#
#  CPU-M
#
#  (c) 2025 TDolphin
#
#  generic makefile for gcc
#
#  for MorphOS (host) (ppc)
#
#    requires: MorphOS SDK
#    requires: AmigaOS C++ wrapper classes (https://github.com/tdolphin-org/AmigaOS.cpp.wrapper)
#    requires: AmigaOS MUI C++ wrapper classes (https://github.com/tdolphin-org/AmigaOS.MUI.cpp.wrapper)
#
#  cross compilation target MorphOS PowerPC, host Linux x86_64 (64-bit)
#
#    requires: MorphOS SDK for cross compilation (https://morph.zone/modules/newbb_plus/viewtopic.php?topic_id=13308&forum=12)
#    requires: AmigaOS C++ wrapper classes (https://github.com/tdolphin-org/AmigaOS.cpp.wrapper)
#    requires: AmigaOS MUI C++ wrapper classes (https://github.com/tdolphin-org/AmigaOS.MUI.cpp.wrapper)
#

# trace/debug flags
DEBUG_FLAGS = #-DTRACE -DTRACE_CUSTOM_COMPONENTS -DTRACE_AMIGAOS

CPP_FLAGS = $(DEBUG_FLAGS) $(MORE_CPP_FLAGS) -Wall\
	-Isrc -I${AOSCPP_PATH}/wrappers/src -I${MUICPP_PATH}/wrappers/src -I${MUICPP_PATH}/components/src
LFLAGS = -L${MUICPP_PATH}/wrappers/lib/$(SUB_BUILD_PATH) -lMUIcpp $(MORE_LFLAGS)

dir_guard = mkdir -p $(@D)

BINPATH = out/$(SUB_BUILD_PATH)

include makefile.gen.version.mk

AOS_WRAPPER_PATH = ${AOSCPP_PATH}/wrappers
AOS_WRAPPER_MODULES = AOS/Exec AOS/Exec AOS/AmigaLib AOS/OpenURL AOS/Graphics AOS/Cybergraphics AOS/Dos AOS/Devices/Timer AOS/Icon Core AOS/Rexxsyslib AOS/PCIX AOS/PCIIDS
AOS_WRAPPER_SRC_DIRS = $(addprefix $(AOS_WRAPPER_PATH)/src/,$(AOS_WRAPPER_MODULES))
AOS_WRAPPER_SRCS = $(foreach sdir,$(AOS_WRAPPER_SRC_DIRS),$(wildcard $(sdir)/*.cpp))
AOS_WRAPPER_CPP_FLAGS_LIGHT = $(CPP_FLAGS)

MUI_COMPONENTS_PATH = ${MUICPP_PATH}/components
MUI_COMPONENTS_MODULES = Components/Core Components/MCC Components/MCC/Core Components/Buttons Components/Tabs
MUI_COMPONENTS_SRC_DIRS = $(addprefix $(MUI_COMPONENTS_PATH)/src/,$(MUI_COMPONENTS_MODULES))
MUI_COMPONENTS_SRCS = $(foreach sdir,$(MUI_COMPONENTS_SRC_DIRS),$(wildcard $(sdir)/*.cpp))

MODULES_COMPONENTS = Components Components/Buttons Components/Core Components/Tabs Components/Tabs/CPU Components/Tabs/Memory Components/Tabs/Expansions \
	Components/Tabs/Graphics Components/Tabs/Boards Components/MCC Components/Windows
MODULES = $(MODULES_COMPONENTS) FileResources TextResources DataInfo

SRC_DIRS = src $(addprefix src/,$(MODULES))
SRCS = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.cpp))
ASM_SRCS = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.s))
OBJS = $(patsubst src/%.cpp,obj/$(SUB_BUILD_PATH)/%.o,$(SRCS))\
	$(patsubst src/%.s,obj/$(SUB_BUILD_PATH)/%.o,$(ASM_SRCS))\
	$(patsubst $(AOS_WRAPPER_PATH)/src/%.cpp,$(AOS_WRAPPER_PATH)/obj/$(SUB_BUILD_PATH)/light/%.o,$(AOS_WRAPPER_SRCS))\
	$(patsubst $(MUI_COMPONENTS_PATH)/src/%.cpp,$(MUI_COMPONENTS_PATH)/obj/$(SUB_BUILD_PATH)/%.o,$(MUI_COMPONENTS_SRCS))

HEADERS = src/ProgDefines.hpp

all: src/Version.cpp src/Version.hpp $(BINPATH)/$(APP_FILE_NAME)

$(BINPATH)/$(APP_FILE_NAME): $(OBJS)
	@echo "## Linking ..."
	$(CPPC) $^ $(LFLAGS) -o $@_nonstripped
	@echo "## Stripping ..."
	$(STRIP) --strip-all $@_nonstripped -o $@
	$(OBJDUMP) --syms --reloc --disassemble-all $@_nonstripped > $@_disassembled
	@echo "## Finished :)"

obj/$(SUB_BUILD_PATH)/%.o: src/%.cpp src/%.hpp $(HEADERS)
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

obj/$(SUB_BUILD_PATH)/%.o: src/%.s
	$(dir_guard)
	$(CC) -c $< -o $@

$(AOS_WRAPPER_PATH)/obj/$(SUB_BUILD_PATH)/light/%.o: $(AOS_WRAPPER_PATH)/src/%.cpp $(AOS_WRAPPER_PATH)/src/%.hpp
	$(dir_guard)
	$(CPPC) $(AOS_WRAPPER_CPP_FLAGS_LIGHT) -c $< -o $@

$(MUI_COMPONENTS_PATH)/obj/$(SUB_BUILD_PATH)/%.o: $(MUI_COMPONENTS_PATH)/src/%.cpp $(MUI_COMPONENTS_PATH)/src/%.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

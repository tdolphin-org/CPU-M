#
#  MakeFile for CPU-M
#
#  (c) 2025 TDolphin
#

include appversion.txt

export APP_DATE = `date +%d.%m.%Y`
export APP_FILE_NAME = CPU-M
export APP_BUILD_COMMIT_HASH = `git rev-parse HEAD`

dir_guard = mkdir -p $@

all:
	@echo "make morphos_ppc"
	@echo "make cross_morphos_ppc"

morphos_ppc: TARGET="MorphOS PPC"
morphos_ppc: CPPC=g++
morphos_ppc: CC=gcc
morphos_ppc: STRIP=strip
morphos_ppc: OBJDUMP=objdump
morphos_ppc: build

cross_morphos_ppc: TARGET="cross MorphOS PPC"
cross_morphos_ppc: CPPC=ppc-morphos-g++
cross_morphos_ppc: CC=ppc-morphos-gcc
cross_morphos_ppc: STRIP=ppc-morphos-strip
cross_morphos_ppc: OBJDUMP=ppc-morphos-objdump
cross_morphos_ppc: build

build: out/morphos/ppc
	@echo "# Build for $(TARGET) ..."
	$(MAKE) -f makefile.generic.gcc.mk SUB_BUILD_PATH=morphos/ppc \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	MUICPP_PATH=../../AmigaOS.MUI.cpp.wrapper \
	CPPC=$(CPPC) CC=$(CC) STRIP=$(STRIP) OBJDUMP=$(OBJDUMP) \
	MORE_CPP_FLAGS="-std=c++17 -Os -noixemul -fno-threadsafe-statics -D_GLIBCXX_HAS_GTHREADS=0" \
	MORE_LFLAGS="-noixemul" \
	all

out/morphos/ppc:
	$(dir_guard)

clean.obj:
	rm -f -R ../../AmigaOS.cpp.wrapper/wrappers/obj/*
	rm -f -R ../../AmigaOS.MUI.cpp.wrapper/components/obj/*
	rm -f -R obj/*

clean: clean.obj
	rm -f -R out/*

rebuild : clean all

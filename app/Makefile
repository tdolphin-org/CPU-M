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

morphos_ppc: out/morphos/ppc
	@echo "# Build App for MorphOS PPC ######################################################################"
	$(MAKE) -f makefile.generic.gcc.mk SUB_BUILD_PATH=morphos/ppc \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	MUICPP_PATH=../../AmigaOS.MUI.cpp.wrapper \
	CPPC=g++ CC=gcc STRIP=strip OBJDUMP=objdump \
	MORE_CPP_FLAGS=-std=c++17,-Os,-noixemul \
	MORE_LFLAGS=-noixemul \
	all

cross_morphos_ppc: out/morphos/ppc
	@echo "# Cross Build for MorphOS PowerPC ################################################################"
	$(MAKE) -f makefile.generic.gcc.mk SUB_BUILD_PATH=morphos/ppc \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	MUICPP_PATH=../../AmigaOS.MUI.cpp.wrapper \
	CPPC=ppc-morphos-g++ CC=ppc-morphos-gcc STRIP=ppc-morphos-strip OBJDUMP=ppc-morphos-objdump \
	MORE_CPP_FLAGS=-std=c++17,-Os,-noixemul \
	MORE_LFLAGS=-noixemul \
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

#
#  Makefile for CPU-M project
#
#  (c) 2025 TDolphin
#

#
# note: for cross compilation requires 'jlha-utils' under linux
#

SUB_PROJECTS = app
APP_DRAWER_NAME = CPU-M

OUT_PATH = out
OUT_APP_PATH = $(OUT_PATH)/$(APP_DRAWER_NAME)

include app/appversion.txt

all:
	@echo "make mos_ppc - MorphOS PowerPC build"
	@echo "make cross_mos_ppc - MorphOS PowerPC build (cross compilation on linux)"
	@echo "make clean.obj - remove all obj files"
	@echo "make clean - remove all obj files and executable files"

mos_ppc: sub_projects_mos_ppc build_out

cross_mos_ppc: sub_projects_cross_mos_ppc build_out

sub_projects_build:
	@echo "------------------------------------------------"
	@date
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) $(BUILD_TARGET) -C $$dir; \
	done
	@date
	@echo "------------------------------------------------"

sub_projects_mos_ppc: BUILD_TARGET=morphos_ppc
sub_projects_mos_ppc: sub_projects_build

sub_projects_cross_mos_ppc: BUILD_TARGET=cross_morphos_ppc
sub_projects_cross_mos_ppc: sub_projects_build

build_out:
	mkdir -p $(OUT_APP_PATH)
	@for dir in $(SUB_PROJECTS); do \
		echo "copy ... " $$dir/out/morphos/ppc/"*" $(OUT_APP_PATH); \
		cp -R $$dir/out/morphos/ppc/* $(OUT_APP_PATH); \
	done
	mkdir -p $(OUT_APP_PATH)/images
	cp -r data/images/* $(OUT_APP_PATH)/images
	cp docs/aminet/header.readme $(OUT_APP_PATH)/CPU-M.readme
	sed -i "s/%VERSION%/$(APP_VERSION)/g" $(OUT_APP_PATH)/CPU-M.readme
	fold -w78 -s docs/CPU-M.readme >> $(OUT_APP_PATH)/CPU-M.readme
#	cp data/icons/CPU-M.drawer.info $(OUT_PATH)/CPU-M.info
#	cp data/icons/CPU-M.info $(OUT_APP_PATH)
#	cp data/icons/CPU-M.readme.info $(OUT_APP_PATH)
	cp LICENSE $(OUT_APP_PATH)
#	cp data/icons/LICENSE.info $(OUT_APP_PATH)
	rm -f $(OUT_APP_PATH)/$(APP_DRAWER_NAME)_*
	cd $(OUT_PATH); lha a $(APP_DRAWER_NAME).lha $(APP_DRAWER_NAME) $(APP_DRAWER_NAME).info

clean.obj:
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) clean.obj -C $$dir; \
	done

clean: clean.obj
	rm -f -R $(OUT_PATH)/*
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) clean -C $$dir; \
	done

rebuild_mos_ppc: clean mos_ppc build_out
rebuild_cross_mos_ppc: clean cross_mos_ppc build_out

check:
	cppcheck --enable=all --inconclusive .

.NOTPARALLEL: build_out
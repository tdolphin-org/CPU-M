# CPU-M — AI Agent Guide

## Project Overview

CPU-M is a **system information tool for MorphOS** (Amiga-like OS for PowerPC). It displays detailed hardware and software info including CPU, mainboard, memory, graphics, PCI/board expansion, and OS details. Developed by TDolphin (Rafal Zabdyr). Serves as a reference example of using [MUI C++ wrappers](https://github.com/tdolphin-org/AmigaOS.MUI.cpp.wrapper) and [AmigaOS C++ wrappers](https://github.com/tdolphin-org/AmigaOS.cpp.wrapper).

## Build System

- **Platform**: MorphOS 3.0+ (PowerPC), cross-compilable from Linux x86_64
- **Toolchain**: GCC, PowerPC target
- **Build commands** (from project root):
  - `make mos_ppc` — native MorphOS build
  - `make cross_mos_ppc` — cross-compile on Linux
  - `make clean` / `make clean.obj`
  - `make check` — run cppcheck
  - `make rebuild_mos_ppc` / `make rebuild_cross_mos_ppc`
- **SDK dependencies**:
  - MorphOS SDK (or cross-compile SDK)
  - `AmigaOS.cpp.wrapper` (set `AOSCPP_PATH`)
  - `AmigaOS.MUI.cpp.wrapper` (set `MUICPP_PATH`)
- **Cross-compilation prerequisites** (see [setup guide below](#cross-compilation-setup)):
  - `ppc-morphos-{g++,gcc,strip,objdump}` toolchain from MorphOS SDK
  - Two wrapper repos cloned as siblings to `CPU-M/`
  - `jlha-utils` for LHA archive creation
- **Build output**: `out/CPU-M/CPU-M` (stripped executable) + LHA archive
- **Compiler flags** (from `app/makefile.generic.gcc.mk`):
  - `cpp` with `-Os -flto -fno-rtti -Wall -D_NO_PPCINLINE`
  - Link: `-lamiga_std_light -lMUIcpp`
  - Trace/debug: `-DTRACE -DTRACE_CUSTOM_COMPONENTS -DTRACE_AMIGAOS`
- **Code style**: WebKit-based (`.clang-format`), tabs=4, indent=4, column limit=140

## Project Structure

```
CPU-M/
├── Makefile                          # top-level build orchestrator
├── app/
│   ├── Makefile                      # app sub-build
│   ├── appversion.txt                # APP_VERSION = x.y.z
│   ├── makefile.generic.gcc.mk       # main build rules
│   ├── makefile.gen.version.mk       # auto-generates Version.hpp/cpp from git hash
│   └── src/
│       ├── Main.cpp                  # entry point, instantiates App singleton
│       ├── App.hpp / App.cpp         # AppCore singleton — opens all system libraries
│       ├── AppContext.hpp / .cpp     # AppContextCore singleton — exposes library bases
│       ├── WindowManager.hpp / .cpp  # WindowManagerCore singleton — manages all windows
│       ├── ProgDefines.hpp           # app constants: name, author, URLs
│       ├── Version.hpp / .cpp        # auto-generated version info
│       ├── Components/               # MUI GUI components
│       │   ├── Application.hpp/.cpp  # root MUI::Application builder
│       │   ├── AppWindow.hpp/.cpp    # main window with tabs + exit button
│       │   ├── Content.hpp/.cpp      # tab container (7 tabs)
│       │   ├── Base.hpp/.cpp         # helper: LabelText(), ValueText()
│       │   ├── IDs.hpp/.cpp          # window AOS::Identifier constants
│       │   ├── Menus/MainMenu.hpp/.cpp
│       │   ├── Buttons/              # GPU, Memory, Bus, ROM, URL buttons
│       │   ├── Tabs/
│       │   │   ├── CPUTab.hpp/.cpp          # CPU info with multi-core cycle
│       │   │   ├── CPU/CPUInfo.hpp/.cpp     # single CPU/core display
│       │   │   ├── MainboardTab.hpp/.cpp    # board vendor, model, ports
│       │   │   ├── MemoryTab.hpp/.cpp       # RAM slots + soldered
│       │   │   ├── Memory/MemorySlotsInfo.hpp/.cpp
│       │   │   ├── Memory/SolderedMemoryInfo.hpp/.cpp
│       │   │   ├── GraphicsTab.hpp/.cpp     # GPU boards list
│       │   │   ├── Graphics/GraphicsBoards.hpp/.cpp
│       │   │   ├── Graphics/GPUName.hpp/.cpp
│       │   │   ├── Graphics/BusInterfaceNames.hpp/.cpp
│       │   │   ├── Graphics/RenderConfig.hpp/.cpp
│       │   │   ├── Graphics/TheoreticalPerformance.hpp/.cpp
│       │   │   ├── BoardsTab.hpp/.cpp       # PCI board list
│       │   │   ├── Boards/BoardsList.hpp/.cpp
│       │   │   ├── Boards/BoardRomSize.hpp/.cpp
│       │   │   ├── OSTab.hpp/.cpp           # OS version, loaded exec nodes
│       │   │   └── AboutTab.hpp/.cpp        # links (homepage, git, email, YouTube)
│       │   └── Windows/
│       │       ├── GPUSpecWindow.hpp/.cpp         # GPU spec detail popup
│       │       ├── MemoryModuleSpecWindow.hpp/.cpp # RAM module detail popup
│       │       ├── BusInterfacesSpecWindow.hpp/.cpp # PCI/AGP/PCIe spec popup
│       │       └── BoardAttributesWindow.hpp/.cpp  # PCI board attributes popup
│       ├── DataInfo/                # hardware specification data
│       │   ├── CPUSpec.hpp/.cpp              # CPU spec map (PPC models)
│       │   ├── GPUSpec.hpp/.cpp              # GPU spec map
│       │   ├── GfxCardSpec.hpp/.cpp          # graphics card spec map
│       │   ├── GfxCardTypes.hpp/.cpp         # GfxCardID enum (~200 entries)
│       │   ├── GPUTypes.hpp/.cpp             # GPUID, GPUVariantID, ManufacturerID, ArchitectureID enums
│       │   ├── MemorySpec.hpp/.cpp           # memory type/module spec maps
│       │   ├── MemoryTypes.hpp/.cpp          # MemoryGeneration, ModuleForm, MemoryType enums
│       │   ├── TechnologyTypes.hpp/.cpp      # TechnologyID enum (nm process nodes)
│       │   ├── BoardInfo.hpp                 # BoardInfo struct (vendor/device/class)
│       │   ├── HardwareSystemSpec.hpp/.cpp   # system motherboard database + lookup
│       │   └── PCI2IDSpec.hpp/.cpp           # PCI vendor/device -> GfxCardID mapping
│       ├── FileResources/           # image and CSV file path constants
│       │   ├── CPUImages.hpp/.cpp
│       │   ├── ManufacturerImages.hpp/.cpp
│       │   ├── VendorImages.hpp/.cpp
│       │   ├── MemoryModuleImages.hpp/.cpp
│       │   └── Specs.hpp/.cpp
│       ├── TextResources/Labels.hpp/.cpp  # all UI string constants
│       └── Events/AppEventType.hpp        # menu event IDs
├── data/
│   ├── images/              # PNG icons (CPU, vendors, manufacturers, memory)
│   └── specs/pciid_graphics_cards.csv  # PCI ID -> graphics card lookup
├── docs/
│   ├── CPU-M.readme         # distribution readme
│   ├── header.readme        # readme header template
│   └── OldInterface.md      # screenshots of old versions
├── out/CPU-M/               # build output directory
└── .clang-format            # code formatting config
```

## Architecture

### Singleton Pattern

Three core singletons (via `td::Singleton<T>`):
1. **`App`** (`AppCore`) — owns all library base scopes (MUI, OpenURL, Cybergraphics, Graphics, Rexxsyslib, PCIX, PCIIDS, Intuition, ASL), runs the main event loop.
2. **`AppContext`** (`AppContextCore`) — provides access to library bases from components.
3. **`WindowManager`** (`WindowManagerCore`) — owns all secondary windows (GPUSpec, MemoryModuleSpec, BusInterfacesSpec, BoardAttributes).

### Component Hierarchy (MUI)

```
App (MUI::Application)
 └── AppWindow (MUI::Window)
      ├── Content (MUI::Group / tabs container)
      │    ├── CPUTab (CPU info + multi-core selector)
      │    ├── MainboardTab (system/motherboard info)
      │    ├── MemoryTab (RAM slots + soldered)
      │    ├── GraphicsTab (GPU boards)
      │    ├── BoardsTab (PCI/board list)
      │    ├── OSTab (OS version + exec nodes)
      │    └── AboutTab (URL buttons)
      ├── Status bar (app name + version)
      └── Exit button
```

### MUI Custom Classes (MCC)

The project uses custom MCC components (ActionCycle, ActionList) from the MUI C++ wrapper components library. These are registered via `MUI::CustomClassesLifeTimeScope` and disposed on app exit.

### Event Flow

1. MUI notifiers connect UI actions to application logic
2. Menu actions use `AppEventType` enum (values >= 1000)
3. Buttons/double-clicks open detail windows via `WindowManager` singleton
4. `GPUName` components use `GPUSpecButton` to open `GPUSpecWindow`
5. `MemorySlotsInfo` uses `MemoryModuleSpecButton` to open `MemoryModuleSpecWindow`
6. `BoardsList` double-click opens `BoardAttributesWindow` (populated from PCIX library)
7. `GoUrlButton` opens URLs via OpenURL library

## Key Conventions

- **Namespaces**: `Components` (GUI), `DataInfo` (specs), `AOS` (AmigaOS wrappers), `MUI` (MUI wrappers)
- **Naming**: `m` prefix for member variables, PascalCase for classes, SCREAMING_SNAKE for constants
- **Headers**: `#pragma once`, copyright header `// CPU-M\n//\n// (c) 2025 TDolphin\n`
- **Classes**: inherit from `Root<MUI::*>` with `mComponent` as the MUI object; `muiRoot()` returns it
- **Base class** `Components::Base` provides `LabelText()` and `ValueText()` helpers
- **Copyright lines**: always include `(c) 2025(-2026) TDolphin`
- **Trace logging**: guarded by `#ifdef TRACE`, uses `std::cout << __PRETTY_FUNCTION__`
- **Version auto-generation**: `Version.hpp` and `Version.cpp` are regenerated each build from `app/appversion.txt` + git commit hash

## Data Files

- `data/specs/pciid_graphics_cards.csv` — PCI vendor/device -> graphics card CSV database
- `data/images/` — PNG icons organized by category (cpu/, vendors/, manufacturers/, memory/)

## Cross-Compilation Setup

To cross-compile CPU-M from Linux x86_64 to MorphOS PowerPC:

1. **MorphOS SDK** — download the cross-compilation SDK from [morph.zone](https://morph.zone/modules/newbb_plus/viewtopic.php?topic_id=13308&forum=12). It provides the `ppc-morphos-*` toolchain (g++, gcc, strip, objdump). Ensure these are in `$PATH`.

2. **Wrapper repositories** — clone both as siblings to `CPU-M/`:
   ```
   git clone https://github.com/tdolphin-org/AmigaOS.cpp.wrapper
   git clone https://github.com/tdolphin-org/AmigaOS.MUI.cpp.wrapper
   ```
   The build system expects `../../AmigaOS.cpp.wrapper` and `../../AmigaOS.MUI.cpp.wrapper` relative to `app/` (or set `AOSCPP_PATH` / `MUICPP_PATH` in `makefile.generic.gcc.mk`).

3. **LHA archiver** (optional, for .lha packaging):
   ```
   sudo apt install jlha-utils
   ```

4. **Build**:
   ```
   make cross_mos_ppc
   ```
   The stripped executable appears at `out/CPU-M/CPU-M`.

## Testing

No test framework found. Run `cppcheck` with `make check` (requires wrapper repos as siblings, see [cross-compilation setup](#cross-compilation-setup)).

## Important Notes

- The project targets **MorphOS PowerPC**, not standard Linux/Windows
- Libraries are opened at app startup via RAII scopes and closed on destructor
- All MUI objects are built with builder pattern (e.g., `MUI::WindowBuilder()`)
- String resources are centralized in `TextResources/Labels.hpp`
- The `.gitignore` excludes `obj/*`, `out/*`, `app/out/*`, `Version.hpp`, `Version.cpp`
- The `Version.*` files are auto-generated by `makefile.gen.version.mk` and should never be hand-edited

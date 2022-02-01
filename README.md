# gotobed-ae

## Dependencies
- [CommonLibSSE](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE)
- [Detours](https://github.com/microsoft/Detours)
- [JContainers](https://github.com/ryobg/JContainers)

## Building
Prerequisites:
- Visual Studio 2019
- [vcpkg](https://github.com/microsoft/vcpkg) (for CommonLibSSE)

Open x64 Native Tools Command Prompt for VS 2019.

Clone repository:
```
git clone https://github.com/andrelo1/gotobed-ae
```
Clone submodules:
```
cd gotobed-ae
git submodule update --init
```
Build CommonLibSSE:
```
cd CommonLibSSE
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows-static-md
cmake --build build --config Release
```
Build Detours:
```
cd ../Detours/src
nmake
```
Open `gotobed.sln` in Visual Studio and build solution.

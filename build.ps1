#!/usr/bin/env pwsh

#Remove-Item build -Force -Recurse -ErrorAction SilentlyContinue
New-Item -Path .\build -ItemType directory -Force
Set-Location build

cmake -G "Ninja" "-DCMAKE_TOOLCHAIN_FILE=$env:VCPKG_ROOT\scripts\buildsystems\vcpkg.cmake" "-DVCPKG_TARGET_TRIPLET=$env:VCPKG_DEFAULT_TRIPLET" ..
cmake --build .

Set-Location ..

@echo off
setlocal enabledelayedexpansion

set files=
set count=0

for %%f in (src\*.cpp) do (
    set /a count+=1
    echo !count!. %%~nxf
    set files[!count!]=%%~nf
)

if %count%==0 (
    echo No .cpp files found in src/
    pause
    exit
)

set /p choix="Choose file number (1-%count%): >>> "

if !choix! lss 1 (
    echo Invalid choice. Use a number between 1 and %count%.
    pause
    exit
)

if !choix! gtr %count% (
    echo Invalid choice. Use a number between 1 and %count%.
    pause
    exit
)

set filename=!files[%choix%]!

g++ src\%filename%.cpp -g -o build\%filename%_build.exe -lSDL3 -Iheader -Llib -Iinclude -Iinclude\engine

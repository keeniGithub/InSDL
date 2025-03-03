@echo off

echo Choose file:
echo 1. test.cpp
echo 2. main.cpp

set /p choix=">>> "

if %choix%==1 (
    set filename=test
) else if %choix%==2 (
    set filename=main
) else (
    echo Use 1 || 2
    pause
    exit
)

g++ src/%filename%.cpp -g -o build/%filename%_build.exe -lSDL3 -Iheader -Llib -Iinclude -Iinclude/engine

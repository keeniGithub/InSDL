@echo off

set /p folder_name="Project name: "

set /p add_vsc="add .vscode folder? (y/n): "

if /i "%add_vsc%"=="y" (
    set vsc_flag=-vsc
) else (
    set vsc_flag=
)

python main.py create "%folder_name%" %vsc_flag%

pause
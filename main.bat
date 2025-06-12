@echo off
chcp 65001

:: Change to src directory
cd src

:: Compile and output to bin\main.exe
gcc -o ..\bin\main.exe main.c romaji_converter.c hash_table.c

:: Go back and into bin directory
cd ..
cd bin

:: Run the executable
main.exe

pause

@echo off


gcc main.c -o main -lopengl32 -lglu32 -I"%~dp0/include" -L"%~dp0/lib" -lglut32
pause

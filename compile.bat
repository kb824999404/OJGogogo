@echo off
set f=%1
echo Compiling %f%.cpp ...
if "%2"=="" (g++ %f%.cpp -std=c++11 -W -o %f%.exe)^
 else (g++ %f%.cpp -std=c++11 -W %2 -o %f%.exe)
echo Done.
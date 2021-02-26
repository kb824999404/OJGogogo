@echo off
set f=%1
echo Compiling %f%.cpp ...
g++ %f%.cpp -std=c++11 -W -o %f%.exe
echo Done.
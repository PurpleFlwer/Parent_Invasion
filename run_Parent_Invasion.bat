@echo off
cd /d "%~dp0"
g++ main.cpp WebsiteMonitor.cpp -o monitor
monitor
pause

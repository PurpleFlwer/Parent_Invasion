@echo off
cd /d "%USERPROFILE%\OneDrive\Desktop\SafeSurfer_Project"
g++ main.cpp WebsiteMonitor.cpp -o monitor
monitor
pause

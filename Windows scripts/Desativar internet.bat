@echo off
cls
@echo off
ipconfig /release + vbnewlineif %ERRORLEVEL%==1 ipconfig /release_all

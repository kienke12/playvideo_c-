@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\qt5-build\qtbase\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\qt5-build\qtbase\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\qt5-build\qtbase\plugins
)
D:\qt5-build\qtbase\bin\uic.exe %*
EndLocal

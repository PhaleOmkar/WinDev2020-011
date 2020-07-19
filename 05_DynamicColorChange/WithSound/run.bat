cls

cl.exe /c /EHsc BlueScreenWithFullScreenFeatures.cpp

rc.exe BlueScreenWithFullScreenFeatures.rc

link.exe BlueScreenWithFullScreenFeatures.obj BlueScreenWithFullScreenFeatures.res gdi32.lib user32.lib /SUBSYSTEM:WINDOWS

BlueScreenWithFullScreenFeatures.exe
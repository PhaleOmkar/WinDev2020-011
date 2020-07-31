cls

cl.exe SplashScreen.cpp /c /EHsc

rc.exe SplashScreen.rc

link.exe SplashScreen.obj SplashScreen.res gdi32.lib user32.lib /SUBSYSTEM:WINDOWS

SplashScreen.exe
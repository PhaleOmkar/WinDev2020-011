-----------------------------------------
# WinDev2020
Repository by WinDev2020-011 Omkar Phale
-----------------------------------------
    Folder PATH listing for volume New Volume
    Volume serial number is B47D-203F
    E:.
    |   .gitignore
    |   README.md
    |   
    +---00_FirstWindow
    |       FirstWindow.cpp
    |       FirstWindow.JPG
    |       
    +---01_FirstWindowWithMessageBox
    |       FirstWindowWithMessageBox.cpp
    |       WM_CREATE_MessageBox.JPG
    |       WM_KEYDOWN_MessageBox.JPG
    |       WM_LBUTTONDOWN_MessageBox.JPG
    |       WM_RBUTTONDOWN_MessageBox.JPG
    |       
    +---02_MultiColorWM_PAINT
    |   +---DynamicMultiColorWM_PAINT
    |   |       DynamicMultiColorWM_PAINT.cpp
    |   |       DynamicMultiColorWM_PAINT.JPG
    |   |       
    |   \---StaticMultiColorWM_PAINT
    |       +---01_StaticMultiColorWM_PAINT
    |       |       StaticMultiColorWM_PAINT.cpp
    |       |       StaticMultiColorWM_PAINT.JPG
    |       |       
    |       \---02_StaticMultiColorWM_PAINT
    |               StaticMultiColorWM_PAINT.cpp
    |               StaticMultiColorWM_PAINT.JPG
    |               
    +---04_WindowWithResources
    |   \---01_WindowWithIcon
    |       +---WithCustomICO
    |       |       default_large_icon.ico
    |       |       default_small_icon.ico
    |       |       WindowWithIcon.cpp
    |       |       WindowWithIcon.h
    |       |       WindowWithIcon.JPG
    |       |       WindowWithIcon.rc
    |       |       
    |       \---WithWindowsICO
    |               default_large_icon.ico
    |               WindowWithIcon.cpp
    |               WindowWithIcon.h
    |               WindowWithIcon.rc
    |               
    +---05_DynamicColorChange
    |   +---WithoutSound
    |   |       default_large_icon.ico
    |   |       DynamiceColorChange.cpp
    |   |       DynamiceColorChange.h
    |   |       DynamiceColorChange.rc
    |   |       
    |   \---WithSound
    |           BlueScreenWithFullScreenFeatures.cpp
    |           BlueScreenWithFullScreenFeatures.h
    |           BlueScreenWithFullScreenFeatures.rc
    |           default_large_icon.ico
    |           run.bat
    |           sample.wav
    |           sample_long.wav
    |           
    +---06_EnumWindows
    |       default_large_icon.ico
    |       EnumWindowImplementation.cpp
    |       EnumWindowImplementation.h
    |       EnumWindowImplementation.rc
    |       
    +---07_MultiThreading
    |   +---01_UsingWin32API
    |   |       MultiThreading.cpp
    |   |       
    |   \---02_UsingStandardAPI
    |           MultiThreading.cpp
    |           
    +---08_SplashScreen
    |       GithubSplashScreen.cpp
    |       moon.bmp
    |       originalmoon.bmp
    |       run.bat
    |       SplashScreen.cpp
    |       SplashScreen.h
    |       SplashScreen.rc
    |       
    \---09_DLL_Linking
        +---01_Client
        |   +---01_ImplicitLinking
        |   |   +---01_IDE_Based
        |   |   |   |   FirstWindow.cpp
        |   |   |   |   Implicit_DLL_Linking.sln
        |   |   |   |   Implicit_DLL_Linking.vcxproj
        |   |   |   |   Implicit_DLL_Linking.vcxproj.filters
        |   |   |   |   Implicit_DLL_Linking.vcxproj.user
        |   |   |   |   MyMath.h
        |   |   |   |   MyMath.lib
        |   |   |   |   
        |   |   |   \---Debug
        |   |   |       |   Implicit_DLL_Linking.Build.CppClean.log
        |   |   |       |   Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
        |   |   |       |   Implicit_DLL_Linking.log
        |   |   |       |   Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
        |   |   |       |   MyMath.dll
        |   |   |       |   
        |   |   |       \---Implicit.c799ed44.tlog
        |   |   \---02_CMD_Based
        |   |           FirstWindow.cpp
        |   |           MyMath.dll
        |   |           MyMath.h
        |   |           MyMath.lib
        |   |           
        |   \---02_ExplicitLinking
        |       +---01_IDE_Based
        |       |   |   FirstWindow.cpp
        |       |   |   Implicit_DLL_Linking.sln
        |       |   |   Implicit_DLL_Linking.vcxproj
        |       |   |   Implicit_DLL_Linking.vcxproj.filters
        |       |   |   Implicit_DLL_Linking.vcxproj.user
        |       |   |   
        |       |   \---Debug
        |       |       |   08_MyMathdll
        |       |       |   Explicit_DLL_Linking.Build.CppClean.log
        |       |       |   Implicit_DLL_Linking.Build.CppClean.log
        |       |       |   Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
        |       |       |   Implicit_DLL_Linking.log
        |       |       |   Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
        |       |       |   
        |       |       +---Explicit.c799ed44.tlog
        |       |       \---Implicit.c799ed44.tlog
        |       \---02_CMD_Based
        |               08_MyMathdll
        |               FirstWindow.cpp
        |               
        \---02_Server
            |   README.md
            |   
            +---01_declspec
            |   +---01_IDE_Based
            |   |   |   01_IDE_Based.sln
            |   |   |   01_IDE_Based.vcxproj
            |   |   |   01_IDE_Based.vcxproj.filters
            |   |   |   01_IDE_Based.vcxproj.user
            |   |   |   MyMath.cpp
            |   |   |   MyMath.h
            |   |   |   
            |   |   \---Debug
            |   |       |   01_IDE_Based.Build.CppClean.log
            |   |       |   01_IDE_Based.log
            |   |       |   01_IDE_Based.vcxproj.FileListAbsolute.txt
            |   |       |   
            |   |       \---01_IDE_Based.tlog
            |   \---02_CMD_Based
            |           MyMath.cpp
            |           MyMath.h
            |           
            \---02_def
                +---00_Testing
                |   \---01_Client
                |       +---01_ImplicitLinking
                |       |   +---01_IDE_Based
                |       |   |   |   FirstWindow.cpp
                |       |   |   |   Implicit_DLL_Linking.sln
                |       |   |   |   Implicit_DLL_Linking.vcxproj
                |       |   |   |   Implicit_DLL_Linking.vcxproj.filters
                |       |   |   |   Implicit_DLL_Linking.vcxproj.user
                |       |   |   |   MyMath.h
                |       |   |   |   MyMath.lib
                |       |   |   |   
                |       |   |   \---Debug
                |       |   |       |   Implicit_DLL_Linking.Build.CppClean.log
                |       |   |       |   Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
                |       |   |       |   Implicit_DLL_Linking.log
                |       |   |       |   Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
                |       |   |       |   MyMath.dll
                |       |   |       |   
                |       |   |       \---Implicit.c799ed44.tlog
                |       |   \---02_CMD_Based
                |       |           FirstWindow.cpp
                |       |           MyMath.dll
                |       |           MyMath.h
                |       |           MyMath.lib
                |       |           
                |       \---02_ExplicitLinking
                |           +---01_IDE_Based
                |           |   |   FirstWindow.cpp
                |           |   |   Implicit_DLL_Linking.sln
                |           |   |   Implicit_DLL_Linking.vcxproj
                |           |   |   Implicit_DLL_Linking.vcxproj.filters
                |           |   |   Implicit_DLL_Linking.vcxproj.user
                |           |   |   
                |           |   \---Debug
                |           |       |   08_MyMathdll
                |           |       |   Explicit_DLL_Linking.Build.CppClean.log
                |           |       |   Implicit_DLL_Linking.Build.CppClean.log
                |           |       |   Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
                |           |       |   Implicit_DLL_Linking.log
                |           |       |   Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
                |           |       |   
                |           |       +---Explicit.c799ed44.tlog
                |           |       \---Implicit.c799ed44.tlog
                |           \---02_CMD_Based
                |                   08_MyMathdll
                |                   FirstWindow.cpp
                |                   
                +---01_IDE_Based
                |   |   01_IDE_Based.sln
                |   |   01_IDE_Based.vcxproj
                |   |   01_IDE_Based.vcxproj.filters
                |   |   01_IDE_Based.vcxproj.user
                |   |   Implicit_DLL_Linking.sln
                |   |   Implicit_DLL_Linking.vcxproj
                |   |   Implicit_DLL_Linking.vcxproj.filters
                |   |   Implicit_DLL_Linking.vcxproj.user
                |   |   MyMath.cpp
                |   |   MyMath.def
                |   |   MyMath.h
                |   |   
                |   \---Debug
                |       |   01_IDE_Based.Build.CppClean.log
                |       |   01_IDE_Based.log
                |       |   01_IDE_Based.vcxproj.FileListAbsolute.txt
                |       |   Implicit_DLL_Linking.Build.CppClean.log
                |       |   Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
                |       |   Implicit_DLL_Linking.log
                |       |   Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
                |       |   
                |       +---01_IDE_Based.tlog
                |       \---Implicit.c799ed44.tlog
                \---02_CMD_Based
                        MyMath.cpp
                        MyMath.def
                        MyMath.h

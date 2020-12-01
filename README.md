-----------------------------------------
# WinDev2020
Repository by WinDev2020-011 Omkar Phale
-----------------------------------------
	Folder PATH listing for volume WinDev2020
	Volume serial number is B661-A336
	D:.
	|   .gitignore
	|   README.md
	|   temp.txt
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
	+---09_DLL_Linking
	|   +---01_Client
	|   |   +---01_ImplicitLinking
	|   |   |   +---01_IDE_Based
	|   |   |   |   |   FirstWindow.cpp
	|   |   |   |   |   Implicit_DLL_Linking.sln
	|   |   |   |   |   Implicit_DLL_Linking.vcxproj
	|   |   |   |   |   Implicit_DLL_Linking.vcxproj.filters
	|   |   |   |   |   Implicit_DLL_Linking.vcxproj.user
	|   |   |   |   |   MyMath.h
	|   |   |   |   |   MyMath.lib
	|   |   |   |   |   
	|   |   |   |   +---.vs
	|   |   |   |   |   \---Implicit_DLL_Linking
	|   |   |   |   |       \---v16
	|   |   |   |   |           |   .suo
	|   |   |   |   |           |   Browse.VC.db
	|   |   |   |   |           |   
	|   |   |   |   |           \---ipch
	|   |   |   |   |               \---AutoPCH
	|   |   |   |   |                   +---56a3d6f7bfb8eddc
	|   |   |   |   |                   |       FIRSTWINDOW.ipch
	|   |   |   |   |                   |       
	|   |   |   |   |                   +---a6e66785d267ed55
	|   |   |   |   |                   |       FIRSTWINDOW.ipch
	|   |   |   |   |                   |       
	|   |   |   |   |                   \---a940efdfdcfe82ad
	|   |   |   |   |                           FIRSTWINDOW.ipch
	|   |   |   |   |                           
	|   |   |   |   \---Debug
	|   |   |   |           Implicit_DLL_Linking.Build.CppClean.log
	|   |   |   |           Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
	|   |   |   |           Implicit_DLL_Linking.log
	|   |   |   |           Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
	|   |   |   |           MyMath.dll
	|   |   |   |           
	|   |   |   \---02_CMD_Based
	|   |   |           FirstWindow.cpp
	|   |   |           MyMath.dll
	|   |   |           MyMath.h
	|   |   |           MyMath.lib
	|   |   |           
	|   |   \---02_ExplicitLinking
	|   |       +---01_IDE_Based
	|   |       |   |   FirstWindow.cpp
	|   |       |   |   Implicit_DLL_Linking.sln
	|   |       |   |   Implicit_DLL_Linking.vcxproj
	|   |       |   |   Implicit_DLL_Linking.vcxproj.filters
	|   |       |   |   Implicit_DLL_Linking.vcxproj.user
	|   |       |   |   
	|   |       |   +---.vs
	|   |       |   |   \---Implicit_DLL_Linking
	|   |       |   |       \---v16
	|   |       |   |           |   .suo
	|   |       |   |           |   Browse.VC.db
	|   |       |   |           |   
	|   |       |   |           \---ipch
	|   |       |   |               \---AutoPCH
	|   |       |   |                   +---a940efdfdcfe82ad
	|   |       |   |                   |       FIRSTWINDOW.ipch
	|   |       |   |                   |       
	|   |       |   |                   \---fe098e130ef0b66d
	|   |       |   |                           FIRSTWINDOW.ipch
	|   |       |   |                           
	|   |       |   \---Debug
	|   |       |           08_MyMathdll
	|   |       |           Explicit_DLL_Linking.Build.CppClean.log
	|   |       |           Implicit_DLL_Linking.Build.CppClean.log
	|   |       |           Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
	|   |       |           Implicit_DLL_Linking.log
	|   |       |           Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
	|   |       |           
	|   |       \---02_CMD_Based
	|   |               08_MyMathdll
	|   |               FirstWindow.cpp
	|   |               
	|   \---02_Server
	|       |   README.md
	|       |   
	|       +---01_declspec
	|       |   +---01_IDE_Based
	|       |   |   |   01_IDE_Based.sln
	|       |   |   |   01_IDE_Based.vcxproj
	|       |   |   |   01_IDE_Based.vcxproj.filters
	|       |   |   |   01_IDE_Based.vcxproj.user
	|       |   |   |   MyMath.cpp
	|       |   |   |   MyMath.h
	|       |   |   |   
	|       |   |   +---.vs
	|       |   |   |   \---01_IDE_Based
	|       |   |   |       \---v16
	|       |   |   |           |   .suo
	|       |   |   |           |   Browse.VC.db
	|       |   |   |           |   
	|       |   |   |           \---ipch
	|       |   |   |               \---AutoPCH
	|       |   |   |                   \---2e66cd1e0fb86032
	|       |   |   |                           MYMATH.ipch
	|       |   |   |                           
	|       |   |   \---Debug
	|       |   |           01_IDE_Based.Build.CppClean.log
	|       |   |           01_IDE_Based.log
	|       |   |           01_IDE_Based.vcxproj.FileListAbsolute.txt
	|       |   |           
	|       |   \---02_CMD_Based
	|       |           MyMath.cpp
	|       |           MyMath.h
	|       |           
	|       \---02_def
	|           +---00_Testing
	|           |   \---01_Client
	|           |       +---01_ImplicitLinking
	|           |       |   +---01_IDE_Based
	|           |       |   |   |   FirstWindow.cpp
	|           |       |   |   |   Implicit_DLL_Linking.sln
	|           |       |   |   |   Implicit_DLL_Linking.vcxproj
	|           |       |   |   |   Implicit_DLL_Linking.vcxproj.filters
	|           |       |   |   |   Implicit_DLL_Linking.vcxproj.user
	|           |       |   |   |   MyMath.h
	|           |       |   |   |   MyMath.lib
	|           |       |   |   |   
	|           |       |   |   +---.vs
	|           |       |   |   |   \---Implicit_DLL_Linking
	|           |       |   |   |       \---v16
	|           |       |   |   |           |   .suo
	|           |       |   |   |           |   Browse.VC.db
	|           |       |   |   |           |   
	|           |       |   |   |           \---ipch
	|           |       |   |   |               \---AutoPCH
	|           |       |   |   |                   +---56a3d6f7bfb8eddc
	|           |       |   |   |                   |       FIRSTWINDOW.ipch
	|           |       |   |   |                   |       
	|           |       |   |   |                   +---8499970634064835
	|           |       |   |   |                   |       FIRSTWINDOW.ipch
	|           |       |   |   |                   |       
	|           |       |   |   |                   +---a6e66785d267ed55
	|           |       |   |   |                   |       FIRSTWINDOW.ipch
	|           |       |   |   |                   |       
	|           |       |   |   |                   \---a940efdfdcfe82ad
	|           |       |   |   |                           FIRSTWINDOW.ipch
	|           |       |   |   |                           
	|           |       |   |   \---Debug
	|           |       |   |           Implicit_DLL_Linking.Build.CppClean.log
	|           |       |   |           Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
	|           |       |   |           Implicit_DLL_Linking.log
	|           |       |   |           Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
	|           |       |   |           MyMath.dll
	|           |       |   |           
	|           |       |   \---02_CMD_Based
	|           |       |           FirstWindow.cpp
	|           |       |           MyMath.dll
	|           |       |           MyMath.h
	|           |       |           MyMath.lib
	|           |       |           
	|           |       \---02_ExplicitLinking
	|           |           +---01_IDE_Based
	|           |           |   |   FirstWindow.cpp
	|           |           |   |   Implicit_DLL_Linking.sln
	|           |           |   |   Implicit_DLL_Linking.vcxproj
	|           |           |   |   Implicit_DLL_Linking.vcxproj.filters
	|           |           |   |   Implicit_DLL_Linking.vcxproj.user
	|           |           |   |   
	|           |           |   +---.vs
	|           |           |   |   \---Implicit_DLL_Linking
	|           |           |   |       \---v16
	|           |           |   |           |   .suo
	|           |           |   |           |   Browse.VC.db
	|           |           |   |           |   
	|           |           |   |           \---ipch
	|           |           |   |               \---AutoPCH
	|           |           |   |                   +---a940efdfdcfe82ad
	|           |           |   |                   |       FIRSTWINDOW.ipch
	|           |           |   |                   |       
	|           |           |   |                   \---fe098e130ef0b66d
	|           |           |   |                           FIRSTWINDOW.ipch
	|           |           |   |                           
	|           |           |   \---Debug
	|           |           |           08_MyMathdll
	|           |           |           Explicit_DLL_Linking.Build.CppClean.log
	|           |           |           Implicit_DLL_Linking.Build.CppClean.log
	|           |           |           Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
	|           |           |           Implicit_DLL_Linking.log
	|           |           |           Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
	|           |           |           
	|           |           \---02_CMD_Based
	|           |                   08_MyMathdll
	|           |                   FirstWindow.cpp
	|           |                   
	|           +---01_IDE_Based
	|           |   |   01_IDE_Based.sln
	|           |   |   01_IDE_Based.vcxproj
	|           |   |   01_IDE_Based.vcxproj.filters
	|           |   |   01_IDE_Based.vcxproj.user
	|           |   |   Implicit_DLL_Linking.sln
	|           |   |   Implicit_DLL_Linking.vcxproj
	|           |   |   Implicit_DLL_Linking.vcxproj.filters
	|           |   |   Implicit_DLL_Linking.vcxproj.user
	|           |   |   MyMath.cpp
	|           |   |   MyMath.def
	|           |   |   MyMath.h
	|           |   |   
	|           |   +---.vs
	|           |   |   +---01_IDE_Based
	|           |   |   |   \---v16
	|           |   |   |       |   .suo
	|           |   |   |       |   Browse.VC.db
	|           |   |   |       |   
	|           |   |   |       \---ipch
	|           |   |   |           \---AutoPCH
	|           |   |   |               +---2e66cd1e0fb86032
	|           |   |   |               |       MYMATH.ipch
	|           |   |   |               |       
	|           |   |   |               +---350cd230dd9d9a3c
	|           |   |   |               |       MYMATH.ipch
	|           |   |   |               |       
	|           |   |   |               +---d81bb61cdc34a415
	|           |   |   |               |       FIRSTWINDOW.ipch
	|           |   |   |               |       
	|           |   |   |               +---df8d2c63721fc227
	|           |   |   |               |       FIRSTWINDOW.ipch
	|           |   |   |               |       
	|           |   |   |               \---fbb01426d651dfa8
	|           |   |   |                       FIRSTWINDOW.ipch
	|           |   |   |                       
	|           |   |   \---Implicit_DLL_Linking
	|           |   |       \---v16
	|           |   |           |   .suo
	|           |   |           |   Browse.VC.db
	|           |   |           |   
	|           |   |           \---ipch
	|           |   |               \---AutoPCH
	|           |   |                   +---3c8410b4ee4f71d9
	|           |   |                   |       FIRSTWINDOW.ipch
	|           |   |                   |       
	|           |   |                   +---56a3d6f7bfb8eddc
	|           |   |                   |       FIRSTWINDOW.ipch
	|           |   |                   |       
	|           |   |                   +---a6e66785d267ed55
	|           |   |                   |       FIRSTWINDOW.ipch
	|           |   |                   |       
	|           |   |                   \---a940efdfdcfe82ad
	|           |   |                           FIRSTWINDOW.ipch
	|           |   |                           
	|           |   \---Debug
	|           |           01_IDE_Based.Build.CppClean.log
	|           |           01_IDE_Based.log
	|           |           01_IDE_Based.vcxproj.FileListAbsolute.txt
	|           |           Implicit_DLL_Linking.Build.CppClean.log
	|           |           Implicit_DLL_Linking.exe.lastcodeanalysissucceeded
	|           |           Implicit_DLL_Linking.log
	|           |           Implicit_DLL_Linking.vcxproj.FileListAbsolute.txt
	|           |           
	|           \---02_CMD_Based
	|                   MyMath.cpp
	|                   MyMath.def
	|                   MyMath.h
	|                   
	\---10_COM_Programs
		+---01_ClassFactory
		|   +---01_ClassFactoryDllServerWithRegFile
		|   |       ClassFactoryDllServerWithRegFile.cpp
		|   |       ClassFactoryDllServerWithRegFile.def
		|   |       ClassFactoryDllServerWithRegFile.dll
		|   |       ClassFactoryDllServerWithRegFile.h
		|   |       ClassFactoryDllServerWithRegFile.lib
		|   |       
		|   \---02_ClientOfClassFactoryDllServerWithRegFile
		|       +---01_CPP_Client
		|       |       ClassFactoryDllServerWithRegFile.h
		|       |       ClassFactoryDllServerWithRegFile.reg
		|       |       ClientOfClassFactoryDllServerWithRegFile.cpp
		|       |       ClientOfClassFactoryDllServerWithRegFile.exe
		|       |       run.bat
		|       |       
		|       \---02_C_Client
		|               ClassFactoryDllServerWithRegFile.h
		|               ClassFactoryDllServerWithRegFile.reg
		|               ClientOfClassFactoryDllServerWithRegFile.c
		|               ClientOfClassFactoryDllServerWithRegFile.exe
		|               run.bat
		|               
		+---02_Containment
		|   |   Containment_Readme.pdf
		|   |   
		|   +---ClientOfContainmentComponentWithRegFile
		|   |       ClientOfContainmentComponentWithRegFile-CPP.pdf
		|   |       ClientOfContainmentComponentWithRegFile.cpp
		|   |       ClientOfContainmentComponentWithRegFile.h
		|   |       ContainmentOuterComponent-REG.pdf
		|   |       HeaderForClientOfContainmentComponentWithRegFile.pdf
		|   |       
		|   +---ContainmentInnerComponentWithRegFile
		|   |       ContainmentInnerComponentWithRegFile-CPP.pdf
		|   |       ContainmentInnerComponentWithRegFile-DEF.pdf
		|   |       ContainmentInnerComponentWithRegFile-HEADER.pdf
		|   |       ContainmentInnerComponentWithRegFile.cpp
		|   |       ContainmentInnerComponentWithRegFile.def
		|   |       ContainmentInnerComponentWithRegFile.h
		|   |       
		|   \---ContainmentOuterComponentWithRegFile
		|           ClientOfContainmentComponentWithRegFile.h
		|           ContainmentInnerComponentWithRegFile-HEADER.pdf
		|           ContainmentInnerComponentWithRegFile.h
		|           ContainmentOuterComponent-REG.pdf
		|           ContainmentOuterComponentWithRegFile-CPP.pdf
		|           ContainmentOuterComponentWithRegFile-DEF.pdf
		|           ContainmentOuterComponentWithRegFile-HEADER.pdf
		|           ContainmentOuterComponentWithRegFile.cpp
		|           ContainmentOuterComponentWithRegFile.def
		|           ContainmentOuterComponentWithRegFile.h
		|           HeaderForClientOfContainmentComponentWithRegFile.pdf
		|           
		+---03_Aggregation
		|   |   Aggregation_Readme.pdf
		|   |   
		|   +---AggregationInnerComponentWithRegFile
		|   |       AggregationInnerComponentWithRegFile-CPP.pdf
		|   |       AggregationInnerComponentWithRegFile-DEF.pdf
		|   |       AggregationInnerComponentWithRegFile-HEADER.pdf
		|   |       AggregationInnerComponentWithRegFile.cpp
		|   |       AggregationInnerComponentWithRegFile.def
		|   |       AggregationInnerComponentWithRegFile.h
		|   |       
		|   +---AggregationOuterComponentWithRegFile
		|   |       AggregationInnerComponentWithRegFile-HEADER.pdf
		|   |       AggregationOuterComponent-REG.pdf
		|   |       AggregationOuterComponentWithRegFile-CPP.pdf
		|   |       AggregationOuterComponentWithRegFile-DEF.pdf
		|   |       AggregationOuterComponentWithRegFile-HEADER.pdf
		|   |       AggregationOuterComponentWithRegFile.cpp
		|   |       AggregationOuterComponentWithRegFile.def
		|   |       ClientOfAggregationComponentWithRegFile.h
		|   |       HeaderForClientOfAggregationComponentWithRegFile.pdf
		|   |       
		|   \---ClientOfAggregationComponentWithRegFile
		|           AggregationOuterComponent-REG.pdf
		|           ClientOfAggregationComponentWithRegFile-CPP.pdf
		|           ClientOfAggregationComponentWithRegFile.h
		|           HeaderForClientOfAggregationComponentWithRegFile.pdf
		|           
		\---04_Automation
			|   Multiple Dual Interfaces-Not Recommended.pdf
			|   
			+---32-bit
			|   +---01-AutomationServerWithRegFile
			|   |   |   AutomationServerWithRegFile-REG.pdf
			|   |   |   midl-command-TXT.pdf
			|   |   |   
			|   |   +---AutomationProxyStub
			|   |   |       AutomationProxyStub-DEF.pdf
			|   |   |       AutomationServerTypeLib-IDL.pdf
			|   |   |       
			|   |   \---AutomationServerWithRegFile
			|   |           AutomationServerWithRegFile-CPP.pdf
			|   |           AutomationServerWithRegFile-DEF.pdf
			|   |           AutomationServerWithRegFile-HEADER.pdf
			|   |           
			|   \---02-ClientOfAutomationServerWithRegFile
			|       +---01-IClassFactoryAutomationClient
			|       |       AutomationServerWithRegFile-HEADER.pdf
			|       |       IClassFactoryAutomationClient-CPP.pdf
			|       |       
			|       +---02-IDispatchAutomationClient
			|       |       AutomationServerWithRegFile-HEADER.pdf
			|       |       IDispatchAutomationClient-CPP.pdf
			|       |       
			|       +---03-C#Client
			|       |       ReadMe.txt
			|       |       
			|       \---04-VBClient
			|               ReadMe.txt
			|               
			\---64-bit
				+---01-AutomationServerWithRegFile
				|       AutomationServerWithRegFile-REG.pdf
				|       midl-command_64Bit-TXT.pdf
				|       
				\---02-ClientOfAutomationServerWithRegFile
					+---03-C#Client
					|       C# CommandLine Compilation For CSharpAutomation-TXT.pdf
					|       CSharpAutomation-CS.pdf
					|       
					\---04-VBClient
							VB CommandLine Compilation For VBAutomation-TXT.pdf
							VBAutomation-VB.pdf
							
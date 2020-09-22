cls

cl.exe ClientOfClassFactoryDllServerWithRegFile.cpp /c /EHsc

link.exe ClientOfClassFactoryDllServerWithRegFile.obj gdi32.lib user32.lib kernel32.lib ole32.lib oleaut32.lib /SUBSYSTEM:WINDOWS

ClientOfClassFactoryDllServerWithRegFile.exe

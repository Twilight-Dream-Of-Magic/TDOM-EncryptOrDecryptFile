@Echo off

Color 1A

Cd /d %~dp0
If Not Exist "..\\..\\..\\Test_Binary\\Alpha-Version3.2\\" (
Mkdir "..\\..\\..\\Test_Binary\\Alpha-Version3.2\\"
) Else (
Echo "Info :EODF Test_Binary Folder Already Exist !"
)
Cls

Echo "---------- Code Compile Start ----------"

:: g++.exe -shared -o
:: g++.exe -finput-charset=GBK
:: g++.exe -fexec-charset=UTF-8

g++.exe -fexec-charset=GBK -O2 -c ".\\Main_EODF3-2_By_TDOM.cpp" -o "..\\..\\..\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2.objective-binary"
g++.exe -shared "..\\..\\..\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2.objective-binary" -o "..\\..\\..\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2.exe"
g++.exe -static "..\\..\\..\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2.objective-binary" -o "..\\..\\..\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2_StaticLink.exe"

Echo "---------- Code Compile End ----------"

Pause
Cls
Exit

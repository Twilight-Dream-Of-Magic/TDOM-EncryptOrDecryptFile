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

Cd /d "..\\..\\..\\"

g++.exe -finput-charset=GBK -fexec-charset=GBK -O2 -c ".\\[Encrypt_Or_Decrypt_File]-Source-Code\\Test-Version\\Alpha-Version3.2\\Main_EODF3-2_By_TDOM.cpp" -o ".\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2.objective-binary"
g++.exe -shared ".\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2.objective-binary" -o ".\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2.exe"
g++.exe -static ".\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2.objective-binary" -o ".\\Test_Binary\\Alpha-Version3.2\\CUI_EncryptDecryptFile_TestVersion3-2_StaticLink.exe"

Cd /d ".\\[Encrypt_Or_Decrypt_File]-Source-Code\\Test-Version\\Alpha-Version3.2\\"

Echo "---------- Code Compile End ----------"

Pause
Cls
Exit

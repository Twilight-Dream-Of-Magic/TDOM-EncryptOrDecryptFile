@Echo off

Color 1A

Cd /d %~dp0
If Not Exist "..\\..\\..\\Test_Binary\\Alpha-Version3.1\\" (
Mkdir "..\\..\\..\\Test_Binary\\Alpha-Version3.1\\"
) Else (
Echo "Info :EODF Test_Binary Folder Already Exist !"
)
Cls

Echo "---------- Code Compile Start ----------"
:: g++.exe -shared -o
:: g++.exe -finput-charset=GBK
:: g++.exe -fexec-charset=UTF-8

Cd /d "..\\..\\..\\"

g++.exe -finput-charset=GBK -fexec-charset=GBK -O2 -c ".\\[Encrypt_Or_Decrypt_File]-Source-Code\\Test-Version\\Alpha-Version3.1\\Main_EODF3-1_By_TDOM.cpp" -o ".\\Test_Binary\\Alpha-Version3.1\\CUI_EncryptDecryptFile_TestVersion3-1.objective-binary"
g++.exe -shared ".\\Test_Binary\\Alpha-Version3.1\\CUI_EncryptDecryptFile_TestVersion3-1.objective-binary" -o ".\\Test_Binary\\Alpha-Version3.1\\CUI_EncryptDecryptFile_TestVersion3-1.exe"
g++.exe -static ".\\Test_Binary\\Alpha-Version3.1\\CUI_EncryptDecryptFile_TestVersion3-1.objective-binary" -o ".\\Test_Binary\\Alpha-Version3.1\\CUI_EncryptDecryptFile_TestVersion3-1_StaticLink.exe"

Cd /d ".\\[Encrypt_Or_Decrypt_File]-Source-Code\\Test-Version\\Alpha-Version3.1\\"

Echo "---------- Code Compile End ----------"

Pause
Cls
Exit

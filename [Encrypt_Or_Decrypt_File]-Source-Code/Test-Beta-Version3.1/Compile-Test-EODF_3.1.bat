@Echo off

Color 1A

Cd /d %CD%
If Not Exist "..\\..\\Test_Binary\\Beta-Vesion3.1\\" (
Mkdir "..\\..\\Test_Binary\\Beta-Vesion3.1\\"
) Else ( 
Echo "Info :EODF Test_Binary Folder Already Exist !"
)
:: g++.exe -shared -o
:: -fexec-charset=GB2312
g++.exe -O2 -c ".\\Main_EODF3-1_By_Twlilght_Yujiang.cpp" -o "..\\..\\Test_Binary\\Beta-Vesion3.1\\CUI_EncryptDecryptFile_TestVersion3-1.binary-objective"
:: g++.exe -finput-charset=UTF-8
g++.exe -shared "..\\..\\Test_Binary\\Beta-Vesion3.1\\CUI_EncryptDecryptFile_TestVersion3-1.binary-objective" -o "..\\..\\Test_Binary\\Beta-Vesion3.1\\CUI_EncryptDecryptFile_TestVersion3-1.exe"
g++.exe -static "..\\..\\Test_Binary\\Beta-Vesion3.1\\CUI_EncryptDecryptFile_TestVersion3-1.binary-objective" -o "..\\..\\Test_Binary\\Beta-Vesion3.1\\CUI_EncryptDecryptFile_TestVersion3-1_StaticLink.exe"
Echo Code Compile End
Pause
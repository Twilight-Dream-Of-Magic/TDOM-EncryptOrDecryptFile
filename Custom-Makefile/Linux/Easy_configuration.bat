@Echo off



::Cd /d "%CD%"

Cd /d %~dp0

Color 0A



::Initialization File

If Not Exist "..\\Makefile" (

Goto Main

) Else If Not Exist "Makefile.Header" (

Goto Main

) Else (

Goto Check_File

)




:Old_File_Cannot_Remove

Color 06

Cls

Echo "FAILED: The script file configuration has not changed since there were some errors."

Echo "Old [Makefile] script file can not remove in the this directory!"

Pause

Exit



:New_File_Not_Found

Color 04

Cls

Echo "FAILED: The script file configuration has not changed since there were some errors."

Echo "New [Makefile] script file not found in the this directory!"

Pause

Exit



:Check_File

If Exist "..\\Makefile.Header" (

Cls

Del /f /q "..\\Makefile.Header"

Goto Check_File2

) Else (

Echo "INFOMATION: Old [Makefile.Header] script file alrady exist."

Goto Old_File_Cannot_Remove

) 



:Check_File2

If Exist "..\\Makefile" (

Cls

Del /f /q "..\\Makefile"

Goto Check_File3

) Else (

Echo "INFOMATION: Old [Makefile] script file alrady exist."

Goto Old_File_Cannot_Remove

)



:Check_File3

If Exist ".\\Makefile.Header" (

Goto Check_File4

) Else (

If Not Exist ".\\Makefile.Header" Goto New_File_Not_Found

)



:Check_File4

If Exist ".\\Makefile" (

Goto Main

) Else (

If Not Exist ".\\Makefile" Goto New_File_Not_Found

)



:Main

Color 02

Cls

Copy /y ".\\Makefile" "..\\"

Copy /y ".\\Makefile.Header" "..\\"

Cd /d "..\\"

make help

Echo "SUCCESSFUL: Configuration [Makefile] Script File Done!"

:Quit

Pause

Cls

Exit


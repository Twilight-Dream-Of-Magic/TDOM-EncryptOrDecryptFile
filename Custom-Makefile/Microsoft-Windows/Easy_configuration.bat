@Echo off

Cd /d "%~dp0"

Color 1A

If Not Exist ".\Makefile" || ".\Makefile.Header" (

Goto File_Not_Found_Error

) Else If Not Exist ".\Makefile.Header" && ".\Makefile" (

Goto File_Not_Found_Error

) Else (

Goto Main

)

:File_Not_Found_Error
Cls
Echo "Script file configuration failed with error."
Echo "Makefile File not found in the this directory!"
Goto Quit

:Main

If Exist "..\Makefile" (

Cls
Del /f /s /q ..\Makefile

) Else If Exist "..\Makefile.Header" (

Cls
Del /f /s /q ..\Makefile.Header

) Else (

Cls
Copy /y ".\Makefile" "..\"
Copy /y ".\Makefile.Header" "..\"

Cd /d ..\

make help

(

Echo "Config Makefile Script File Done!"

:Quit

Pause

Cls

Exit


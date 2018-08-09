#This File Makefile Scrpit

#Command Separator Is Tab Keyboard!!!

include Makefile.Header

.PHONY = all clean
.PHONY = build_version1 build_version2 build_version3
.PHONY = bebug_mode_version bebug_mode_version2 bebug_mode_version3
.PHONY = release_beta_version release_beta_version2 release_beta_version3
.PHONY = run run_bebug run.bat run_bebug.bat
.PHONY = LINKING_OBJECTIVES STATIC_LINKING_OBJECTIVES



#Build All Project File



all:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 01

	- make config_all

	- @make debug_mode_version
	- @pause
	- @make debug_mode_version2
	- @pause
	- @make debug_mode_version3
	- @pause
	- @cls

	- @make release_beta_version
	- @pause
	- @make release_beta_version2
	- @pause
	- @make release_beta_version3
	- @pause
	- @cls
	- $(COMMAND_WINDOW_COLOR) 01



#Configuration Project Environment



release_folder:

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION_FOLDER)

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION2_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION2_FOLDER)

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION3_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION3_FOLDER)

debug_folder:

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION_FOLDER)

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION2_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION2_FOLDER)

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION3_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION3_FOLDER)

config_all:

	- @make release_folder
	- @make debug_folder



#Build One Version Project File



build_version1:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 12
	- @make debug_mode_version
	- @make release_beta_version
	- @pause
	- @cls

build_version2:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 12
	- @make debug_mode_version2
	- @make release_beta_version2
	- @pause
	- @cls

build_version3:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 12
	- @make debug_mode_version3
	- @make release_beta_version3
	- @pause
	- @cls



#Build Debug File



debug_mode_version:

	- @cd /d %~dp0
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 05

	- @make debug_folder

	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION) -o $(DEBUG_OBJECTIVES_VERSION)
	- @pause
	- @cls
	- $(LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION) -o $(DEBUG_EXECUTE_FILE_VERSION)
	- $(STATIC_LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION) -o $(DEBUG_STATIC_EXECUTE_FILE_VERSION)
	- @pause
	- @cls

debug_mode_version2:

	- @cd /d %~dp0
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 06

	- @make debug_folder

	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION2) -o $(DEBUG_OBJECTIVES_VERSION2)
	- @pause
	- @cls
	- $(LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION2) -o $(DEBUG_EXECUTE_FILE_VERSION2)
	- $(STATIC_LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION2) -o $(DEBUG_STATIC_EXECUTE_FILE_VERSION2)
	- @pause
	- @cls

debug_mode_version3:

	- @cd /d %~dp0
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 07

	- @make debug_folder

	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION3) -o $(DEBUG_OBJECTIVES_VERSION3)
	- @pause
	- @cls
	- $(LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION3) -o $(DEBUG_EXECUTE_FILE_VERSION3)
	- $(STATIC_LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION3) -o $(DEBUG_STATIC_EXECUTE_FILE_VERSION3)
	- @pause
	- @cls



#Build Release File



release_beta_version:

	- @cd /d %~dp0
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 02

	- @make release_folder

	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION) -o $(RELEASE_OBJECTIVES_VERSION)
	- @pause
	- @cls
	- $(LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION) -o $(RELEASE_EXECUTE_FILE_VERSION)
	- $(STATIC_LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION) -o $(RELEASE_STATIC_EXECUTE_FILE_VERSION)
	- @pause
	- @cls

release_beta_version2:

	- @cd /d %~dp0
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 03

	- @make release_folder

	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION2) -o $(RELEASE_OBJECTIVES_VERSION2)
	- @pause
	- @cls
	- $(LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION2) -o $(RELEASE_EXECUTE_FILE_VERSION2)
	- $(STATIC_LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION2) -o $(RELEASE_STATIC_EXECUTE_FILE_VERSION2)

release_beta_version3:

	- @cd /d %~dp0
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 04

	- @make release_folder

	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION3) -o $(RELEASE_OBJECTIVES_VERSION3)
	- @pause
	- @cls
	- $(LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION3) -o $(RELEASE_EXECUTE_FILE_VERSION3)
	- $(STATIC_LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION3) -o $(RELEASE_STATIC_EXECUTE_FILE_VERSION3)
	- @pause
	- @cls



#Run Program



run.bat:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 08
	- cd /d %~dp0
	- @echo @echo off >> run.bat
	- @echo.>>run.bat
	- @echo cd /d $(RELEASE_EXECUTE_VERSION3_FOLDER) >> run.bat
	- @echo.>>run.bat
	- @echo start .\\CUI_EncryptDecryptFile_BetaVersion3.exe >> run.bat
	- @start ".\\run.bat"

run_debug.bat:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 09
	- cd /d %~dp0
	- @echo @echo off >> run_debug.bat
	- @echo.>>run_debug.bat
	- @echo cd /d $(DEBUG_EXECUTE_VERSION3_FOLDER) >> run_debug.bat
	- @echo.>>run_debug.bat
	- @echo start .\\CUI_EncryptDecryptFile_DebugVersion3.exe >> run_debug.bat
	- @start ".\\run_debug.bat"

run:

	- make run.bat

run_debug:

	- make run_debug.bat



#Clean This Project



clean_debug:

	- @cd /d %~dp0
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 10

	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION)
	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION2)
	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION3)

	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION)
	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION3)
	
	- $(DELETE) $(DEBUG_STATIC_EXECUTE_FILE_VERSION)
	- $(DELETE) $(DEBUG_STATIC_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(DEBUG_STATIC_EXECUTE_FILE_VERSION3)

	- $(DELETE) "..\\Binary\\Debug\\*.*"
	- $(DELETE) "..\\Objectives\\Debug\\*.*"

	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION3_FOLDER)

	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION3_FOLDER)

	- $(DELETE) "..\\run_debug.bat"

clean_release:

	- @cd /d %~dp0
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 10

	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION)
	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION2)
	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION3)

	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION)
	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION3)
	
	- $(DELETE) $(RELEASE_STATIC_EXECUTE_FILE_VERSION)
	- $(DELETE) $(RELEASE_STATIC_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(RELEASE_STATIC_EXECUTE_FILE_VERSION3)

	- $(DELETE) "..\\Binary\\Release\\*.*"
	- $(DELETE) "..\\Objectives\\Release\\*.*"

	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION3_FOLDER)

	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION3_FOLDER)

	- $(DELETE) "..\\run.bat"

clean:

	- make clean_debug
	- make clean_release

	- $(REMOVE_FOLDER) "..\\Binary\\"
	- $(REMOVE_FOLDER) "..\\Objectives\\"



#Display Help Massage



help:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 11
	- @cls
	- @echo "make all"
	- @echo "make build_version1"
	- @echo "make build_version2"
	- @echo "make build_version3"
	- @echo "make debug_mode_version (debug)"
	- @echo "make debug_mode_version2 (debug)"
	- @echo "make debug_mode_version3 (debug)"
	- @echo "make release_beta_version (release)"
	- @echo "make release_beta_version2 (release)"
	- @echo "make release_beta_version3 (release)"
	- @echo "make config_all"
	- @echo "make run"
	- @echo "make run_debug"
	- @echo "make clean"
	- @echo "make help"

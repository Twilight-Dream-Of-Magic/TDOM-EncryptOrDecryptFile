#This File Is Makefile Script

#Command Separator Is Tab Keyboard!!!

include Makefile.Header

.PHONY = all clean
.PHONY = build_version1 build_version2 build_version3
.PHONY = bebug_mode_version bebug_mode_version2 bebug_mode_version3
.PHONY = release_beta_version release_beta_version2 release_beta_version3
.PHONY = run run_bebug run.sh run_bebug.sh
.PHONY = LINKING_OBJECTIVES STATIC_LINKING_OBJECTIVES



#Build All Project File



all:

	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR)

	- make config_all

	- make debug_mode_version
	- sleep 5s
	- make debug_mode_version2
	- sleep 5s
	- make debug_mode_version3
	- sleep 5s
	- clear

	- $(CONSOLE_COLOR2)

	- make release_beta_version
	- sleep 5s
	- make release_beta_version2
	- sleep 5s
	- make release_beta_version3
	- sleep 5s
	- clear

	- $(DEFAULT_COLOR)



#Configuration Project Environment



release_folder:

	- $(CONSOLE_COLOR3)

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION_FOLDER)

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION2_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION2_FOLDER)

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION3_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION3_FOLDER)

	- $(DEFAULT_COLOR)

debug_folder:

	- $(CONSOLE_COLOR4)

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION_FOLDER)

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION2_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION2_FOLDER)

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION3_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION3_FOLDER)

	- $(DEFAULT_COLOR)

config_all:

	- make release_folder
	- make debug_folder



#Build One Version Project File



build_version1:

	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR5)

	- make debug_mode_version
	- make release_beta_version
	- sleep 5s
	- clear

	- $(DEFAULT_COLOR)

build_version2:

	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR6)

	- make debug_mode_version2
	- make release_beta_version2
	- sleep 5s
	- clear



build_version3:

	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR7)

	- make debug_mode_version3
	- make release_beta_version3
	- sleep 5s
	- clear

	- $(DEFAULT_COLOR)

#Build Debug File



debug_mode_version:

	- cd $PWD
	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR8)

	- make debug_folder
	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION) -o $(DEBUG_OBJECTIVES_VERSION)
	- sleep 5s
	- clear
	- $(LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION) -o $(DEBUG_EXECUTE_FILE_VERSION)
	- $(STATIC_LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION) -o $(DEBUG_STATIC_EXECUTE_FILE_VERSION)
	- sleep 5s
	- clear

	- $(DEFAULT_COLOR)

debug_mode_version2:

	- cd $PWD
	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR9)

	- make debug_folder
	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION2) -o $(DEBUG_OBJECTIVES_VERSION2)
	- sleep 5s
	- clear
	- $(LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION2) -o $(DEBUG_EXECUTE_FILE_VERSION2)
	- $(STATIC_LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION2) -o $(DEBUG_STATIC_EXECUTE_FILE_VERSION2)
	- sleep 5s
	- clear

	- $(DEFAULT_COLOR)

debug_mode_version3:

	- cd $PWD
	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR10)

	- make debug_folder
	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION3) -o $(DEBUG_OBJECTIVES_VERSION3)
	- sleep 5s
	- clear
	- $(LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION3) -o $(DEBUG_EXECUTE_FILE_VERSION3)
	- $(STATIC_LINKING_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION3) -o $(DEBUG_STATIC_EXECUTE_FILE_VERSION3)
	- sleep 5s
	- clear

	- $(DEFAULT_COLOR)



#Build Release File



release_beta_version:

	- cd $PWD
	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR11)

	- make release_folder
	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION) -o $(RELEASE_OBJECTIVES_VERSION)
	- sleep 5s
	- clear
	- $(LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION) -o $(RELEASE_EXECUTE_FILE_VERSION)
	- $(STATIC_LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION) -o $(RELEASE_STATIC_EXECUTE_FILE_VERSION)
	- sleep 5s
	- clear

	- $(DEFAULT_COLOR)

release_beta_version2:

	- cd $PWD
	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR12)

	- make release_folder
	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION2) -o $(RELEASE_OBJECTIVES_VERSION2)
	- sleep 5s
	- clear
	- $(LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION2) -o $(RELEASE_EXECUTE_FILE_VERSION2)
	- $(STATIC_LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION2) -o $(RELEASE_STATIC_EXECUTE_FILE_VERSION2)

	- $(DEFAULT_COLOR)

release_beta_version3:

	- cd $PWD
	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR13)

	- make release_folder
	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION3) -o $(RELEASE_OBJECTIVES_VERSION3)
	- sleep 5s
	- clear
	- $(LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION3) -o $(RELEASE_EXECUTE_FILE_VERSION3)
	- $(STATIC_LINKING_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION3) -o $(RELEASE_STATIC_EXECUTE_FILE_VERSION3)
	- sleep 5s
	- clear

	- $(DEFAULT_COLOR)



#Run Program



run.sh:

	- $(HIDDEN_CURSOR_MODE)
	- cd $PWD
	- echo "----------"
	- echo cd "$(RELEASE_EXECUTE_VERSION3_FOLDER)" >> run.sh
	- echo "----------"
	- echo ./CUI_EncryptDecryptFile_BetaVersion3.elf >> run.sh
	- ./run.sh
	- $(SHOW_CURSOR_MODE)

run_debug.sh:

	- $(HIDDEN_CURSOR_MODE)
	- cd $PWD
	- echo "----------"
	- echo cd "$(DEBUG_EXECUTE_VERSION3_FOLDER)" >> run_debug.sh
	- echo "----------"
	- echo ./CUI_EncryptDecryptFile_DebugVersion3.elf >> run_debug.sh
	- ./run_debug.sh
	- $(SHOW_CURSOR_MODE)

run:

	- make run.sh

run_debug:

	- make run_debug.sh



#Clean This Project



clean_debug:

	- cd $PWD
	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR14)

	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION)
	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION2)
	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION3)

	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION)
	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION3)
	
	- $(DELETE) $(DEBUG_STATIC_EXECUTE_FILE_VERSION)
	- $(DELETE) $(DEBUG_STATIC_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(DEBUG_STATIC_EXECUTE_FILE_VERSION3)

	- $(DELETE) "..//Binary//Linux//Debug//*.*"
	- $(DELETE) "..//Objectives//Linux//Debug//*.*"

	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION3_FOLDER)

	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION3_FOLDER)

	- $(DELETE) "..//run_debug.sh"

	- $(DEFAULT_COLOR)

clean_release:

	- cd $PWD
	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR15)

	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION)
	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION2)
	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION3)

	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION)
	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION3)
	
	- $(DELETE) $(RELEASE_STATIC_EXECUTE_FILE_VERSION)
	- $(DELETE) $(RELEASE_STATIC_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(RELEASE_STATIC_EXECUTE_FILE_VERSION3)

	- $(DELETE) "..//Binary//Linux//Release/*.*"
	- $(DELETE) "..//Objectives//Linux//Release//*.*"

	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION3_FOLDER)

	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION3_FOLDER)

	- $(DELETE) "..//run.sh"

	- $(DEFAULT_COLOR)

clean_all:

	- make clean_debug
	- make clean_release

	- $(REMOVE_FOLDER) "..//Binary//Linux//"
	- $(REMOVE_FOLDER) "..//Objectives//Linux//"



#Display Help Massage



help:

	- $(HIDDEN_CURSOR_MODE)
	- $(CONSOLE_COLOR16)-----THIS PROJECT MAKEFILE HELP COMMAND-----
	- sleep 2s
	- clear
	- echo "make all"
	- echo "make build_version1"
	- echo "make build_version2"
	- echo "make build_version3"
	- echo "make debug_mode_version (debug)"
	- echo "make debug_mode_version2 (debug)"
	- echo "make debug_mode_version3 (debug)"
	- echo "make release_beta_version (release)"
	- echo "make release_beta_version2 (release)"
	- echo "make release_beta_version3 (release)"
	- echo "make config_all"
	- echo "make run"
	- echo "make run_debug"
	- echo "clean_release"
	- echo "make clean_debug"
	- echo "make clean_all"
	- echo "make help"
	- sleep 2s
	- $(DEFAULT_COLOR)
	- $(SHOW_CURSOR_MODE)

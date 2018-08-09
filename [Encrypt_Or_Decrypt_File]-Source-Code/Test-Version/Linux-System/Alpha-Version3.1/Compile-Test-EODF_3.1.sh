#!/usr/bin/env sh
#!/usr/bin/env bash
#!/usr/bin/env zsh

#echo -e '\033[44m'
#Linux Console Backgroud Color: Blue

#echo -e '\033[0;92m'
#Linux Console Foregroud Color: Light Green

#echo -e '\033[44;92m'
#Linux Console Backgroud Color: Blue + Foregroud Color: Light Green'

PROJECT_DIRECTORY="..//..//..//..//Test_Binary//Other-Platform//Linux//Alpha-Version3.1"

Compile_file()
{
	echo -e "\033[44;92m---------- Code Compile Start ----------"

    # g++ -shared -o
    # g++ -finput-charset=UTF-8
    # g++ -fexec-charset=GBK

    g++ -fexec-charset=UTF-8 -O2 -c ".//Main_EODF3-1_By_TDOM.cpp" -o "$PROJECT_DIRECTORY//CUI_EncryptDecryptFile_TestVersion3-1.objective-binary"
    g++ -shared "$PROJECT_DIRECTORY//CUI_EncryptDecryptFile_TestVersion3-1.objective-binary" -o "$PROJECT_DIRECTORY//CUI_EncryptDecryptFile_TestVersion3-1.elf"
    g++ -static "$PROJECT_DIRECTORY//CUI_EncryptDecryptFile_TestVersion3-1.objective-binary" -o "$PROJECT_DIRECTORY//CUI_EncryptDecryptFile_TestVersion3-1_StaticLink.elf"

    echo -e "---------- Code Compile End ----------\033[0;0m"

    sleep 5s
    clear

    Quit
}

Initialization_file()
{
    cd "$PWD"

    if test -d $PROJECT_DIRECTORY
    then

        echo "Info :EODF Test_Binary Folder Already Exist !"
        sleep 5s

        Compile_file

    else

        mkdir --parents --verbose $PROJECT_DIRECTORY

        Compile_file

    fi
}

Quit()
{
    echo -e '\033[0m'  #Linux Console Reset Color
    exit 0
}

Main()
{
    Initialization_file
}

Main

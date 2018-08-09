#!/usr/bin/env sh
#!/usr/bin/env bash
#!/usr/bin/env zsh

File="Makefile"
File1="Makefile.Header"
Old_File="../Makefile"
Old_File1="../Makefile.Header"

Copy_new_script_file()
{
  cp --force $File "../"
  cp --force $File1 "../"
}

Remove_old_script_file()
{
  rm --force $Old_File
  rm --force $Old_File1
}

Quit()
{
  sleep 2s

  exit 0
}

Configuration_file()
{

  if [ test -f $Old_File && $Old_File1 ];
    then

      clear

      Remove_old_script_file

      Copy_new_script_file

  elif [ test -f $Old_File || $Old_File1 ];
    then

      Remove_old_script_file

      Copy_new_script_file

  else

    clear

    Copy_new_script_file

  fi

  #make help

  sleep 2s

  Return_success

}

Return_fail()
{
  clear

  echo "Script file configuration failed with error."

  echo "Makefile File not found in the this directory!"

  Quit
}

Return_success()
{
  clear

  echo "Config Makefile Script File Done!"

  Quit
}


Work_status()
{

  if [ test ! -f $File || $File1 ];
    then

      Return_fail

  elif [ test ! -f $File && $File1 ];
    then

      Return_fail

  else

    Configuration_file

  fi
}

Main()
{

  cd "$PWD"

  Work_status

}

Main

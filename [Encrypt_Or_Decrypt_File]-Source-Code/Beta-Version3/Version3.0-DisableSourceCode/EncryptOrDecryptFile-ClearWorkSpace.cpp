#include <iostream>  //计算机C++语言标准输入输出函数 Computer C++ language standard input and output functions
#include <stdio.h>   //计算机C语言标准输入输出函数 Computer C language standard input and output functions
#include <stdlib.h>  //计算机C语言标准库函数 Computer C language standard library functions
#include <string>    //计算机C++语言字符串处理函数 Computer C++ language string handling functions
#include <windows.h>
#include "stdafx.h"

using namespace std;

void ConsoleTableColorSet(int R,int G,int B)
{
    if(R<0) R=0;
    if(R>1) R=1;

    if(G<0) G=0;
    if(G>1) G=1;

    if(B<0) B=0;
    if(B>1) B=1;

    if(R == 1 && G == 1 && B == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    }
    else if(R == 1 && G == 1 && B == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    }
    else if(R == 1 && G == 0 && B == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    }
    else if(R == 0 && G == 1 && B == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    }
    else if(R == 1 && G == 0 && B == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    }
    else if(R == 0 && G == 1 && B == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    }
    else if(R == 0 && G == 0 && B == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
    }
}

int main()
{
Clear_Workspace_Program_Main_Menu:

  string Load_User_Keyboard_Input;
  string Input_Judgment_Clear_Workspace;
  
  system("color 0f");
  std :: cout << "If you know the risk\n[Keyboard input " << "ClearWorkSpace" << " to continue]\n" << "[Or Keyboard input " << "Quit" << " stop this program]" << endl;
  std :: cout << "如果你知道风险\n[键盘输入" << "ClearWorkSpace" << "继续]\n" << "[或键盘输入" << "Quit" << "停止此程序]" << endl;
  std :: cin >> Load_User_Keyboard_Input;
  system("cls");

  if(Load_User_Keyboard_Input == "ClearWorkSpace")
  {
    cin.ignore(10240,'\n'); //Delete 10240 bytes of data within the "cin" buffer 删除“cin”缓冲区内的10240个字节的数据
    cin.clear(); //Change the status identifier of the input stream "cin" and reset it. 更改输入流“cin”的状态标示符，并且重置。
    cin.sync(); //Clear all the contents of the input stream "cin" buffer area. 清除输入流“cin”缓冲区域的所有内容。

    Clear_Workspace_Restart:

    system("color 0C");

      std :: cout << "[警告!]即将进行的操作，会选中 <File-Key-Record-Log> 和 <WorkPath> 文件夹，然后永久的删除所有数据!\n" << endl;
      std :: cout << "包括源文件、生成的加密文件、生成的解密文件、密码日志、配置\n" << endl;
      std :: cout << "如果你知道风险，请按键盘 [Y键继续 N键返回]\n注释:[ Yes / No ]" << endl;

      std :: cout << "[Warning!] The upcoming operation will select the <File-Key-Record-Log>and <WorkPath folders>, and then permanently delete all the data!\n" << endl;
      std :: cout << "Including source files, generated encrypted files, generated decrypted files, password logs, configuration\n" << endl;
      std :: cout << "If you know the risk, press the keypad [Y key to continue N key to return]\nAnnotations:[Yes / No]" << endl;
      std :: cin >> Input_Judgment_Clear_Workspace;

      //string All_Clear_Workspace_Value[52] = {"Y" || "y" || "YES" || "Yes" || "yes" || "Y\n" || "y\n" || "YES\n" || "Yes\n" || "yes\n" || " Y\r" || "y\r" || "YES\r" || "Yes\r" || "yes\r" || "Y\n\r" || "y\n\r" || "YES\n\r" || "Yes\n\r" || "yes\n\r" || " Y\r\n" || "y\r\n" || "YES\r\n" || "Yes\r\n" || "yes\r\n" || "N" || "n" || "NO" || "No" || "no" || "N\n" || "n\n" || "NO\n" || "No\n" || "no\n" || "N\r" || "n\r" || "NO\r" || "No\r" || "no\r" || "N\n\r" || "n\n\r" || "NO\n\r" || "No\n\r" || "no\n\r" || "N\r\n" || "n\r\n" || "NO\r\n" || "No\r\n" || "no\r\n" || "" || " "};
      //string Accept_Clear_Workspace_Value[25] = {"Y" || "y" || "YES" || "Yes" || "yes" || "Y\n" || "y\n" || "YES\n" || "Yes\n" || "yes\n" || " Y\r" || "y\r" || "YES\r" || "Yes\r" || "yes\r" || "Y\n\r" || "y\n\r" || "YES\n\r" || "Yes\n\r" || "yes\n\r" || " Y\r\n" || "y\r\n" || "YES\r\n" || "Yes\r\n" || "yes\r\n"};
      //string Denied_Clear_Workspace_Value[27] = {"N" || "n" || "NO" || "No" || "no" || "N\n" || "n\n" || "NO\n" || "No\n" || "no\n" || "N\r" || "n\r" || "NO\r" || "No\r" || "no\r" || "N\n\r" || "n\n\r" || "NO\n\r" || "No\n\r" || "no\n\r" || "N\r\n" || "n\r\n" || "NO\r\n" || "No\r\n" || "no\r\n" || "" || " "};

         if(Input_Judgment_Clear_Workspace == "Y") //Accept_Clear_Workspace_Value
         {
			Accept_Condition:
            DeleteFile(".\\SourceFileName_Temp.INI");
            DeleteFile(".\\SourceFileMainName_Temp.INI");
            DeleteFile(".\\SourceFileExtendedName_Temp.INI");

            system("@Del /s /f /q .\\File-Key-Record-Log\\*.*");
            system("@Del /s /f /q .\\WorkPath\\*.*");

            system("@Del /s /f /q .\\WorkPath\\Encrypt\\*.*");
            system("@Del /s /f /q .\\WorkPath\\Encrypt\\InputFile\\*.*");
            system("@Del /s /f /q .\\WorkPath\\Encrypt\\OutputFile\\*.*");

            system("@Del /s /f /q .\\WorkPath\\Decrypt\\*.*");
            system("@Del /s /f /q .\\WorkPath\\Decrypt\\InputFile\\*.*");
            system("@Del /s /f /q .\\WorkPath\\Decrypt\\OutputFile\\*.*");

            system("@Rmdir /s /q .\\File-Key-Record-Log\\");

            system("@Rmdir /s /q .\\WorkPath\\Encrypt\\OutputFile\\");
            system("@Rmdir /s /q .\\WorkPath\\Encrypt\\InputFile\\");
            system("@Rmdir /s /q .\\WorkPath\\Encrypt\\");

            system("@Rmdir /s /q .\\WorkPath\\Decrypt\\OutputFile\\");
            system("@Rmdir /s /q .\\WorkPath\\Decrypt\\InputFile\\");
            system("@Rmdir /s /q .\\WorkPath\\Decrypt\\");
            system("@Rmdir /s /q .\\WorkPath\\");

            system("cls");
			
           cin.ignore(10240,'\n'); //Delete 10240 bytes of data within the "cin" buffer 删除“cin”缓冲区内的10240个字节的数据
           cin.clear(); //Change the status identifier of the input stream "cin" and reset it. 更改输入流“cin”的状态标示符，并且重置。
           cin.sync(); //Clear all the contents of the input stream "cin" buffer area. 清除输入流“cin”缓冲区域的所有内容。
		   
           Input_Judgment_Clear_Workspace = "";
		   system("color 06");
		   std :: cout << "Workspace environment, clean up done!" << endl;
		   std :: cout << "工作空间环境,清理完成！" << endl;
		   system("pause");
		   system("cls");
          return 0;
         }
		 if(Input_Judgment_Clear_Workspace == "y")
		 {
		  goto Accept_Condition;
		 }
		 if(Input_Judgment_Clear_Workspace == "YES")
		 {
		  goto Accept_Condition;
		 }
		 if(Input_Judgment_Clear_Workspace == "Yes")
		 {
		  goto Accept_Condition;
		 }
		 if(Input_Judgment_Clear_Workspace == "yes")
		 {
		  goto Accept_Condition;
		 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         if(Input_Judgment_Clear_Workspace == "N") //Denied_Clear_Workspace_Value
         {
		   Denied_Condition:
		   system("color 02");
		   std :: cout << "Respect your choice, I will be here waiting for you, next time goodbye!" << endl;
		   std :: cout << "尊重你的选择，我会在这里等你，下次再见!" << endl;
		   system("pause");
		   system("cls");
           cin.ignore(10240,'\n'); //Delete 10240 bytes of data within the "cin" buffer 删除“cin”缓冲区内的10240个字节的数据
           cin.clear(); //Change the status identifier of the input stream "cin" and reset it. 更改输入流“cin”的状态标示符，并且重置。
           cin.sync(); //Clear all the contents of the input stream "cin" buffer area. 清除输入流“cin”缓冲区域的所有内容。
           Input_Judgment_Clear_Workspace = "";
           goto Clear_Workspace_Program_Main_Menu;
         }
		 if(Input_Judgment_Clear_Workspace == "n")
		 {
		  goto Denied_Condition;
		 }
		 if(Input_Judgment_Clear_Workspace == "NO")
		 {
		  goto Denied_Condition;
		 }
		 if(Input_Judgment_Clear_Workspace == "No")
		 {
		  goto Denied_Condition;
		 }
		 if(Input_Judgment_Clear_Workspace == "no")
		 {
		  goto Denied_Condition;
		 }
		 if(Input_Judgment_Clear_Workspace == "")
		 {
		  goto Denied_Condition;
		 }
		 if(Input_Judgment_Clear_Workspace == " ")
		 {
		  goto Denied_Condition;
		 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 else
		 {
			 if(Input_Judgment_Clear_Workspace != "Y") //All_Clear_Workspace_Value
             {
		       Incompatible_Condition:
		       system("color 0e");
		       std :: cout << "You entered incorrect keyboard data, please try re-enter the keyboard data!" << endl;
		       std :: cout << "您输入的键盘数据不正确，请尝试重新输入键盘数据！" << endl;
		       system("pause");
		       system("cls");
               Input_Judgment_Clear_Workspace = "";
		   
               cin.ignore(10240,'\n'); //Delete 10240 bytes of data within the "cin" buffer 删除“cin”缓冲区内的10240个字节的数据
               cin.clear(); //Change the status identifier of the input stream "cin" and reset it. 更改输入流“cin”的状态标示符，并且重置。
               cin.sync(); //Clear all the contents of the input stream "cin" buffer area. 清除输入流“cin”缓冲区域的所有内容。
		       goto Clear_Workspace_Restart;
             }
			 if(Input_Judgment_Clear_Workspace != "y")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "YES")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "Yes")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "yes")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "N")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "n")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "NO")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "No")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "no")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != "")
			 {
			   goto Incompatible_Condition;
			 }
			 if(Input_Judgment_Clear_Workspace != " ")
			 {
			   goto Incompatible_Condition;
			 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
             else
             {
                 ConsoleTableColorSet(0,0,0);
                 std :: cout << "There was an error while the program was running !" << endl;
		         std :: cout << "程序运行时发生错误！" << endl;
		         system("pause");
		         system("cls");
				 
                 cin.ignore(10240,'\n'); //Delete 10240 bytes of data within the "cin" buffer 删除“cin”缓冲区内的10240个字节的数据
                 cin.clear(); //Change the status identifier of the input stream "cin" and reset it. 更改输入流“cin”的状态标示符，并且重置。
                 cin.sync(); //Clear all the contents of the input stream "cin" buffer area. 清除输入流“cin”缓冲区域的所有内容。
                 exit(2);
             }
		 }
		 
    cin.ignore(10240,'\n'); //Delete 10240 bytes of data within the "cin" buffer 删除“cin”缓冲区内的10240个字节的数据
    cin.clear(); //Change the status identifier of the input stream "cin" and reset it. 更改输入流“cin”的状态标示符，并且重置。
    cin.sync(); //Clear all the contents of the input stream "cin" buffer area. 清除输入流“cin”缓冲区域的所有内容。
    Input_Judgment_Clear_Workspace = "";

  /*
    int Judgment_Clear_Workspace = 0;
    Judgment_Clear_Workspace++;
    Judgment_Clear_Workspace <= 3;

   switch(Judgment_Clear_Workspace)
   {
         case 1:
                break;
         case 2:
                break;
         case 3:
                break;
    default:
            break;
   }
   */

  }
  if(Load_User_Keyboard_Input == "Quit")
  {
    cin.ignore(10240,'\n'); //Delete 10240 bytes of data within the "cin" buffer 删除“cin”缓冲区内的10240个字节的数据
    cin.clear(); //Change the status identifier of the input stream "cin" and reset it. 更改输入流“cin”的状态标示符，并且重置。
    cin.sync(); //Clear all the contents of the input stream "cin" buffer area. 清除输入流“cin”缓冲区域的所有内容。
    return 0;
  }
  else
  {
    if(Load_User_Keyboard_Input != "ClearWorkSpace","Quit")
    {
      ConsoleTableColorSet(0,0,0);
      std :: cout << "User Keyboard Input Error Value!" << endl;
	  std :: cout << "用户键盘输入错误值！" << endl;
	  system("pause");
	  system("cls");
      cin.ignore(10240,'\n'); //Delete 10240 bytes of data within the "cin" buffer 删除“cin”缓冲区内的10240个字节的数据
      cin.clear(); //Change the status identifier of the input stream "cin" and reset it. 更改输入流“cin”的状态标示符，并且重置。
      cin.sync(); //Clear all the contents of the input stream "cin" buffer area. 清除输入流“cin”缓冲区域的所有内容。
      Load_User_Keyboard_Input = "";
      exit(1);
    }
  }
}

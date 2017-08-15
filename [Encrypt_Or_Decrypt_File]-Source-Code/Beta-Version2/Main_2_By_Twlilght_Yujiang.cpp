/****************************************************************************
Read Me - About This Source Code File

Chinese中文:
计算机语言类型: C++
程序文件名: Twlilght_Yujiang_File_Lock
程序平台类型: Windows 命令行控制台
程序实际作用: 文件对称式加密解密
版本: Beta 2.0
源代码修改时间: 2017-8-11
作者:Twlilght_Yujiang

English英文:
Chinese
Computer Language Type: C ++
Program File Name: Twlilght_Yujiang_File_Lock
Program Platform Type: Windows Command Line Console
The actual role of the program: file symmetric encryption and decryption
Version: Beta 2.0
Source code modified by: 2017-8-11
Author: Twlilght_Yujiang
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <stdio.h>   //C标准输入输出函数
#include <stdlib.h>  //C标准库函数
#include <string.h>  //字符串处理函数
#include <windows.h>

using namespace std;

//typedef unsigned char byte;

int RunEncryptFile(char *E_SourceFileName, char *E_KEY, char *E_KEY2, char *E_KEY3, char *E_TargetFileNewName);
int RunDecryptFile(char *D_SourceFileName, char *D_KEY, char *D_KEY2, char *D_KEY3, char *D_TargetFileNewName);

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
ProgramMainMenu:

    string Load_User_Keyboard_Input;

    system("color 0A");

    std :: cout << "----------" << endl;
    std :: cout << "Enter 1 EncryptFile" << endl;
    std :: cout << "Enter 2 DecryptFile" << endl;
    std :: cout << "Enter 3 Exit Program" << endl;
    std :: cout << "----------" << endl;
    std :: cout << "" << endl;
    std :: cout << "System:Input And Output/Enter>";

    std :: cin >> Load_User_Keyboard_Input;
	getchar();

    if(Load_User_Keyboard_Input == "1")
    {
       system("cls");
       system("color 1A");

       char E_SourceFileName[4096],    // 加密的文件名
            E_TargetFileNewName[4096]; // 加密后要保存的文件名

      //char E_TargetFileLastNameOutput = (E_TargetFileNewName + ".TY_ENCRYPTED"); //最后保存的加密后文件名

        char E_KEY[128], //File (Encryption or Encrypted) key 文件加密密钥
             E_KEY2[128],
             E_KEY3[128];

         std :: cout << "Please input >>> the source file name.\nDo not enter spaces!\n(Contains the directory name):" << endl;
         std :: cout << "输入要加密的文件名,[C:\]不要输入空格(含路径)：" << endl;
         std :: cin >> E_SourceFileName;

          std :: cout << "\n";
          std :: cout << "输入(长度小于128)密钥,不要输入空格：" << endl;  //密钥是用户自己定义的，(长度小于128)。可以随意给需要加密的文件添加密钥
          std :: cout << "Please input >>> the key,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> E_KEY;

          std :: cout << "\n";
		  std :: cout << "输入(长度小于128)密钥2,不要输入空格：" << endl;
          std :: cout << "Please input >>> the key2,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> E_KEY2;

          std :: cout << "\n";
          std :: cout << "输入(长度小于128)密钥3,不要输入空格：" << endl;
          std :: cout << "Please input >>> the key3,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> E_KEY3;

           std :: cout << "\n";
           std :: cout << "Please output >>> the target file new name.\nDo not enter spaces!\n(Contains the directory name):" << endl;
           std :: cout << "加密后的文件名,不要输入空格(含路径)：" << endl;  //给加密后的文件命名，并保存
           std :: cin >> E_TargetFileNewName;
           system("cls");

		   std :: cout << "正在记录并导出，本次用于文件加密，3个密钥字符串......" << endl;
		   std :: cout << "Is being recorded and exported, this time for file encryption, 3 key string......" << endl;
		   ofstream PasswordOutputKeyFile;
		   PasswordOutputKeyFile.open("FILE-ENCRYPTION-DECRYPTIPN-PASSWORD.KEY.TXT");
		   PasswordOutputKeyFile << "Twlilght_Yujiang File Lock Password [Key String] Save\n" << endl;
		   PasswordOutputKeyFile << "\n" << endl;
		   PasswordOutputKeyFile << "Source Input File Name and Path: " << E_SourceFileName << "\n" << endl;
		   PasswordOutputKeyFile << "EncryptFile: New Output Target File Name and Path: " << E_TargetFileNewName << "\n" << endl;
		   PasswordOutputKeyFile << "Key string1 [Password1]: " << E_KEY << "\n" << endl;
		   PasswordOutputKeyFile << "Key string2 [Password2]: " << E_KEY2 << "\n" << endl;
		   PasswordOutputKeyFile << "Key string3 [Password3]: " << E_KEY3 << "\n" << endl;
		   PasswordOutputKeyFile << "<******************************************************************************************>" << "\n" << endl;
		   PasswordOutputKeyFile.close();

	        std :: cout << "Please wait, read and write in the file......" << endl;
	        std :: cout << "请等待，文件读写中......" << endl;
	        getchar();

      if(RunEncryptFile(E_SourceFileName, E_KEY, E_KEY2, E_KEY3, E_TargetFileNewName))
      {
         printf("恭喜你，文件[%s]加密成功，保存在[%s]。\n", E_SourceFileName, E_TargetFileNewName);
         printf("Congratulations, the file [%s] is encrypted successfully, saved in [%s]. \n", E_SourceFileName, E_TargetFileNewName);
		 getchar();
         system("pause");
         system("cls");
         goto ProgramMainMenu;
      }
    }
    if(Load_User_Keyboard_Input == "2")
    {
       system("cls");
       system("color 1A");

   	   char D_SourceFileName[4096],    //源文件名
            D_TargetFileNewName[4096]; //目标文件新名称

       //char D_TargetFileLastNameOutput = (D_TargetFileNewName - ".TY_ENCRYPTED"); //最后保存的解密后文件名

        char D_KEY[128], //File (Decryption or Decrypted) key 文件解密密钥
             D_KEY2[128],
             D_KEY3[128];

         std :: cout << "Please input >>> the source file name.\nDo not enter spaces!\n(Contains the directory name):" << endl;
		 std :: cout << "输入要解密的文件名,[C:\]不要输入空格(含路径)：" << endl;
         std :: cin >> D_SourceFileName;

          std :: cout << "\n";
          std :: cout << "输入(长度小于128)密钥,不要输入空格：" << endl;  //密钥是用户自己定义的，可以随意给需要解密的文件输入密钥
          std :: cout << "Please input >>> the key3,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> D_KEY;

          std :: cout << "\n";
		  std :: cout << "输入(长度小于128)密钥2,不要输入空格：" << endl;
		  std :: cout << "Please input >>> the key2,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> D_KEY2;

          std :: cout << "\n";
		  std :: cout << "输入(长度小于128)密钥3,不要输入空格：" << endl;
		  std :: cout << "Please input >>> the key,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> D_KEY3;

           std :: cout << "\n";
		   std :: cout << "Please output >>> the target file new name.\nDo not enter spaces!\n(Contains the directory name):" << endl;
           std :: cout << "解密后的文件名,不要输入空格(含路径)：" << endl;  //给解密后的文件命名，并保存
           std :: cin >> D_TargetFileNewName;
           system("cls");

		    std :: cout << "Please wait, read and write in the file......" << endl;
	        std :: cout << "请等待，文件读写中......" << endl;
		    getchar();

       if(RunDecryptFile(D_SourceFileName, D_KEY, D_KEY2, D_KEY3, D_TargetFileNewName))
       {
          printf("恭喜你，文件[%s]解密成功，保存在[%s]。\n", D_SourceFileName, D_TargetFileNewName);
          printf("Congratulations, the file [%s] is decrypted successfully, saved in [%s]. \n", D_SourceFileName, D_TargetFileNewName);
		  getchar();
          system("pause");
          system("cls");
          goto ProgramMainMenu;
       }
    }

  if(Load_User_Keyboard_Input == "3")
  {
  	return 0;
  }
  else
  {
   std :: cout << "User Input Error !" << endl;
   getchar();
   exit(1);
  }
}

#include "Main_2_By_Twlilght_Yujiang.hpp"
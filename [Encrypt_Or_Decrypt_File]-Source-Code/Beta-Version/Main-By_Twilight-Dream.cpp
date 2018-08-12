/****************************************************************************
Read Me - About This Source Code File

Chinese中文:
计算机语言类型: C++
程序文件名: Twilight-Dream-Of-Magic_File_Lock
程序平台类型: Windows 命令行控制台
程序实际作用: 文件对称式加密解密
版本: Beta 1.0
源代码修改时间: 2017-8-1
作者: Twilight-Dream-Of-Magic

English英文:
Chinese
Computer Language Type: C++
Program File Name: Twilight-Dream-Of-Magic_File_Lock
Program Platform Type: Windows Command Line Console
The actual role of the program: file symmetric encryption and decryption
Version: Beta 1.0
Source code modified by: 2017-8-1
Author: Twilight-Dream-Of-Magic
*****************************************************************************/

#include <iostream>
#include <stdio.h>   //标准输入输出函数
#include <stdlib.h>  //标准库函数
#include <string.h>  //字符串处理函数
#include <windows.h>

using namespace std;

//typedef unsigned char byte;

int RunEncryptFile(char *E_SourceFileName, char *E_KEY, char *E_KEY2, char *E_KEY3, char *E_TargetFileNewName);
int RunDecryptFile(char *D_SourceFileName, char *D_KEY, char *D_KEY2, char *D_KEY3, char *D_TargetFileNewName);

int main()
{
	string Load_User_Keyboard_Input;

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
	  char E_SourceFileName[4096],     // 加密的文件名
		   E_TargetFileNewName[4096];  // 加密后要保存的文件名

	   char E_KEY[128], //File (Encryption or Encrypted) key 文件加密密钥
			E_KEY2[128],
			E_KEY3[128];

	   printf("Please input >>> the source file name\n(Contains the directory name):\n");
	   printf("输入要加密的文件名,[C:\]不要输入空格(含路径)：\n");
	   scanf("%s", E_SourceFileName);

		printf("\n");
		printf("输入(长度小于128)密钥,不要输入空格：\n");  //密钥是用户自己定义的，(长度小于128)。可以随意给需要加密的文件添加密钥
		printf("Please input >>> the key,Do not enter spaces!\n(length less than 128):\n");
		scanf("%s", E_KEY);

		printf("\n");
		printf("输入(长度小于128)密钥2,不要输入空格：\n"); //密钥是用户自己定义的，(长度小于128)。可以随意给需要加密的文件添加密钥
		printf("Please input >>> the key2,Do not enter spaces!\n(length less than 128):\n");
		scanf("%s", E_KEY2);

		printf("\n");
		printf("输入(长度小于128)密钥3,不要输入空格：\n"); //密钥是用户自己定义的，(长度小于128)。可以随意给需要加密的文件添加密钥
		printf("Please input >>> the key3,Do not enter spaces!\n(length less than 128):\n");
		scanf("%s", E_KEY3);

	   printf("\n");
	   printf("Please input >>> the target file new name(Contains the directory name):\n");
	   printf("加密后的文件名,不要输入空格(含路径)：\n");  //给加密后的文件命名，并保存
	   scanf("%s",E_TargetFileNewName);

	   printf("Please wait, read and write in the file......\n");
	   printf("请等待，文件读写中......\n");
	   getchar();

		if(RunEncryptFile(E_SourceFileName, E_KEY, E_KEY2, E_KEY3, E_TargetFileNewName))
		{
			printf("恭喜你，文件[%s]加密成功，保存在[%s]。\n", E_SourceFileName, E_TargetFileNewName);
			printf("Congratulations, the file [%s] is encrypted successfully, saved in [%s]. \n", E_SourceFileName, E_TargetFileNewName);
			getchar();
			system("pause");
			return 0;
		}
	}
	if(Load_User_Keyboard_Input == "2")
	{
	   char D_SourceFileName[4096];     //源文件名
	   char D_TargetFileNewName[4096];  //目标文件新名称

		char D_KEY[128], //File (Decryption or Decrypted) key 文件解密密钥
			 D_KEY2[128],
			 D_KEY3[128];

		 printf("\n");
		 printf("Please input >>> the source file name\n(Contains the directory name):\n");
		 printf("输入要解密的文件名,[C:\]不要输入空格(含路径)：\n");
		 scanf("%s", D_SourceFileName);

		  printf("\n");
		  printf("输入(长度小于128)密钥,不要输入空格：\n");  //密钥是用户自己定义的，可以随意给需要解密的文件输入密钥
		  printf("Please input >>> the key3,Do not enter spaces!\n(length less than 128):\n");
		  scanf("%s", D_KEY);

		  printf("\n");
		  printf("输入(长度小于128)密钥2,不要输入空格：\n");
		  printf("Please input >>> the key2,Do not enter spaces!\n(length less than 128):\n");
		  scanf("%s", D_KEY2);

		  printf("\n");
		  printf("输入(长度小于128)密钥3,不要输入空格：\n");
		  printf("Please input >>> the key,Do not enter spaces!\n(length less than 128):\n");
		  scanf("%s", D_KEY3);

		printf("\n");
		printf("Please input >>> the target file new name(Contains the directory name):\n");
		printf("解密后的文件名,不要输入空格(含路径)：\n");  //给解密后的文件命名，并保存
		scanf("%s",D_TargetFileNewName);

		printf("Please wait, read and write in the file......\n");
		printf("请等待，文件读写中......\n");
		getchar();

		if(RunDecryptFile(D_SourceFileName, D_KEY, D_KEY2, D_KEY3, D_TargetFileNewName))
		{
			printf("恭喜你，文件[%s]解密成功，保存在[%s]。\n", D_SourceFileName, D_TargetFileNewName);
			printf("Congratulations, the file [%s] is decrypted successfully, saved in [%s]. \n", D_SourceFileName, D_TargetFileNewName);
			getchar();
			system("pause");
			return 0;
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

#include "Main-By_Twilight-Dream.hpp
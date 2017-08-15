/****************************************************************************
Read Me - About This Source Code File

Chinese中文:
计算机语言类型: C++
程序文件名: Twlilght_Yujiang_File_Lock
程序平台类型: Windows 命令行控制台
程序实际作用: 文件对称式加密解密
版本: Debugging 1.0
源代码修改时间: 2017-8-11
作者:Twlilght_Yujiang

English英文:
Chinese
Computer Language Type: C++
Program File Name: Twlilght_Yujiang_File_Lock
Program Platform Type: Windows Command Line Console
The actual role of the program: file symmetric encryption and decryption
Version: Debugging 1.0
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

int RunEncryptFile(char *E_SFN, char *E_KEY, char *E_KEY2, char *E_KEY3, char *E_TFN);
int RunDecryptFile(char *D_STN, char *D_KEY, char *D_KEY2, char *D_KEY3, char *D_TFN);

void DOSColorSet(int R,int G,int B)
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

       string E_SourceFileName,    // 加密的文件名
              E_TargetFileNewName; // 加密后要保存的文件名

       char* E_SFN;
       char* E_TFN;

      //char E_TargetFileLastNameOutput = (E_TargetFileNewName + ".TY_ENCRYPTED"); //最后保存的加密后文件名

        char E_KEY[128], //File (Encryption or Encrypted) key 文件加密密钥
             E_KEY2[128],
             E_KEY3[128];

         std :: cout << "Please input >>> the source file name.\n(Contains the directory name):" << endl;
         std :: cout << "输入要加密的文件名,[C:\](含路径)：" << endl;
         std :: cin >> E_SourceFileName;
         int String_Length = E_SourceFileName.length();
         E_SFN = (char *)malloc((String_Length+1)*sizeof(char));
         E_SourceFileName.copy(E_SFN,String_Length,0);

          std :: cout << "\n";
          std :: cout << "输入(长度小于128)密钥,不要输入空格：" << endl;  //密钥是用户自己定义的，(长度小于128)。可以随意给需要加密的文件添加密钥
          std :: cout << "Please input >>> the key,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> E_KEY;

          std :: cout << "\n";
		  std :: cout << "输入(长度小于128)密钥2,不要输入空格：" << endl; //密钥是用户自己定义的，(长度小于128)。可以随意给需要加密的文件添加密钥
          std :: cout << "Please input >>> the key2,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> E_KEY2;

          std :: cout << "\n";
          std :: cout << "输入(长度小于128)密钥3,不要输入空格：" << endl; //密钥是用户自己定义的，(长度小于128)。可以随意给需要加密的文件添加密钥
          std :: cout << "Please input >>> the key3,Do not enter spaces!\n(length less than 128):" << endl;
          std :: cin >> E_KEY3;

           std :: cout << "\n";
           std :: cout << "Please input >>> the target file new name(Contains the directory name):" << endl;
           std :: cout << "加密后的文件名(含路径)：" << endl;  //给加密后的文件命名，并保存
           std :: cin >> E_TargetFileNewName;
           int String_Length2 = E_TargetFileNewName.length();
           E_TFN = (char *)malloc((String_Length2+1)*sizeof(char));
           E_TargetFileNewName.copy(E_TFN,String_Length2,0);

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

      if(RunEncryptFile(E_SFN, E_KEY, E_KEY2, E_KEY3, E_TFN))
      {
         printf("恭喜你，文件[%s]加密成功，保存在[%s]。\n", E_SFN, E_TFN);
         printf("Congratulations, the file [%s] is encrypted successfully, saved in [%s]. \n", E_SFN, E_TFN);
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

   	   string D_SourceFileName,    //源文件名
              D_TargetFileNewName; //目标文件新名称

       char* D_SFN;
       char* D_TFN;

       //char D_TargetFileLastNameOutput = (D_TargetFileNewName - ".TY_ENCRYPTED"); //最后保存的解密后文件名

        char D_KEY[128], //File (Decryption or Decrypted) key 文件解密密钥
             D_KEY2[128],
             D_KEY3[128];

         std :: cout << "\n";
         std :: cout << "Please input >>> the source file name.\nDo not enter spaces!\n(Contains the directory name):" << endl;
		 std :: cout << "输入要解密的文件名,[C:\]不要输入空格(含路径)：" << endl;
         std :: cin >> D_SourceFileName;
         int String_Length3 = D_SourceFileName.length();
         D_SFN = (char *)malloc((String_Length3+1)*sizeof(char));
         D_SourceFileName.copy(D_SFN,String_Length3,0);

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
		   std :: cout << "Please input >>> the target file new name(Contains the directory name):" << endl;
           std :: cout << "解密后的文件名,不要输入空格(含路径)：" << endl;  //给解密后的文件命名，并保存
           std :: cin >> D_TargetFileNewName;
           int String_Length4 = D_TargetFileNewName.length();
           D_TFN = (char *)malloc((String_Length4+1)*sizeof(char));
           D_TargetFileNewName.copy(D_TFN,String_Length4,0);

           system("cls");

		    std :: cout << "Please wait, read and write in the file......" << endl;
	        std :: cout << "请等待，文件读写中......" << endl;
		    getchar();

       if(RunDecryptFile(D_SFN, D_KEY, D_KEY2, D_KEY3, D_TFN))
       {
          printf("恭喜你，文件[%s]解密成功，保存在[%s]。\n", D_SFN, D_TFN);
          printf("Congratulations, the file [%s] is decrypted successfully, saved in [%s]. \n", D_SFN, D_TFN);
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

	/*******************************************
    *                 加密文件
    *
    * E_SourceFileName    要加密的文件名
    * E_KEY               密钥
    * E_TargetFileNewName 加密后要保存的文件名
    *
    * @return  加密成功或失败的数字表示
    *
	* 0 = 加密失败
    * 1 = 加密成功
    ********************************************/

		int RunEncryptFile(char* E_SFN, char *E_KEY, char *E_KEY2, char *E_KEY3, char* E_TFN)
		{
            FILE *FilePointerSource, *FilePointerTarget; //要打开的文件的指针
            char buffer[1024];               //缓冲区，用于存放从文件读取的数据

		    int FileByteData,                //每次从文件中读取的字节数
                RTNOC,                       //循环次数
                KeyLength = strlen(E_KEY),   //密钥的长度
                KeyLength2 = strlen(E_KEY2),
                KeyLength3 = strlen(E_KEY3);

             FilePointerSource = fopen(E_SFN, "rb"); //以二进制方式读取文件
             if(FilePointerSource == NULL)
		     {
	     	   printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", E_SFN);
               printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", E_SFN);
			   getchar();
               return 0;
             }

		     FilePointerTarget = fopen(E_TFN, "wb"); //以二进制方式写入文件
             if(FilePointerTarget == NULL)
             {
           	   printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", FilePointerTarget);
               printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", FilePointerTarget);
			   getchar();
               return 0;
             }

/*加密算法开始*/
//依次运行三个大型加密模块
//Run three large encryption modules in turn

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                 buffer[RTNOC] += E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行递增运算
                 {
                 buffer[RTNOC] += E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行递增运算
                 {
                 buffer[RTNOC] += E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

/***********************************************************************************************************************************************************/

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                 buffer[RTNOC] += E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行递增运算
                 {
                 buffer[RTNOC] += E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行递增运算
                 {
                 buffer[RTNOC] += E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

/***********************************************************************************************************************************************************/

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                 buffer[RTNOC] += E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行递增运算
                 {
                 buffer[RTNOC] += E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY2进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行异或运算
                 {
                 buffer[RTNOC] ^= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行递增运算
                 {
                 buffer[RTNOC] += E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY3进行递乘运算
                 {
                 buffer[RTNOC] *= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

/*加密算法结束*/

		  fclose(FilePointerSource);
          fclose(FilePointerTarget);

          DeleteFile(E_SFN);

		return 1;
        }

        int RunDecryptFile(char* D_SFN, char *D_KEY, char *D_KEY2, char *D_KEY3, char* D_TFN)
		{
            FILE *FilePointerSource, *FilePointerTarget; //要打开的文件的指针
            char buffer[1024];               //缓冲区，用于存放从文件读取的数据

		    int FileByteData,                //每次从文件中读取的字节数
                RTNOC,                       //循环次数
                KeyLength = strlen(D_KEY),   //密钥的长度
                KeyLength2 = strlen(D_KEY2),
                KeyLength3 = strlen(D_KEY3);

             FilePointerSource = fopen(D_SFN, "rb"); //以二进制方式读取文件
             if(FilePointerSource == NULL)
		     {
	     	   printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", D_SFN);
               printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", D_SFN);
			   getchar();
               return 0;
             }

		     FilePointerTarget = fopen(D_TFN, "wb"); //以二进制方式写入文件
             if(FilePointerTarget == NULL)
             {
               printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", FilePointerTarget);
               printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", FilePointerTarget);
			   getchar();
               return 0;
             }

	/*******************************************
    *                 解密文件
    *
    * D_SourceFileName    要解密的文件名
    * D_KEY               密钥
    * D_TargetFileNewName 解密后要保存的文件名
    *
    * @return  解密成功或失败的数字表示
    *
	* 0 = 解密失败
    * 1 = 解密成功
    ********************************************/

/*解密算法开始*/
//依次运行大型三个解密模块
//Run three large decryption modules in turn

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

/***********************************************************************************************************************************************************/

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

/***********************************************************************************************************************************************************/

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

             while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY2进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行异或运算
                 {
                 buffer[RTNOC] ^= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行递减运算
                 {
                 buffer[RTNOC] -= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和D_KEY3进行递除运算
                 {
                 buffer[RTNOC] /= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 1, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

/*解密算法结束*/

          fclose(FilePointerSource);
          fclose(FilePointerTarget);

		return 1;
        }

//string New_PlainText; //新明文
//string New_CipherText; //新密文



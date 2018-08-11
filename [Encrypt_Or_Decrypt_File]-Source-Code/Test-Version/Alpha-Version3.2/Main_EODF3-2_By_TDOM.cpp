/****************************************************************************
Read Me - About This Source Code File

Chinese中文:
计算机语言类型: C++
程序文件名: File_Lock
程序平台类型: Windows 命令行控制台
程序实际作用: 对称式加密和对称式解密至文件
版本: Alpha 3.2
源代码修改时间: 2018-8-08
作者: Twilight-Dream-Of-Magic

English英文:
Computer Language Type: C ++
Program File Name: File_Lock
Program Platform Type: Windows Command Line Console
The actual role of the program: symmetric encryption and decryption to file
Version: Alpha 3.2
Source code modified by: 2018-8-08
Author: Twilight-Dream-Of-Magic
*****************************************************************************/

#include "EODF3-2_By_TDOM.hpp"

using namespace std;

//Variable argc is Argument counter
//Variable argv is Argument vector

int main (int argc, char *argv[])
{

  string ShowLanguage;

  if (argc == 3 && strcmp(argv[1],"-help") == 0 || argc == 2 && strcmp(argv[1],"--display-help") == 0)
  {
    if(strcmp(argv[2],"") == 0 || strcmp(argv[2]," ") == 0)
    {
      cout << "" << endl;
      cout << "Error: Language for command help manual not set !" << endl;
      cout << "错误：未设置命令帮助手册的语言 !" << endl;
      cout << "" << endl;
      return 0;
    }
    if(strcmp(argv[2],"?") == 0)
    {
      cout << "" << endl;
      cout << "==============================" << endl;
      cout << "+ Help manual language list  +" << endl;
      cout << "==============================" << endl;
      cout << "+  en-US = American English  +" << endl;
      cout << "+ zh-CN = Simplified Chinese +" << endl;
      cout << "==============================" << endl;
      cout << "" << endl;
      return 0;
    }
    if(strcmp(argv[2],"en-US") == 0)
    {
      ShowLanguage = argv[2];
      DisplayHelpManual(ShowLanguage);
    }
    if(strcmp(argv[2],"zh-CN") == 0)
    {
      ShowLanguage = argv[2];
      DisplayHelpManual(ShowLanguage);
    }
  }
  if (argc == 2 && strcmp(argv[1],"-cui") == 0 || argc == 3 && strcmp(argv[1],"--user-interface") == 0 && strcmp(argv[2],"command") == 0)
  {
    CTUI();
  }
  if (argc == 2 && strcmp(argv[1],"-gui") == 0 || argc == 3 && strcmp(argv[1],"--user-interface") == 0 && strcmp(argv[2],"graphical") == 0)
  {
    GWUI();
  }
  if (argc == 14 && strcmp(argv[1],"-e") == 0 && strcmp(argv[2],"-sf") == 0 && strcmp(argv[4],"-k") == 0 && strcmp(argv[6],"-k2") == 0 && strcmp(argv[8],"-k3") == 0 && strcmp(argv[10],"-k4") == 0 && strcmp(argv[12],"-tf") == 0)
  {
    if (!access(".\\File-Key-Record-Log\\", 0))
    {
      cout << "Building and Loading Folder." << endl;
    }
    else
    {
      system("@Mkdir .\\File-Key-Record-Log\\");
    }

    cout << "正在记录并导出，本次用于文件加密，4个密钥字符串......" << endl;
    cout << "Is being recorded and exported, this time for file encryption, 4 key string......" << endl;

    time_t time_value = time(0);
    char now_time_char[64];
    strftime(now_time_char, sizeof(now_time_char), "%Y-%m-%d %X %A",localtime(&time_value));

    ofstream KeyStringSaveToFile;

    KeyStringSaveToFile.open(".\\File-Key-Record-Log\\ENCRYPTION-DECRYPTION-PASSWORD.KEY.TXT");

    KeyStringSaveToFile << "Log Time:" << " " << now_time_char << "\n" << endl;
    KeyStringSaveToFile << "Twilight-Dream-Of-Magic File Lock Password [Key String] Save\n" << endl;
    KeyStringSaveToFile << "\n" << endl;
    KeyStringSaveToFile << "Source Input File Name and Path: " << argv[3] << "\n" << endl;
    KeyStringSaveToFile << "EncryptFile: New Output Target File Name and Path: " << argv[13] << "\n" << endl;
    KeyStringSaveToFile << "Key string1 [Password1]: " << E_KEY << "\n" << endl;
    KeyStringSaveToFile << "Key string2 [Password2]: " << E_KEY2 << "\n" << endl;
    KeyStringSaveToFile << "Key string3 [Password3]: " << E_KEY3 << "\n" << endl;
    KeyStringSaveToFile << "Key string4 [Password4]: " << E_KEY4 << "\n" << endl;
    KeyStringSaveToFile << "<******************************************************************************************>" << "\n" << endl;

    KeyStringSaveToFile.close();

    if(RunEncryptFile(argv[3],argv[5],argv[7],argv[9],argv[11],argv[13]))
    {
      printf("恭喜你，文件[%s]加密成功，保存在[%s]。\n", argv[3], argv[13]);
      printf("Congratulations, the file [%s] is encrypted successfully, saved in [%s]. \n", argv[3], argv[13]);
      getchar();
      system("Pause");
      system("Cls");
    }
    else
    {
      cout << "An unknown error occurred while the program was running the core child process function (note: using cryptographic methods to apply data to the file)." << endl;
      cout << "程序正在运行核心的子进程函数（注释： 使用密码学的方法，将数据应用到文件）时，发生了未知错误。" << endl;
      exit(1);
    }

  }
  if (argc == 14 && strcmp(argv[1],"--encrypt") == 0 && strcmp(argv[2],"--source-file") == 0 && strcmp(argv[4],"--key") == 0 && strcmp(argv[6],"--key2") == 0 && strcmp(argv[8],"--key3") == 0 && strcmp(argv[10],"--key4") == 0 && strcmp(argv[12],"--target-file") == 0)
  {
    if (!access(".\\File-Key-Record-Log\\", 0))
    {
      cout << "Building and Loading Folder." << endl;
    }
    else
    {
      system("@Mkdir .\\File-Key-Record-Log\\");
    }

    cout << "正在记录并导出，本次用于文件加密，4个密钥字符串......" << endl;
    cout << "Is being recorded and exported, this time for file encryption, 4 key string......" << endl;

    time_t time_value = time(0);
    char now_time_char[64];
    strftime(now_time_char, sizeof(now_time_char), "%Y-%m-%d %X %A",localtime(&time_value));

    ofstream KeyStringSaveToFile;

    KeyStringSaveToFile.open(".\\File-Key-Record-Log\\ENCRYPTION-DECRYPTION-PASSWORD.KEY.TXT");

    KeyStringSaveToFile << "<******************************************************************************************>" << "\n" << endl;
    KeyStringSaveToFile << "Log Time:" << " " << now_time_char << "\n" << endl;
    KeyStringSaveToFile << "Twilight-Dream-Of-Magic File Lock Password [Key String] Save\n" << endl;
    KeyStringSaveToFile << "\n" << endl;
    KeyStringSaveToFile << "Source Input File Name and Path: " << argv[3] << "\n" << endl;
    KeyStringSaveToFile << "EncryptFile: New Output Target File Name and Path: " << argv[13] << "\n" << endl;
    KeyStringSaveToFile << "Key string1 [Password1]: " << E_KEY << "\n" << endl;
    KeyStringSaveToFile << "Key string2 [Password2]: " << E_KEY2 << "\n" << endl;
    KeyStringSaveToFile << "Key string3 [Password3]: " << E_KEY3 << "\n" << endl;
    KeyStringSaveToFile << "Key string4 [Password4]: " << E_KEY4 << "\n" << endl;
    KeyStringSaveToFile << "<******************************************************************************************>" << "\n" << endl;
    KeyStringSaveToFile << "\n" << endl;

    KeyStringSaveToFile.close();

    if(RunEncryptFile(argv[3],argv[5],argv[7],argv[9],argv[11],argv[13]))
    {
      printf("恭喜你，文件[%s]加密成功，保存在[%s]。\n", argv[3], argv[13]);
      printf("Congratulations, the file [%s] is encrypted successfully, saved in [%s]. \n", argv[3], argv[13]);
      getchar();
      system("Pause");
      system("Cls");
    }
    else
    {
      cout << "An unknown error occurred while the program was running the core child process function (note: using cryptographic methods to apply data to the file)." << endl;
      cout << "程序正在运行核心的子进程函数（注释： 使用密码学的方法，将数据应用到文件）时，发生了未知错误。" << endl;
      exit(1);
    }

  }
  if (argc == 14 && strcmp(argv[1],"-d") == 0 && strcmp(argv[2],"-sf") == 0 && strcmp(argv[4],"-k") == 0 && strcmp(argv[6],"-k2") == 0 && strcmp(argv[8],"-k3") == 0 && strcmp(argv[10],"-k4") == 0 && strcmp(argv[12],"-tf") == 0)
  {

    if(RunDecryptFile(argv[3],argv[5],argv[7],argv[9],argv[11],argv[13]))
    {
      printf("恭喜你，文件[%s]解密成功，保存在[%s]。\n", argv[3], argv[13]);
      printf("Congratulations, the file [%s] is decrypted successfully, saved in [%s]. \n", argv[3], argv[13]);
      getchar();
      system("Pause");
      system("Cls");
    }
    else
    {
      cout << "An unknown error occurred while the program was running the core child process function (note: using cryptographic methods to apply data to the file)." << endl;
      cout << "程序正在运行核心的子进程函数（注释： 使用密码学的方法，将数据应用到文件）时，发生了未知错误。" << endl;
      exit(1);
    }

  }
  if (argc == 14 && strcmp(argv[1],"--decrypt") == 0 && strcmp(argv[2],"--source-file") == 0 && strcmp(argv[4],"--key") == 0 && strcmp(argv[6],"--key2") == 0 && strcmp(argv[8],"--key3") == 0 && strcmp(argv[10],"--key4") == 0 && strcmp(argv[12],"--target-file") == 0)
  {

    if(RunDecryptFile(argv[3],argv[5],argv[7],argv[9],argv[11],argv[13]))
    {
      printf("恭喜你，文件[%s]解密成功，保存在[%s]。\n", argv[3], argv[13]);
      printf("Congratulations, the file [%s] is decrypted successfully, saved in [%s]. \n", argv[3], argv[13]);
      getchar();
      system("Pause");
      system("Cls");
    }
    else
    {
      cout << "An unknown error occurred while the program was running the core child process function (note: using cryptographic methods to apply data to the file)." << endl;
      cout << "程序正在运行核心的子进程函数（注释： 使用密码学的方法，将数据应用到文件）时，发生了未知错误。" << endl;
      exit(1);
    }

  }
  else if (argc == 1)
  {
    cout << "" << endl;
    cout << "Your method of using this program is incorrect, please use the" << " -help " << "command to view the manual." << endl;
    cout << "Since the use of this [-help] command parameter requires the next command parameter to set the display language, use [-help ?] to check the supported language." << endl;
    cout << "" << endl;
    cout << "你的使用本程序的方法不正确，请使用" << " -help " << "命令参数来查看手册。" << endl;
    cout << "这个[-help] 命令参数的使用方法，因为需要下一个命令参数来设置显示语言，所以使用[-help ?]，来检查支持的语言。" << endl;
    cout << "" << endl;
    system("Pause");
    return 0;
  }
  return 0;
}

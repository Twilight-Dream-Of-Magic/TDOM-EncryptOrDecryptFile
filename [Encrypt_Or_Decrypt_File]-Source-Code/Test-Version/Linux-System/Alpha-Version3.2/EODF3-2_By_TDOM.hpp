/* File Cipher The Return Enum Status For Worked */
enum
{
   SUCCESSFUL, //Function return value is 0
   FAILED, //Function return value is 1
   RUNTIME_ERROR, //Function return value is 2
   THROW_EXCEPTED //Function return value is 3
};

#include "Multiple-Cryptography-Algorithm-To-File.hpp"
#include "Command-Text_User-Interface.hpp"
#include "Graphical-Window_User-Interface.hpp"

void KeyString_SaveToFile(auto VariableSF, auto VariableK, auto VariableK2, auto VariableK3, auto VariableK4, auto VariableTF)
{
   if (!access(".\\File-Key-Record-Log\\", 0))
    {
      cout << "Building and Loading Folder." << endl;
    }
    else
    {
      system("mkdir .\\File-Key-Record-Log\\");
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
    KeyStringSaveToFile << "Source Input File Name and Path: " << VariableSF << "\n" << endl;
    KeyStringSaveToFile << "EncryptFile: New Output Target File Name and Path: " << VariableTF << "\n" << endl;
    KeyStringSaveToFile << "Key string1 [Password1]: " << VariableK << "\n" << endl;
    KeyStringSaveToFile << "Key string2 [Password2]: " << VariableK2 << "\n" << endl;
    KeyStringSaveToFile << "Key string3 [Password3]: " << VariableK3<< "\n" << endl;
    KeyStringSaveToFile << "Key string4 [Password4]: " << VariableK4 << "\n" << endl;
    KeyStringSaveToFile << "<******************************************************************************************>" << "\n" << endl;

    KeyStringSaveToFile.close();
}

void CallCustomEncryptToFile(auto VariableSF, auto VariableK, auto VariableK2, auto VariableK3, auto VariableK4, auto VariableTF) //const char* ESF, char* EK[], char* EK2[], char* EK3[], char* EK4[], const char* ETF
{
   KeyString_SaveToFile(VariableSF, VariableK, VariableK2, VariableK3, VariableK4, VariableTF);
   
   int CIPHER_RETURN_STATUS = RunEncryptFile(VariableSF, VariableK, VariableK2, VariableK3, VariableK4, VariableTF);
   
   if (CIPHER_RETURN_STATUS == SUCCESSFUL)
    {
      printf("恭喜你，文件[%s]加密成功，保存在[%s]。\n", VariableSF, VariableTF);
      printf("Congratulations, the file [%s] is encrypted successfully, saved in [%s]. \n", VariableSF, VariableTF);
      getchar();
      system("sleep 5s");
      system("clear");
    }
    if(CIPHER_RETURN_STATUS == FAILED)
    {
       cout << "An unknown error occurred while the program was running the core child process function (note: using cryptographic methods to apply data to the file)." << endl;
       cout << "程序正在运行核心的子进程函数（注释： 使用密码学的方法，将数据应用到文件）时，发生了未知错误。" << endl;
       exit(1);
    }
    if(CIPHER_RETURN_STATUS == RUNTIME_ERROR)
    {
       cout << "Function Runtime Has Been Error" << endl; 
    }
    else if(CIPHER_RETURN_STATUS == THROW_EXCEPTED)
    {
       cout << "Checked And Throw Exception For Function Working " << endl;
    }

}

void CallCustomDecryptToFile(auto VariableSF, auto VariableK, auto VariableK2, auto VariableK3, auto VariableK4, auto VariableTF) //const char* DSF, char* DK[], char* DK2[], char* DK3[], char* DK4[], const char* DTF
{
    int CIPHER_RETURN_STATUS = RunDecryptFile(VariableSF, VariableK, VariableK2, VariableK3, VariableK4, VariableTF);

    if (CIPHER_RETURN_STATUS == SUCCESSFUL)
    {
      printf("恭喜你，文件[%s]解密成功，保存在[%s]。\n", VariableSF, VariableTF);
      printf("Congratulations, the file [%s] is decrypted successfully, saved in [%s]. \n", VariableSF, VariableTF);
      getchar();
      system("sleep 5s");
      system("clear");
    }
    if(CIPHER_RETURN_STATUS == FAILED)
    {
       cout << "An unknown error occurred while the program was running the core child process function (note: using cryptographic methods to apply data to the file)." << endl;
       cout << "程序正在运行核心的子进程函数（注释： 使用密码学的方法，将数据应用到文件）时，发生了未知错误。" << endl;
       exit(1);
    }
    if(CIPHER_RETURN_STATUS == RUNTIME_ERROR)
    {
       cout << "Function Runtime Has Been Error" << endl; 
    }
    else if(CIPHER_RETURN_STATUS == THROW_EXCEPTED)
    {
       cout << "Checked And Throw Exception For Function Working " << endl;
    }

}

void DisplayHelpManual(string ShowLanguage)
{
  if (ShowLanguage == "en-US")
  {
    cout << "" << endl;
    cout << "########################################################################################################################" << endl;
    cout << "*                                                     Help Manual                                                      *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                        Functional description: Display command help manual from this program                         *" << endl;
    cout << "*                                   Command parameter: [-help] or [--display-help].                                    *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                                            Functional group description:                                             *" << endl;
    cout << "*                                   ▲ About the user interface using this program. ▲                                   *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                                   Using the user interface: (Command Console Text)                                   *" << endl;
    cout << "*                               Command parameter: [-cui] or [--user-interface command]                                *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                                     Using the user interface: (Graphical Window)                                     *" << endl;
    cout << "*                              Command parameter: [-gui] or [--user-interface graphical]                               *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                                            Function group 2 description:                                             *" << endl;
    cout << "*                                  ▲ About the cryptography method in this program, ▲                                  *" << endl;
    cout << "*                                 ▲ If the target file is processed by this program. ▲                                 *" << endl;
    cout << "*                           ▲ Then, the contents of the file are protected and converted. ▲                            *" << endl;
    cout << "*         ▲ After that, the user needs to modify the operation of the file, such as relocking and unlocking. ▲         *" << endl;
    cout << "*                                 ▲ SPAF = ( a secure password to access the file ) ▲                                  *" << endl;
    cout << "*    ▲ These requests to the target file require the correct input (SPAF) before the conversion can be restored. ▲     *" << endl;
    cout << "*              ▲ So that the original contents of the file cannot be obtained by the third party...... ▲               *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                           Use the command line to interact: (Method: Encrypt to your file)                           *" << endl;
    cout << "*                                        Command parameter: [-e] or [--encrypt]                                        *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                 Command parameter: [-sf file_path+file_name] or [--source-file file_path+file_name]                  *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                                 Command parameter: [-k password] or [--key password]                                 *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                               Command parameter: [-k2 password2] or [--key2 password2]                               *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                               Command parameter: [-k3 password3] or [--key3 password3]                               *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                               Command parameter: [-k4 password4] or [--key4 password4]                               *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                 Command parameter: [-tf file_path+file_name] or [--target-file file_path+file_name]                  *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "*                           Use the command line to interact: (Method: Decrypt to your file)                           *" << endl;
    cout << "*                                        Command parameter: [-d] or [--decrypt]                                        *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                 Command parameter: [-sf file_path+file_name] or [--source-file file_path+file_name]                  *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                                 Command parameter: [-k password] or [--key password]                                 *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                               Command parameter: [-k2 password2] or [--key2 password2]                               *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                               Command parameter: [-k3 password3] or [--key3 password3]                               *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                               Command parameter: [-k4 password4] or [--key4 password4]                               *" << endl;
    cout << "*                                            ▼ And next command parameter ▼                                            *" << endl;
    cout << "*                 Command parameter: [-tf file_path+file_name] or [--target-file file_path+file_name]                  *" << endl;
    cout << "*                                                                                                                      *" << endl;
    cout << "########################################################################################################################" << endl;
    cout << "" << endl;
    return;
  }
  if(ShowLanguage == "zh-CN")
  {
    cout << "" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "+                                  帮助手册                                   +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                           功能描述：从该程序显示命令帮助手册。                            +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                 功能组描述：                                  +" << endl;
    cout << "+                            ▲ 关于使用此程序的用户界面。 ▲                            +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                            使用用户界面:  命令控制台文本                             +" << endl;
    cout << "+                命令参数: [-cui] 或 [--user-interface command]                +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                              使用用户界面:  图形窗口                              +" << endl;
    cout << "+               命令参数: [-gui] 或 [--user-interface graphical]               +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                 功能组2描述：                                 +" << endl;
    cout << "+                                   ▲ 关于此程序中的加密方法 ▲                       +" << endl;
    cout << "+                          ▲ 假如目标文件，被这个程序处理完成。 ▲                          +" << endl;
    cout << "+                           ▲ 然后，文件内容，被保护和转换。 ▲                           +" << endl;
    cout << "+                      ▲ 之后用户需要修改文件的操作，比如重新锁定和解锁。 ▲                       +" << endl;
    cout << "+              ▲ 这些应用于目标文件的请求，需要输入正确的(访问文件的安全密码)，才可以还原转换。 ▲               +" << endl;
    cout << "+                         ▲ 可以使第三方无法获取文件的原始内容...... ▲                     +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                  使用命令行进行交互                              +" << endl;
    cout << "+                                   执行功能 -> 加密到你的文件                       +" << endl;
    cout << "+                         命令参数: [-e] 或 [--encrypt]                        +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+              命令参数: [-sf 文件路径+文件名称] 或 [--source-file 文件路径+文件名称]          +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+                          命令参数: [-k 密码] 或 [--key 密码]                     +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+                          命令参数: [-k2 密码2] 或 [--key2 密码2]                 +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+                          命令参数: [-k3 密码3] 或 [--key3 密码3]                 +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+                          命令参数: [-k4 密码4] 或 [--key4 密码4]                 +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+             命令参数: [-tf 文件路径+文件名称] 或 [--target-file 文件路径+文件名称]           +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "+                                  使用命令行进行交互                              +" << endl;
    cout << "+                                   执行功能: 解密到你的文件                         +" << endl;
    cout << "+                         命令参数: [-d] 或 [--decrypt]                        +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+              命令参数: [-sf 文件路径+文件名称] 或 [--source-file 文件路径+文件名称]          +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+                          命令参数: [-k 密码] 或 [--key 密码]                     +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+                          命令参数: [-k2 密码2] 或 [--key2 密码2]                 +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+                          命令参数: [-k3 密码3] 或 [--key3 密码3]                 +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+                          命令参数: [-k4 密码4] 或 [--key4 密码4]                 +" << endl;
    cout << "+                              ▼ 然后下一个命令参数 ▼                              +" << endl;
    cout << "+            命令参数: [-tf 文件路径+文件名称] 或 [--target-file 文件路径+文件名称]            +" << endl;
    cout << "+                                                                         +" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "" << endl;
    return;
  }
}

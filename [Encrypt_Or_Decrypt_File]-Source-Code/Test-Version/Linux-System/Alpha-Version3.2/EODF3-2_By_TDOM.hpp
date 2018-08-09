#include "Multiple-Cryptography-Algorithm-To-File.hpp"
#include "Command-Text_User-Interface.hpp"
#include "Graphical-Window_User-Interface.hpp"

using namespace std;

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

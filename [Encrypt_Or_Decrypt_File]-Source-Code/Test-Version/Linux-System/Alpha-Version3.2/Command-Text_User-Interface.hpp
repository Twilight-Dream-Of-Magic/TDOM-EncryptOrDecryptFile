#include "Support-Libary.hpp"
#include "My-Linux-Function.hpp"

using namespace std;

//typedef unsigned char byte;

/****************************************************************************************************************************************************************/

void CleanFileFromThisWorkspace()
{
  string DeleteFileName = ".//SourceFileName.CONFIGFILE";
  string DeleteFileName2 = ".//SourceFileMainName.CONFIGFILE";
  string DeleteFileName3 = ".//SourceFileExtendedName.CONFIGFILE";

	remove(DeleteFileName.c_str());
	remove(DeleteFileName2.c_str());
	remove(DeleteFileName3.c_str());

	system("rm --force --verbose .//File-Key-Record-Log//*.*");
	system("rm --force --verbose .//WorkPath//*.*");
	system("rm --force --verbose .//WorkPath//Encrypt//*.*");
	system("rm --force --verbose .//WorkPath//Encrypt//InputFile//*.*");
	system("rm --force --verbose .//WorkPath//Encrypt//OutputFile//*.*");
	system("rm --force --verbose .//WorkPath//Decrypt//*.*");
	system("rm --force --verbose .//WorkPath//Decrypt//InputFile//*.*");
	system("rm --force --verbose .//WorkPath//Decrypt//OutputFile//*.*");

  string DeleteDirectoryName = ".//File-Key-Record-Log//";
  string DeleteDirectoryName2 = ".//WorkPath//Encrypt//OutputFile//";
  string DeleteDirectoryName3 = ".//WorkPath//Encrypt//InputFile//";
  string DeleteDirectoryName4 = ".//WorkPath//Encrypt//";
  string DeleteDirectoryName5 = ".//WorkPath//Decrypt//OutputFile//";
  string DeleteDirectoryName6 = ".//WorkPath//Decrypt//InputFile//";
  string DeleteDirectoryName7 = ".//WorkPath//Decrypt//";
  string DeleteDirectoryName8 = ".//WorkPath//";

	rmdir(DeleteDirectoryName.c_str());
	rmdir(DeleteDirectoryName2.c_str());
	rmdir(DeleteDirectoryName3.c_str());
	rmdir(DeleteDirectoryName4.c_str());
	rmdir(DeleteDirectoryName5.c_str());
	rmdir(DeleteDirectoryName6.c_str());
	rmdir(DeleteDirectoryName7.c_str());
	rmdir(DeleteDirectoryName8.c_str());

	system("clear");
}

int Set_CTUI_Error(int This_Error_Code)
{
  if(This_Error_Code != 0 && This_Error_Code > 0)
  {
    if(This_Error_Code == 1)
    {
      cout << "加载配置文件时，出现了未知错误并结束" << endl;
      cout << "When the configuration file is loaded, an unknown error has occurred and ends" << endl;
      system("sleep 5s");
      system("exit 0");
    }
  }
  else
  {
    This_Error_Code = 0;
    if (This_Error_Code <= 0)
    {
      cout << "这个程序，没有错误发生" << endl;
      cout << "This program, no error occurred" << endl;
      system("sleep 5s");
      system("exit 0");
    }
    else if (This_Error_Code < 0)
    {
      cout << "这个程序，有未知错误发生了" << endl;
      cout << "This program has an unknown error occurred" << endl;
      system("sleep 5s");
      system("exit 0");
    }
  }
}

string E_IF_PATH = ".//WorkPath//Encrypt//InputFile//", //加密之前，文件的路径 Before encrypting the path of the file
E_OF_PATH = ".//WorkPath//Encrypt//OutputFile//"; //加密之后，文件的路径 After encrypting the path of the file

string D_IF_PATH = ".//WorkPath//Decrypt//InputFile//", //解密之前，文件的路径 Before decrypting the path of the file
D_OF_PATH = ".//WorkPath//Decrypt//OutputFile//"; //解密之后，文件的路径 After decrypting the path of the file

int CTUI()
{
 ProgramMainMenu:

	string Load_User_Keyboard_Input;
  	int This_Error_Code;

	system("echo -e '\033[45m'"); //Linux Console Backgroud Color: Purple
	system("echo -e '\033[0;33m'"); //Linux Console Foregroud Color: Yellow

	system("echo -e '\033[45;33m'");

	system("clear");

	cout << "----------------------------------------" << endl;
	cout << "Enter 1 Encrypt File" << endl;
	cout << "1.加密文件\n" << endl;
	cout << "Enter 2 Decrypt File" << endl;
	cout << "2.解密文件\n" << endl;
	cout << "Enter 3 Use The Information Manual" << endl;
	cout << "3.使用信息说明手册\n" << endl;
	cout << "Enter 4 Clean Up The Workspace[To Restore The Initial State]" << endl;
	cout << "4.清理工作空间[恢复初始状态]\n" << endl;
	cout << "Enter 5 Exit Program" << endl;
	cout << "5.退出程序\n" << endl;
	cout << "----------------------------------------" << endl;
	cout << "System:Input And Output/Enter>";

	std::cin >> Load_User_Keyboard_Input;
	getchar();

/****************************************************************************************************************************************************************/

	if (Load_User_Keyboard_Input == "1")
	{
		system("echo -e '\033[44m'"); //Linux Console Backgroud Color: Blue
		system("echo -e '\033[0;92m'"); //Linux Console Foregroud Color: Light Green

		system("echo -e '\033[44;92m'");

		system("clear");

		if (!access(".//WorkPath//Encrypt//InputFile//", 0))
		{
			cout << "Building and Loading Folder 20%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//WorkPath//Encrypt//InputFile//");
		}

		if (!access(".//WorkPath//Encrypt//OutputFile//", 0))
		{
			cout << "Building and Loading Folder 40%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//WorkPath//Encrypt//OutputFile//");
		}

		if (!access(".//WorkPath//Decrypt//InputFile//", 0))
		{
			cout << "Building and Loading Folder 60%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//WorkPath//Decrypt//InputFile//");
		}

		if (!access(".//WorkPath//Decrypt//OutputFile//", 0))
		{
			cout << "Building and Loading Folder 80%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//WorkPath//Decrypt//OutputFile//");
		}

		if (!access(".//File-Key-Record-Log//", 0))
		{
			cout << "Building and Loading Folder 100%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//File-Key-Record-Log//");
		}

		system("clear");

		ConsoleTableColorSet(0, 0, 0);
		cout << "Please input >>> the source file name + file extension name.\nDo not enter spaces!\n:" << endl;
		cout << "输入要加密的文件名+文件扩展名，不要输入空格!" << endl;
		std::cin >> E_SourceFileName;

		cout << "Please input >>> the source file name, not the file extension name!\nDo not enter spaces!\n:" << endl;
		cout << "输入要加密的文件主要名，不是文件扩展名！不要输入空格!" << endl;
		std::cin >> E_SourceFileMainName;

		cout << "Please input >>> the file extension name.\nDo not enter spaces!\n:" << endl;
		cout << "输入要加密的文件扩展名，不要输入空格!" << endl;
		std::cin >> E_SourceFileExtendedName;
		system("clear");

		cout << "正在记录并导出，源文件名称......\n[警告!]在进行本次操作后，请下次选择同样名称的加密文件，进行解密文件操作!\n否则，在那之前，请立即禁止使用加密文件功能！" << endl;
		cout << "Recording and exporting, source file name......\n[Warning!]After doing this operation, please select the same name next time the encrypted file, decrypt the file operation!\nOtherwise, before that, please immediately disable the use of encrypted file function" << endl;
		cout << "您是否接受这个协议?[键盘Enter继续] 或者 [关闭程序]......" << endl;
		cout << "Whether you accept this agreement?[Keyboard Enter Continue] Or [Close this program]......" << endl;

		system("sleep 5s");
		system("clear");

		ConsoleTableColorUnset();

		ofstream SourceFileNameTemporarySave;

		SourceFileNameTemporarySave.open(".//SourceFileName.CONFIGFILE");
		SourceFileNameTemporarySave << E_SourceFileName << endl;
		SourceFileNameTemporarySave.close();

		SourceFileNameTemporarySave.open(".//SourceFileMainName.CONFIGFILE");
		SourceFileNameTemporarySave << E_SourceFileMainName << endl;
		SourceFileNameTemporarySave.close();

		SourceFileNameTemporarySave.open(".//SourceFileExtendedName.CONFIGFILE");
		SourceFileNameTemporarySave << E_SourceFileExtendedName << endl;
		SourceFileNameTemporarySave.close();

		//加密密钥码是用户自己定义的，(长度小于256)。可以任意的给一个需要加密的文件添加一个或多个加密密钥码
		//Encryption key code is user-defined, (length less than 256). You can optionally add one or more encryption keys to the one files you want to encrypt
	E_KEY_LENTH_IS_INCORRECT:
		int E_KEY_CODE_MAX_LENGTH = 256;

		ConsoleTableColorSet(0, 0, 1);
		cout << "\n";
		cout << "输入(长度小于256)密钥,不要输入空格!" << endl;
		cout << "Please input >>> the key,Do not enter spaces!\n(length less than 256):" << endl;
		std::cin >> E_KEY;
		if(strlen(E_KEY) > E_KEY_CODE_MAX_LENGTH)
		{
		    memset(E_KEY,NULL,sizeof(E_KEY)); //Reset This Variable The Value (NULL = 0)
			cout << "加密密钥的长度，已经超过256位字符。 请重新输入所有加密密钥！" << endl;
			cout << "Encryption key length, has more than 256 characters. Please re-enter the all encryption key!" << endl;
			system("sleep 5s");
			goto E_KEY_LENTH_IS_INCORRECT;
		}

		ConsoleTableColorSet(0, 1, 0);
		cout << "\n";
		cout << "输入(长度小于256)密钥2,不要输入空格!" << endl;
		cout << "Please input >>> the key2,Do not enter spaces!\n(length less than 256):" << endl;
		std::cin >> E_KEY2;
		if(strlen(E_KEY2) > E_KEY_CODE_MAX_LENGTH)
		{
		    memset(E_KEY2,NULL,sizeof(E_KEY2)); //Reset This Variable The Value (NULL = 0)
			cout << "加密密钥2的长度，已经超过256位字符。 请重新输入所有加密密钥！" << endl;
			cout << "Encryption key2 length, has more than 256 characters. Please re-enter the all encryption key!" << endl;
			system("sleep 5s");
			goto E_KEY_LENTH_IS_INCORRECT;
		}

		ConsoleTableColorSet(0, 1, 1);
		cout << "\n";
		cout << "输入(长度小于256)密钥3,不要输入空格!" << endl;
		cout << "Please input >>> the key3,Do not enter spaces!\n(length less than 256):" << endl;
		std::cin >> E_KEY3;
		if(strlen(E_KEY3) > E_KEY_CODE_MAX_LENGTH)
		{
		    memset(E_KEY3,NULL,sizeof(E_KEY3)); //Reset This Variable The Value (NULL = 0)
			cout << "加密密钥3的长度，已经超过256位字符。 请重新输入所有加密密钥！" << endl;
			cout << "Encryption key3 length, has more than 256 characters. Please re-enter the all encryption key!" << endl;
			system("sleep 5s");
			goto E_KEY_LENTH_IS_INCORRECT;
		}

		ConsoleTableColorSet(1, 0, 0);
		cout << "\n";
		cout << "输入(长度小于256)密钥4,不要输入空格!" << endl;
		cout << "Please input >>> the key3,Do not enter spaces!\n(length less than 256):" << endl;
		std::cin >> E_KEY4;
		if(strlen(E_KEY4) > E_KEY_CODE_MAX_LENGTH)
		{
		    memset(E_KEY4,NULL,sizeof(E_KEY4)); //Reset This Variable The Value (NULL = 0)
			cout << "加密密钥4的长度，已经超过256位字符。 请重新输入所有加密密钥！" << endl;
			cout << "Encryption key4 length, has more than 256 characters. Please re-enter the all encryption key!" << endl;
			system("sleep 5s");
			goto E_KEY_LENTH_IS_INCORRECT;
		}

		ConsoleTableColorSet(1, 0, 1);
		cout << "\n";
		cout << "Please output >>> file extension name.\nDo not enter spaces!\n[.TSMY-ENCRYPTED]:" << endl;
		cout << "输出文件扩展名,不要输入空格[.TSMY-ENCRYPTED]：" << endl; //给加密后的文件输出文件扩展名，并保存 Export the file extension to the encrypted file and save it
		std::cin >> E_TargetFileExtendedName;
		if (E_TargetFileExtendedName == " ")
		{
			string E_TargetFileAddExtendedName = ".TSMY-ENCRYPTED";
			E_TargetFileExtendedName = E_TargetFileAddExtendedName;
		}

		system("clear");

		system("echo -e '\033[44m'"); //Linux Console Backgroud Color: Blue
		system("echo -e '\033[0;92m'"); //Linux Console Foregroud Color: Light Green

		system("echo -e '\033[44;92m'");

		string E_SourceFileStringPath = E_IF_PATH + E_SourceFileName;
		string E_TargetFileStringPath = E_OF_PATH + E_SourceFileName + E_TargetFileExtendedName;

		const char *E_SourceFileCharPath = E_SourceFileStringPath.c_str();
		const char *E_TargetFileCharPath = E_TargetFileStringPath.c_str();

		/*char *E_SourceFileLastNameOutput; //最后读写的文件名
		strcpy(E_SourceFileLastNameOutput,E_SourceFileCharPath);
		char *E_TargetFileLastNameOutput; //最后保存的加密后文件名
		strcpy(E_TargetFileLastNameOutput,E_TargetFileCharPath);*/

		ConsoleTableColorSet(1, 1, 0);
    cout << "正在记录并导出，本次用于文件加密，4个密钥字符串......" << endl;
    cout << "Is being recorded and exported, this time for file encryption, 4 key string......" << endl;

    time_t time_value = time(0);
    char now_time_char[64];
    strftime(now_time_char, sizeof(now_time_char), "%Y-%m-%d %X %A",localtime(&time_value));

    ofstream KeyStringSaveToFile;

    KeyStringSaveToFile.open(".//File-Key-Record-Log//ENCRYPTION-DECRYPTIPN-PASSWORD.KEY.TXT");

    KeyStringSaveToFile << "Log Time:" << " " << now_time_char << "\n" << endl;
    KeyStringSaveToFile << "Twilight-Dream-Of-Magic File Lock Password [Key String] Save\n" << endl;
    KeyStringSaveToFile << "\n" << endl;
    KeyStringSaveToFile << "Source Input File Name and Path: " << E_SourceFileStringPath << "\n" << endl;
    KeyStringSaveToFile << "EncryptFile: New Output Target File Name and Path: " << E_TargetFileStringPath << "\n" << endl;
	KeyStringSaveToFile << "Key string1 [Password1]: " << E_KEY << "\n" << endl;
    KeyStringSaveToFile << "Key string2 [Password2]: " << E_KEY2 << "\n" << endl;
    KeyStringSaveToFile << "Key string3 [Password3]: " << E_KEY3 << "\n" << endl;
    KeyStringSaveToFile << "Key string4 [Password4]: " << E_KEY4 << "\n" << endl;
    KeyStringSaveToFile << "<******************************************************************************************>" << "\n" << endl;

    KeyStringSaveToFile.close();

		ConsoleTableColorSet(1, 1, 1);
		cout << "Please wait, read and write in the file......" << endl;
		cout << "请等待，文件读写中......" << endl;
		getchar();

		if (RunEncryptFile(E_SourceFileCharPath, E_KEY, E_KEY2, E_KEY3, E_KEY4, E_TargetFileCharPath))
		{
			printf("恭喜你，文件[%s]加密成功，保存在[%s]。\n", E_SourceFileCharPath, E_TargetFileCharPath);
			printf("Congratulations, the file [%s] is encrypted successfully, saved in [%s]. \n", E_SourceFileCharPath, E_TargetFileCharPath);
			getchar();
			system("sleep 5s");
			system("clear");
			goto ProgramMainMenu;
		}
	}

/****************************************************************************************************************************************************************/

	if (Load_User_Keyboard_Input == "2")
	{
		system("echo -e '\033[44m'"); //Linux Console Backgroud Color: Blue
		system("echo -e '\033[0;92m'"); //Linux Console Foregroud Color: Light Green
		
		system("echo -e '\033[44;92m'");

		system("clear");

		if (!access(".//WorkPath//Encrypt//InputFile//", 0))
		{
			cout << "Building and Loading Folder 20%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//WorkPath//Encrypt//InputFile//");
		}

		if (!access(".//WorkPath//Encrypt//OutputFile//", 0))
		{
			cout << "Building and Loading Folder 40%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//WorkPath//Encrypt//OutputFile//");
		}

		if (!access(".//WorkPath//Decrypt//InputFile//", 0))
		{
			cout << "Building and Loading Folder 60%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//WorkPath//Decrypt//InputFile//");
		}

		if (!access(".//WorkPath//Decrypt//OutputFile//", 0))
		{
			cout << "Building and Loading Folder 80%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//WorkPath//Decrypt//OutputFile//");
		}

		if (!access(".//File-Key-Record-Log//", 0))
		{
			cout << "Building and Loading Folder 100%" << endl;
		}
		else
		{
			system("mkdir --parents --verbose .//File-Key-Record-Log//");
		}

		system("clear");

		ConsoleTableColorSet(1, 1, 1);
		cout << "Please input >>> the source file name + file extension name.\nDo not enter spaces!\n:" << endl;
		cout << "输入要解密的文件名+文件扩展名,不要输入空格!" << endl;
		std::cin >> D_SourceFileName;

		//解密密钥码是由用户自己在加密文件步骤设置的。这个定义，来自被加密密钥码的操作过的二进制文件（说明：解密密钥码等于加密密钥码）。你可以给任意一个需要解密的文件，输入正确的解密密钥码
		//The decryption key code is set by the user himself at the encrypted file step. This definition, from the encrypted key code of the operation of the binary file (Description: decryption key code is equal to the encryption key code). You can give a random file to be decrypted and enter the correct decryption key code
	D_KEY_LENTH_IS_INCORRECT:
		int D_KEY_CODE_MAX_LENGTH = 256;

		ConsoleTableColorSet(1, 1, 0);
		cout << "\n";
		cout << "输入(长度小于256)密钥,不要输入空格!" << endl;
		cout << "Please input >>> the key3,Do not enter spaces!\n(length less than 256):" << endl;
		std::cin >> D_KEY;
		if(strlen(D_KEY) > D_KEY_CODE_MAX_LENGTH)
		{
		    memset(D_KEY,NULL,sizeof(D_KEY)); //Reset This Variable The Value (NULL = 0)
			cout << "解密密钥的长度，已经超过256位字符。 请重新输入所有解密密钥！" << endl;
			cout << "Decryption key length, has more than 256 characters. Please re-enter the all decryption key!" << endl;
			system("sleep 5s");
			goto D_KEY_LENTH_IS_INCORRECT;
		}

		ConsoleTableColorSet(1, 0, 1);
		cout << "\n";
		cout << "输入(长度小于256)密钥2,不要输入空格!" << endl;
		cout << "Please input >>> the key2,Do not enter spaces!\n(length less than 256):" << endl;
		std::cin >> D_KEY2;
		if(strlen(D_KEY2) > D_KEY_CODE_MAX_LENGTH)
		{
		    memset(D_KEY2,NULL,sizeof(D_KEY2)); //Reset This Variable The Value (NULL = 0)
			cout << "解密密钥2的长度，已经超过256位字符。 请重新输入所有解密密钥！" << endl;
			cout << "Decryption key2 length, has more than 256 characters. Please re-enter the all decryption key!" << endl;
			system("sleep 5s");
			goto D_KEY_LENTH_IS_INCORRECT;
		}

		ConsoleTableColorSet(1, 0, 0);
		cout << "\n";
		cout << "输入(长度小于256)密钥3,不要输入空格!" << endl;
		cout << "Please input >>> the key,Do not enter spaces!\n(length less than 256):" << endl;
		std::cin >> D_KEY3;
		if(strlen(D_KEY3) > D_KEY_CODE_MAX_LENGTH)
		{
		    memset(D_KEY3,NULL,sizeof(D_KEY3)); //Reset This Variable The Value (NULL = 0)
			cout << "解密密钥3的长度，已经超过256位字符。 请重新输入所有解密密钥！" << endl;
			cout << "Decryption key3 length, has more than 256 characters. Please re-enter the all decryption key!" << endl;
			system("sleep 5s");
			goto D_KEY_LENTH_IS_INCORRECT;
		}

		ConsoleTableColorSet(0, 1, 1);
		cout << "\n";
		cout << "输入(长度小于256)密钥4,不要输入空格!" << endl;
		cout << "Please input >>> the key,Do not enter spaces!\n(length less than 256):" << endl;
		std::cin >> D_KEY4;
		if(strlen(D_KEY4) > D_KEY_CODE_MAX_LENGTH)
		{
		    memset(D_KEY4,NULL,sizeof(D_KEY4)); //Reset This Variable The Value (NULL = 0)
			cout << "解密密钥4的长度，已经超过256位字符。 请重新输入所有解密密钥！" << endl;
			cout << "Decryption key4 length, has more than 256 characters. Please re-enter the all decryption key!" << endl;
			system("sleep 5s");
			goto D_KEY_LENTH_IS_INCORRECT;
		}

		system("clear");

		ConsoleTableColorSet(0, 1, 0);

		cout << "\n";
		cout << "如果在当前文件夹下配置文件[.//*.CONFIGFILE]不存在，程序就不会帮您自动恢复原来的文件名称。\n你需要重新输入文件名!" << endl;
		cout << "If the configuration file [.//*.CONFIGFILE] does not exist in the current folder, the program will not automatically restore the original file name.\nYou need to re-enter the file name!" << endl;
		cout << "Please output >>> target file main name,not the file extension name!\nDo not enter spaces!\n[DATA-DECRYPTED]:" << endl;
		cout << "输出文件主要名，不是文件扩展名，不要输入空格[DATA-TSMY-DECRYPTED]!" << endl; //给解密后的文件输出主要文件名，并保存 Output the main file name to the decrypted file and save it
		if (!access(".//SourceFileMainName.CONFIGFILE", 0))
		{
			//char TFMN_Buffer[256];
			ifstream LoadSourceFileNameConfigure(".//SourceFileMainName.CONFIGFILE", ios::in);
			if (LoadSourceFileNameConfigure.fail())
			{
        This_Error_Code = 1;
        Set_CTUI_Error(This_Error_Code);
			}
			while (!LoadSourceFileNameConfigure.eof())
			{
				LoadSourceFileNameConfigure >> D_TargetFileMainName;
				//LoadSourceFileNameConfigure.getline(TFMN_Buffer,256,'\n'); //getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
				//D_TargetFileMainName = TFMN_Buffer;

				cout << "您已成功跳过此步骤" << endl;
				cout << "You have successfully skipped this step" << endl;
			}
			LoadSourceFileNameConfigure.close();
		}
		else
		{
			cout << "配置文件" << ".//SourceFileMainName.CONFIGFILE" << "未找到!\n" << "请重新输入名称!" << endl;
			cout << "Configuration file" << ".//SourceFileMainName.CONFIGFILE " << "Not found!\n" << "Please re-enter the name!" << endl;
			system("touch './/SourceFileMainName.CONFIGFILE'");
			std::cin >> D_TargetFileMainName;

		}

		system("clear");

		cout << "如果在当前文件夹下配置文件[.//*.CONFIGFILE]不存在，程序就不会帮您自动恢复原来的文件名称。\n你需要重新输入文件名!" << endl;
		cout << "If the configuration file [.//*.CONFIGFILE] does not exist in the current folder, the program will not automatically restore the original file name.\nYou need to re-enter the file name!" << endl;
		cout << "Please output >>> target file extension name!\nDo not enter spaces!\n[Example: .txt]:" << endl;
		cout << "输出文件扩展名，不要输入空格[实例： .txt]!" << endl; //给解密后的文件输出文件扩展名，并保存
		if (!access(".//SourceFileExtendedName.CONFIGFILE", 0))
		{
			ifstream LoadSourceFileNameConfigure(".//SourceFileExtendedName.CONFIGFILE", ios::in);
			//char TFEN_Buffer[256];
			if (LoadSourceFileNameConfigure.fail())
			{
        This_Error_Code = 1;
        Set_CTUI_Error(This_Error_Code);
			}
			while (!LoadSourceFileNameConfigure.eof())
			{
				LoadSourceFileNameConfigure >> D_TargetFileExtendedName;
				//LoadSourceFileNameConfigure.getline(TFEN_Buffer,256,'\n'); //getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
				//D_TargetFileExtendedName = TFEN_Buffer;

				cout << "您已成功跳过此步骤" << endl;
				cout << "You have successfully skipped this step" << endl;
			}
			LoadSourceFileNameConfigure.close();
		}
		else
		{
			cout << "配置文件" << ".//SourceFileExtendedName.CONFIGFILE" << "未找到!\n" << "请重新输入名称!" << endl;
			cout << "Configuration file" << ".//SourceFileExtendedName.CONFIGFILE " << "Not found!\n" << "Please re-enter the name!" << endl;
			system("touch './/SourceFileExtendedName.CONFIGFILE'");
			std::cin >> D_TargetFileExtendedName;
		}

		system("clear");

		cout << "\n";
		cout << "如果在当前文件夹下配置文件[.//*.CONFIGFILE]不存在，程序就不会帮您自动恢复原来的文件名称。\n你需要重新输入文件名!" << endl;
		cout << "If the configuration file [.//*.CONFIGFILE] does not exist in the current folder, the program will not automatically restore the original file name.\nYou need to re-enter the file name!" << endl;
		cout << "Please output >>> target file temporary add name.\nDo not enter spaces!\n[-DECRYPTED]:" << endl;
		cout << "输出文件临时添加名，不要输入空格[-TSMY-DECRYPTED]!" << endl; //给解密后的文件输出文件临时添加名，并保存
		cout << "Prevent source encrypted files from being overwritten" << endl;
		cout << "防止源加密文件被覆盖" << endl;
		std::cin >> D_TargetFileTempName;
		if (D_TargetFileTempName == " ")
		{
			string D_TargetFileAddName = "-TSMY-DECRYPTED";
			D_TargetFileTempName = D_TargetFileAddName;
		}

		system("clear");

		string D_SourceFileStringPath = D_IF_PATH + D_SourceFileName;
		string D_TargetFileStringPath = D_OF_PATH + D_TargetFileMainName + D_TargetFileTempName + D_TargetFileExtendedName;

		const char *D_SourceFileCharPath = D_SourceFileStringPath.c_str();
		const char *D_TargetFileCharPath = D_TargetFileStringPath.c_str();

		/*char *D_SourceFileLastNameOutput; //最后读写的文件名
		strcpy(D_SourceFileLastNameOutput,D_SourceFileCharPath);
		char *D_TargetFileLastNameOutput; //最后临时保存的解密后的文件名
		strcpy(D_TargetFileLastNameOutput,D_TargetFileCharPath);*/

		ConsoleTableColorSet(0, 0, 1);
		cout << "Please wait, read and write in the file......" << endl;
		cout << "请等待，文件读写中......" << endl;
		getchar();

		if (RunDecryptFile(D_SourceFileCharPath, D_KEY, D_KEY2, D_KEY3, D_KEY4, D_TargetFileCharPath))
		{
			printf("恭喜你，文件[%s]解密成功，保存在[%s]。\n", D_SourceFileCharPath, D_TargetFileCharPath);
			printf("Congratulations, the file [%s] is decrypted successfully, saved in [%s]. \n", D_SourceFileCharPath, D_TargetFileCharPath);
			getchar();
			system("sleep 5s");
			system("clear");
			goto ProgramMainMenu;
		}
	}

/****************************************************************************************************************************************************************/

	if (Load_User_Keyboard_Input == "3")
	{
	 Instruction_Manual_Language_Restart:
	  system("clear");

	    system("echo -e '\033[47;33m'");

		cout << "欢迎你的到来！这是本程序的说明手册[Alpha Version 3.2]，请务必在使用前，仔细阅读" << endl;
		cout << "Welcome to your arrival! This is the instruction manual [Beta Version 3.1] of this program, please be sure to read carefully before using it" << endl;
		cout << "" << endl;
		cout << "enUS----------English 英文" << endl;
		cout << "zhCN----------Chinese 中文" << endl;
		cout << "MENU----------Back Main Menu 返回主菜单" << endl;
		cout << "" << endl;
		cout << "Manual://Program//Keyboard_Input> ";
		string Instruction_Manual_Language;
		std::cin >> Instruction_Manual_Language;
		if (Instruction_Manual_Language == "enUS")
		{
			system("clear");

			system("echo -e '\033[45;34m'");

			cout << "Manual://Program//Keyboard_Output> " << endl;
			cout << "" << endl;
			cout << "When the program executes the function of encrypting the file or decrypting the file, it will create the workspace folder, input the folder, output the folder.\n" << endl;
			cout << "When the program encrypts the file or decrypts the file and waits, the program is reading and writing the file in the background.\nNever close the program at this time! Otherwise your data is damaged and bear the consequences.\nIt is recommended that you after the data backup, use this program to encrypt the file or decrypt the file!\n" << endl;
			system("sleep 5s");
			system("clear");
		}
		if (Instruction_Manual_Language == "zhCN")
		{
			system("clear");

			system("echo -e '\033[31;36m'");

			cout << "Manual://Program//Keyboard_Output> " << endl;
			cout << "" << endl;
			cout << "当程序执行加密文件或解密文件的功能时，将创建工作空间文件夹，输入文件夹，输出文件夹。\n" << endl;
			cout << "当程序加密文件或解密文件并且等待时，程序正在后台读取和写入文件。这个时候，永远不要关闭这个程序！\n否则您的数据被损坏并承担后果。建议您在进行数据备份之后，用这个程序加密文件或解密文件！\n" << endl;
			system("sleep 5s");
			system("clear");

		}
		if (Instruction_Manual_Language == "MENU","menu")
		{
			system("clear");
			goto ProgramMainMenu;
		}
		else
		{
			if (Instruction_Manual_Language != "enUS", "zhCN")
			{
				ConsoleTableColorSet(0, 0, 0);
				goto Instruction_Manual_Language_Restart;
			}
		}

	}

/****************************************************************************************************************************************************************/

	if (Load_User_Keyboard_Input == "4")
	{
	Waring_Information:
		string You_understand;

		system("echo -e '\033[37;31m'");

		cout << "[警告!]即将进行的操作，会选中 <File-Key-Record-Log> 和 <WorkPath> 文件夹，然后永久的删除所有数据!\n" << endl;
		cout << "包括源文件、生成的加密文件、生成的解密文件、密码日志、配置\n" << endl;
		cout << "如果你知道风险，请按键盘 [Y键继续 N键返回]\n[ Yes / No ]" << endl;

		cout << "[Warning!] The upcoming operation will select the <File-Key-Record-Log>and <WorkPath folders>, and then permanently delete all the data!\n" << endl;
		cout << "Including source files, generated encrypted files, generated decrypted files, password logs, configuration\n" << endl;
		cout << "If you know the risk, press the keypad [Y key to continue N key to back the main menu]\n[Yes / No]" << endl;
		std::cin >> You_understand; //你了解风险？ You understand the risks?


		if (You_understand == "N")
		{
			goto ProgramMainMenu;
		}
		if (You_understand == "n")
		{
			goto ProgramMainMenu;
		}
		if (You_understand== "Y")
		{
			CleanFileFromThisWorkspace();

			goto ProgramMainMenu;
		}
		if (You_understand == "y")
		{
			CleanFileFromThisWorkspace();

			goto ProgramMainMenu;
		}
		else
		{
			goto Waring_Information;
		}
	}

/****************************************************************************************************************************************************************/

	if (Load_User_Keyboard_Input == "5")
	{
		ConsoleTableColorUnset();
		return 0;
	}
	else
	{
		if (Load_User_Keyboard_Input != "1", "2", "3", "4")
		{
			ConsoleTableColorSet(0, 0, 0);
			cout << "User keyboard enter error !" << endl;
			getchar();
			exit(1);
		}
	}
}

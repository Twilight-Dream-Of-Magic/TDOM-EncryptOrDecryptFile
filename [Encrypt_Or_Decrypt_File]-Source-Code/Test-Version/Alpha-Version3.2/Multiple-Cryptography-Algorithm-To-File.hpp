#include "Support-Libary.hpp"

using namespace std;

int RunEncryptFile(const char *E_SourceFileCharPath, char *E_KEY, char *E_KEY2, char *E_KEY3, char *E_KEY4, const char *E_TargetFileCharPath);
int RunDecryptFile(const char *D_SourceFileCharPath, char *D_KEY, char *D_KEY2, char *D_KEY3, char *D_KEY4, const char *D_TargetFileCharPath);

/***声明代码-开始 Declare the code - the beginning***/
//以下变量,应用到文件被加密时
//The following variables apply when the file is encrypted

string E_SourceFileName,       // 源文件名
E_SourceFileMainName,     // 源文件主要名
E_SourceFileExtendedName, // 源文件扩展名
E_TargetFileExtendedName; // 目标文件扩展名

char E_KEY[256], //File (Encryption or Encrypted) key 文件加密密钥
E_KEY2[256],
E_KEY3[256],
E_KEY4[256];
/***声明代码-结束 Declare the code - end***/

/***声明代码-开始 Declare the code - the beginning***/
//以下变量,应用到文件被解密时
//The following variables apply when the file is decrypted

string D_SourceFileName,      //源文件名
D_TargetFileMainName,     //目标文件主要名
D_TargetFileTempName,     //目标文件临时添加名
D_TargetFileExtendedName; //目标文件源扩展名

char D_KEY[256], //File (Decryption or Decrypted) key 文件解密密钥
D_KEY2[256],
D_KEY3[256],
D_KEY4[256];
/***声明代码-结束 Declare the code - end***/

int NOIEM; //初始加密模块次数 (Number of initial encryption modules)
int NOIDM; //初始解密模块次数 (Number of initial decryption modules)

int MAX_NOT_E_MODULE = 12801; //加密模块最大循环次数 (The maximum number of times the encryption module is running)
int MINI_NOT_E_GROUP = 6401; //加密集合最小循环次数 (The minimum number of times the encryption group is running)

int MAX_NOT_D_MODULE = 12801; //解密模块最大循环次数 (The maximum number of times the decryption module is running)
int MINI_NOT_D_GROUP = 6401; //解密集合最小循环次数 (The minimum number of times the decryption group is running)

long FileHeaderLength = 0;
long FileHeaderByteData = 0;

/*******************************************
*                 加密文件
*
* E_SourceFileName    需要加密的文件名
* E_KEY               密钥
* E_TargetFileNewName 加密完成后要保存的文件名
*
* @return  加密成功或失败的数字表示
*
* 0 = 加密失败
* 1 = 加密成功
********************************************/

	int RunEncryptFile(const char *E_SourceFileCharPath, char *E_KEY, char *E_KEY2, char *E_KEY3, char *E_KEY4, const char *E_TargetFileCharPath)
	{
			FILE *FilePointerSource, *FilePointerTarget; //需要打开的文件的指针 Need to open the file pointer
			char buffer[1024];                           //文件流缓冲区，用于存放从文件读取的数据 File stream buffer, used to store the data read from the file

			int FileByteData,                            //每次从文件中读取的字节数 The number of bytes read from the file each time
				RTNOC,                                     //运行循环次数 (Run The Number Of Cycles)
				KeyLength = strlen(E_KEY),                 //密钥的长度 The length of the key
				KeyLength2 = strlen(E_KEY2),
				KeyLength3 = strlen(E_KEY3),
				KeyLength4 = strlen(E_KEY4);

			FilePointerSource = fopen(E_SourceFileCharPath, "rb"); //以二进制方式读取文件
			if(FilePointerSource == NULL)
			{
				//printf("File[%s]failed to open, please check whether the file path and name are entered correctly !\n", E_SourceFileCharPath);
				//printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确 ！\n", E_SourceFileCharPath);
        cout << "File " << "[ " << E_SourceFileCharPath << " ]" << " failed to open, please check whether the file path and name are entered correctly!" << endl;
        cout << "文件 " << "[ " << E_SourceFileCharPath << " ]" << " 打开失败，请检查文件路径和名称是否输入正确 ！" << endl;
				getchar();
				return 0;
			}

			FilePointerTarget = fopen(E_TargetFileCharPath, "wb+"); //以二进制方式写入文件
			if(FilePointerTarget == NULL)
			{
				//printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly !\n", E_TargetFileCharPath);
				//printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确 ！\n", E_TargetFileCharPath);
        cout << "File " << "[ " << E_TargetFileCharPath << " ]" << " creation/write failed! Please check whether the file path and name are entered correctly !" << endl;
        cout << "文件 " << "[ " << E_TargetFileCharPath << " ]" << " 创建/写入失败！请检查文件路径和名称是否输入正确 ！" << endl;
				getchar();
				return 0;
			}

/*加密算法开始*/

/*****************************************************************************buffer[RTNOC]******************************************************************************/

//运行大型加密模块
//Run large encryption module

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

    /*Skip file header (512 byte)*/
		fseek(FilePointerSource,512L,SEEK_SET); //Move the file pointer to the 512th byte of the file start
		FileHeaderLength = ftell(FilePointerSource);//Get this file header length
		fseek(FilePointerSource,0L,SEEK_SET);//Move the file pointer to this file start point

    /*Continuously read fileheaderlength length data from file, save to buffer until end of file*/
		while((FileHeaderByteData = fread(buffer, 1, FileHeaderLength, FilePointerSource)) > 0)
		{
			fwrite(buffer, 1, FileHeaderByteData, FilePointerTarget); //Write data from buffer to file
		}

		/*The pointer to the file stream is moved, and the read and write data continues to start at the 513rd byte*/
		fseek(FilePointerSource,513L,SEEK_SET);
		fseek(FilePointerTarget,513L,SEEK_SET);


		for(NOIEM = 0;NOIEM < MAX_NOT_E_MODULE;NOIEM++)
		{
			system("@color 6F");
			cout << "Please wait, read and write in the file......" << endl;
			cout << "请等待，文件读写中......" << endl;
			system("@color 0D");
			cout << "The display of the interaction progress has been opened using the request for the encryption function." << endl;
			cout << "使用加密功能的请求，交互进度的显示已经被打开。" << endl;
			cout << "Encrypting...... Currently in use the first key" << endl;

			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				//Mini-Group Encryption Module Key1-Calculate1
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop division) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递除运算.
					{
						buffer[RTNOC] /= E_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				//Mini-Group Encryption Module Key1-Calculate2
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop addition) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递增运算.
					{
						buffer[RTNOC] += E_KEY[RTNOC];
					}
				   fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				//Mini-Group Encryption Module Key1-Calculate3
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //不Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop multiplication) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递乘运算.
					{
						buffer[RTNOC] *= E_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				//Mini-Group Encryption Module Key1-Calculate4
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop subtraction) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递减运算.
					{
						buffer[RTNOC] -= E_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

			cout << "Encrypting...... Currently in use the second key" << endl;

			//Mini-Group Encryption Module Key2-Calculate1
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop multiplication) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递乘运算.
					{
						buffer[RTNOC] *= E_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Encryption Module Key2-Calculate2
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop subtraction) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递减运算.
					{
					   buffer[RTNOC] -= E_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Encryption Module Key2-Calculate3
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop division) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递除运算。
					{
					   buffer[RTNOC] /= E_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Encryption Module Key2-Calculate4
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop addition) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递增运算.
					{
					   buffer[RTNOC] += E_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

			cout << "Encrypting...... Currently in use the third key" << endl;

			//Mini-Group Encryption Module Key3-Calculate1
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{

				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY3[RTNOC];
					}
				fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop subtraction) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递减运算.
					{
						buffer[RTNOC] -= E_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Encryption Module Key3-Calculate2
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{

				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY3[RTNOC];
					}
				fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop division) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递除运算.
					{
						buffer[RTNOC] /= E_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Encryption Module Key3-Calculate3
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{

				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY3[RTNOC];
					}
				fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop addition) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递增运算.
					{
						buffer[RTNOC] += E_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}

			}

			//Mini-Group Encryption Module Key3-Calculate4
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{

				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= E_KEY3[RTNOC];
					}
				fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop multiplication) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递乘运算.
					{
						buffer[RTNOC] *= E_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

//文件和密钥4在缓冲区中计算
//The file and key4 are counted in Buffer

			cout << "Encrypting...... Currently in use the fourth key" << endl;

			//Mini-Group Encryption Module Key4-Calculate1

			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for (RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
					buffer[RTNOC] ^= E_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop addition) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递增运算.
					{
						buffer[RTNOC] += E_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Encryption Module Key4-Calculate2
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for (RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
					buffer[RTNOC] ^= E_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop multiplication) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递乘运算.
					{
						buffer[RTNOC] *= E_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Encryption Module Key4-Calculate3
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for (RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
					buffer[RTNOC] ^= E_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop subtraction) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递减运算.
					{
						buffer[RTNOC] -= E_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Encryption Module Key4-Calculate4
			for(NOIEM = 0;NOIEM < MINI_NOT_E_GROUP;NOIEM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for (RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and E_KEY on the data in the buffer
					{
					buffer[RTNOC] ^= E_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop division) operation of byte-by-byte and E_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递除运算.
					{
						buffer[RTNOC] /= E_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			system("@color 07");
			cout << "The display of the interaction progress has been closed for the encryption function." << endl;
			cout << "已经关闭加密功能的交互进度的显示。" << endl;

			if(NOIEM < MAX_NOT_E_MODULE || 12800)
			{
			  break; //End encrypting process
			}

		}

/***********************************************************************************************************************************************************/

/*加密算法结束*/

		  fclose(FilePointerSource);
		  fclose(FilePointerTarget);

		  //DeleteFile(E_SourceFileCharPath); /*This is windows API function*/
			//remove(E_SourceFileCharPath); /*This is C & C++ language the delete file common IO function, use in the linux and unix or windows platform.*/

		return 1;
	}

/*******************************************
*                 解密文件
*
* D_SourceFileName    需要解密的文件名
* D_KEY               密钥
* D_TargetFileNewName 解密完成后要保存的文件名
*
* @return  解密成功或失败的数字表示
*
* 0 = 解密失败
* 1 = 解密成功
********************************************/

	int RunDecryptFile(const char *D_SourceFileCharPath, char *D_KEY, char *D_KEY2, char *D_KEY3, char *D_KEY4, const char *D_TargetFileCharPath)
	{
			FILE *FilePointerSource, *FilePointerTarget; //需要打开的文件的指针 Need to open the file pointer
			char buffer[1024];                           //文件流缓冲区，用于存放从文件读取的数据 File stream buffer, used to store the data read from the file

			int FileByteData,                            //每次从文件中读取的字节数 The number of bytes read from the file each time
				RTNOC,                                     //运行循环次数 (Run The Number Of Cycles)
				KeyLength = strlen(D_KEY),                 //密钥的长度 The length of the key
				KeyLength2 = strlen(D_KEY2),
				KeyLength3 = strlen(D_KEY3),
				KeyLength4 = strlen(D_KEY4);

			FilePointerSource = fopen(D_SourceFileCharPath, "rb"); //以二进制方式读取文件
			if(FilePointerSource == NULL)
			{
				//printf("File[%s]failed to open, please check whether the file path and name are entered correctly !\n", D_SourceFileCharPath);
				//printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确 ！\n", D_SourceFileCharPath);
        cout << "File " << "[ " << D_SourceFileCharPath << " ]" << " failed to open, please check whether the file path and name are entered correctly !" << endl;
        cout << "文件 " << "[ " << D_SourceFileCharPath << " ]" << " 打开失败，请检查文件路径和名称是否输入正确 ！" << endl;
				getchar();
				return 0;
			}

			FilePointerTarget = fopen(D_TargetFileCharPath, "wb+"); //以二进制方式写入文件
			if(FilePointerTarget == NULL)
			{
				//printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly !\n", D_TargetFileCharPath);
				//printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确 ！\n", D_TargetFileCharPath);
        cout << "File " << "[ " << D_TargetFileCharPath << " ]" << " creation/write failed! Please check whether the file path and name are entered correctly !" << endl;
        cout << "文件 " << "[ " << D_TargetFileCharPath << " ]" << " 创建/写入失败！请检查文件路径和名称是否输入正确 ！" << endl;
				getchar();
				return 0;
			}

/*解密算法开始*/

/***********************************************************************************************************************************************************/

//运行大型解密模块
//Run large decryption module

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

    /*Skip file header (512 byte)*/
		fseek(FilePointerSource,512L,SEEK_SET); //Move the file pointer to the 512th byte of the file start
		FileHeaderLength = ftell(FilePointerSource);//Get this file header length
		fseek(FilePointerSource,0L,SEEK_SET);//Move the file pointer to this file start point

    /*Continuously read fileheaderlength length data from file, save to buffer until end of file*/
		while((FileHeaderByteData = fread(buffer, 1, FileHeaderLength, FilePointerSource)) > 0)
		{
			fwrite(buffer, 1, FileHeaderByteData, FilePointerTarget); //Write data from buffer to file
		}

		/*The pointer to the file stream is moved, and the read and write data continues to start at the 513rd byte*/
		fseek(FilePointerSource,513L,SEEK_SET);
		fseek(FilePointerTarget,513L,SEEK_SET);

		for(NOIDM = 0;NOIDM < MAX_NOT_D_MODULE;NOIDM++)
		{
			system("@color 6F");
			std::cout << "Please wait, read and write in the file......" << endl;
			std::cout << "请等待，文件读写中......" << endl;
			system("@color 0D");
			cout << "The display of the interaction progress has been opened using the request for the decryption function." << endl;
			cout << "使用解密功能的请求，交互进度的显示已经被打开。" << endl;
			cout << "Decrypting...... Currently in use the first key" << endl;

			//Mini-Group Decryption Module Key1-Calculate1
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY[RTNOC];
					}
				fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop division) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递除运算.
					{
						buffer[RTNOC] /= D_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key1-Calculate2
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY[RTNOC];
					}
				fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop subtraction) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递减运算.
					{
						buffer[RTNOC] -= D_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key1-Calculate3
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY[RTNOC];
					}
				fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop multiplication) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递乘运算.
					{
						buffer[RTNOC] *= D_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key1-Calculate4
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY[RTNOC];
					}
				fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength, FilePointerSource)) > 0) //Constantly reads KeyLength-length data from a file, saves it to the buffer until the end of the file. 不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束。
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop addition) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递增运算.
					{
						buffer[RTNOC] += D_KEY[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

			cout << "Decrypting...... Currently in use the second key" << endl;

			//Mini-Group Decryption Module Key2-Calculate1
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop multiplication) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递乘运算.
					{
						buffer[RTNOC] *= D_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key2-Calculate2
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop addition) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递增运算.
					{
						buffer[RTNOC] += D_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key2-Calculate3
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop division) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递除运算.
					{
						buffer[RTNOC] /= D_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key2-Calculate4
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop subtraction) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递减运算.
					{
						buffer[RTNOC] -= D_KEY2[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

			cout << "Decrypting...... Currently in use the third key" << endl;

			//Mini-Group Decryption Module Key3-Calculate1
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while ((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
				{
					for (RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop addition) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递增运算.
					{
						buffer[RTNOC] += D_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key3-Calculate2
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while ((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
				{
					for (RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop division) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递除运算.
					{
						buffer[RTNOC] /= D_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key3-Calculate3
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while ((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
				{
					for (RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop subtraction) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递减运算.
					{
						buffer[RTNOC] -= D_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key3-Calculate4
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while ((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
				{
					for (RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop multiplication) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递乘运算.
					{
						buffer[RTNOC] *= D_KEY3[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

//文件和密钥4在缓冲区中计算
//The file and key4 are counted in Buffer

			cout << "Decrypting...... Currently in use the fourth key" << endl;

			//Mini-Group Decryption Module Key4-Calculate1
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop subtraction) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递减运算.
					{
						buffer[RTNOC] -= D_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key4-Calculate2
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop multiplication) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递乘运算.
					{
						buffer[RTNOC] *= D_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key4-Calculate3
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop addition) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递增运算.
					{
						buffer[RTNOC] += D_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			//Mini-Group Decryption Module Key4-Calculate4
			for(NOIDM = 0;NOIDM < MINI_NOT_D_GROUP;NOIDM++)
			{
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (XOR = Exclusive or) operation of byte-by-byte and D_KEY on the data in the buffer
					{
						buffer[RTNOC] ^= D_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
				while((FileByteData = fread(buffer, 1, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
				{
					for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //Execute the (loop division) operation of byte-by-byte and D_KEY on the data in the buffer. 对buffer中的数据逐字节的和E_KEY进行递除运算.
					{
						buffer[RTNOC] /= D_KEY4[RTNOC];
					}
				  fwrite(buffer, 1, FileByteData, FilePointerTarget); //Write buffer data to file. 将buffer中的数据写入文件。
				}
			}

			system("@color 07");
			cout << "The display of the interaction progress has been closed for the decryption function." << endl;
			cout << "已经关闭解密功能的交互进度的显示。" << endl;

			if(NOIEM < MAX_NOT_D_MODULE || 12800)
			{
			  break; //End decrypting process
			}

		}

/***********************************************************************************************************************************************************/

/*解密算法结束*/

		  fclose(FilePointerSource);
		  fclose(FilePointerTarget);

			//DeleteFile(D_SourceFileCharPath); /*This is windows API function*/
		  //remove(D_SourceFileCharPath); /*This is C & C++ language the delete file common IO function, use in the linux and unix or windows platform.*/

		return 1;
	}

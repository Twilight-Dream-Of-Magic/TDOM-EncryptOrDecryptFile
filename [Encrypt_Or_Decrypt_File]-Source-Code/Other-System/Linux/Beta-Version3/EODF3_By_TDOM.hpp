#include <iostream> //Standard C++ language input and output function
#include <fstream> //Standard C++ language input and output function of file stream
#include <unistd.h> //Unix & Linux GNU standard (POSIX)
//#include <io.h>
#include <stdio.h>	//Standard C language input and output function
#include <stdlib.h>	//C language standard library functions
#include <string.h>	//C language string processing function

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

            int FileByteData,                              //每次从文件中读取的字节数 The number of bytes read from the file each time
                RTNOC,                                     //运行循环次数 (Run The Number Of Cycles)
                KeyLength = strlen(E_KEY),                 //密钥的长度 The length of the key
                KeyLength2 = strlen(E_KEY2),
                KeyLength3 = strlen(E_KEY3),
                KeyLength4 = strlen(E_KEY4);

             FilePointerSource = fopen(E_SourceFileCharPath, "rb"); //以二进制方式读取文件
             if(FilePointerSource == NULL)
             {
               printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", E_SourceFileCharPath);
               printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", E_SourceFileCharPath);
               getchar();
               return 0;
             }

             FilePointerTarget = fopen(E_TargetFileCharPath, "wb+"); //以二进制方式写入文件
             if(FilePointerTarget == NULL)
             {
               printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", E_TargetFileCharPath);
               printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", E_TargetFileCharPath);
               getchar();
               return 0;
             }

/*加密算法开始*/

/*****************************************************************************buffer[RTNOC]******************************************************************************/

//运行大型加密模块
//Run large encryption module

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

        int NOIEM;                 //初始加密模块次数 (Number of initial encryption modules)
        int MAX_NOT_E_MODULE = 66; //运行加密模块循环次数 (The maximum number of times the encryption module is running)

        for(NOIEM = 0;NOIEM < MAX_NOT_E_MODULE;NOIEM++)
        {
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                    buffer[RTNOC] += E_KEY[RTNOC];
                 }
                fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                    buffer[RTNOC] *= E_KEY[RTNOC];
                 }
               fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                    buffer[RTNOC] ^= E_KEY[RTNOC];
                 }
               fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
                 {
                    buffer[RTNOC] /= E_KEY[RTNOC];
                 }
               fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
                 {
                    buffer[RTNOC] -= E_KEY[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                    buffer[RTNOC] += E_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                    buffer[RTNOC] *= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                    buffer[RTNOC] ^= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
                 {
                    buffer[RTNOC] /= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
                 {
                    buffer[RTNOC] -= E_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                    buffer[RTNOC] += E_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                    buffer[RTNOC] *= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                    buffer[RTNOC] ^= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
                 {
                    buffer[RTNOC] /= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
                 {
                    buffer[RTNOC] -= E_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥4在缓冲区中计算
//The file and key4 are counted in Buffer

            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                    buffer[RTNOC] += E_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                    buffer[RTNOC] *= E_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                    buffer[RTNOC] ^= E_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
                 {
                    buffer[RTNOC] /= E_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
                 {
                    buffer[RTNOC] -= E_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
        }

/***********************************************************************************************************************************************************/

/*加密算法结束*/

          fclose(FilePointerSource);
          fclose(FilePointerTarget);

          remove(E_SourceFileCharPath);

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

            int FileByteData,                              //每次从文件中读取的字节数 The number of bytes read from the file each time
                RTNOC,                                     //运行循环次数 (Run The Number Of Cycles)
                KeyLength = strlen(D_KEY),                 //密钥的长度 The length of the key
                KeyLength2 = strlen(D_KEY2),
                KeyLength3 = strlen(D_KEY3),
                KeyLength4 = strlen(D_KEY4);

             FilePointerSource = fopen(D_SourceFileCharPath, "rb"); //以二进制方式读取文件
             if(FilePointerSource == NULL)
             {
               printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", D_SourceFileCharPath);
               printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", D_SourceFileCharPath);
               getchar();
               return 0;
             }

             FilePointerTarget = fopen(D_TargetFileCharPath, "wb+"); //以二进制方式写入文件
             if(FilePointerTarget == NULL)
             {
               printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", D_TargetFileCharPath);
               printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", D_TargetFileCharPath);
               getchar();
               return 0;
             }

/*解密算法开始*/

/***********************************************************************************************************************************************************/

//运行大型解密模块
//Run large decryption module

//文件和密钥在缓冲区中计算
//The file and key are counted in Buffer

         int NOIDM;                 //初始解密模块次数 (Number of initial decryption modules)
         int MAX_NOT_D_MODULE = 66; //运行解密模块循环次数 (The maximum number of times the decryption module is running)

         for(NOIDM = 0;NOIDM < MAX_NOT_D_MODULE;NOIDM++)
         {
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
                 {
                    buffer[RTNOC] -= D_KEY[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
                 {
                    buffer[RTNOC] /= D_KEY[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                    buffer[RTNOC] ^= D_KEY[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                    buffer[RTNOC] *= D_KEY[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                    buffer[RTNOC] += D_KEY[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }


//文件和密钥2在缓冲区中计算
//The file and key2 are counted in Buffer

            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
                 {
                    buffer[RTNOC] -= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
                 {
                    buffer[RTNOC] /= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                    buffer[RTNOC] ^= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                    buffer[RTNOC] *= D_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength2, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength2 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                    buffer[RTNOC] += D_KEY2[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥3在缓冲区中计算
//The file and key3 are counted in Buffer

            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
                 {
                    buffer[RTNOC] -= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
                 {
                    buffer[RTNOC] /= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                    buffer[RTNOC] ^= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                    buffer[RTNOC] *= D_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength3, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength3 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                    buffer[RTNOC] += D_KEY3[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }

//文件和密钥4在缓冲区中计算
//The file and key4 are counted in Buffer

            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递减运算
                 {
                    buffer[RTNOC] -= D_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递除运算
                 {
                    buffer[RTNOC] /= D_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行异或运算
                 {
                    buffer[RTNOC] ^= D_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递乘运算
                 {
                    buffer[RTNOC] *= D_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
            while((FileByteData = fread(buffer, 16, KeyLength4, FilePointerSource)) > 0) //不断地从文件中读取 KeyLength4 长度的数据，保存到buffer，直到文件结束
            {
                 for(RTNOC = 0; RTNOC < FileByteData; RTNOC++) //对buffer中的数据逐字节的和E_KEY进行递增运算
                 {
                    buffer[RTNOC] += D_KEY4[RTNOC];
                 }
              fwrite(buffer, 16, FileByteData, FilePointerTarget); //将buffer中的数据写入文件
            }
         }

/***********************************************************************************************************************************************************/

/*解密算法结束*/

          fclose(FilePointerSource);
          fclose(FilePointerTarget);

          remove(D_SourceFileCharPath);

        return 1;
    }

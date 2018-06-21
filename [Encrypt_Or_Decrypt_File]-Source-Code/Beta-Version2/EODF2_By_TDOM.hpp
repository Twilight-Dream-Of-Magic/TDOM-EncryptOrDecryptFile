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

        int RunEncryptFile(char *E_SourceFileName, char *E_KEY, char *E_KEY2, char *E_KEY3, char *E_TargetFileNewName)
        {
            FILE *FilePointerSource, *FilePointerTarget; //要打开的文件的指针
            char buffer[1024];               //缓冲区，用于存放从文件读取的数据

            int FileByteData,                //每次从文件中读取的字节数
                RTNOC,                       //运行循环次数 (Run The Number Of Cycles)
                KeyLength = strlen(E_KEY),   //密钥的长度
                KeyLength2 = strlen(E_KEY2),
                KeyLength3 = strlen(E_KEY3);

             FilePointerSource = fopen(E_SourceFileName, "rb"); //以二进制方式读取文件
             if(FilePointerSource == NULL)
             {
               printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", E_SourceFileName);
               printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", E_SourceFileName);
               getchar();
               return 0;
             }

             FilePointerTarget = fopen(E_TargetFileNewName, "wb"); //以二进制方式写入文件
             if(FilePointerTarget == NULL)
             {
               printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", E_TargetFileNewName);
               printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", E_TargetFileNewName);
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

          DeleteFile(E_SourceFileName);

        return 1;
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

        int RunDecryptFile(char *D_SourceFileName, char *D_KEY, char *D_KEY2, char *D_KEY3, char *D_TargetFileNewName)
        {
            FILE *FilePointerSource, *FilePointerTarget; //要打开的文件的指针
            char buffer[1024];               //缓冲区，用于存放从文件读取的数据

            int FileByteData,                //每次从文件中读取的字节数
                RTNOC,                       //运行循环次数 (Run The Number Of Cycles)
                KeyLength = strlen(D_KEY),   //密钥的长度
                KeyLength2 = strlen(D_KEY2),
                KeyLength3 = strlen(D_KEY3);

             FilePointerSource = fopen(D_SourceFileName, "rb"); //以二进制方式读取文件
             if(FilePointerSource == NULL)
             {
               printf("File[%s]failed to open, please check whether the file path and name are entered correctly! \n", D_SourceFileName);
               printf("文件[%s]打开失败，请检查文件路径和名称是否输入正确！\n", D_SourceFileName);
               getchar();
               return 0;
             }

             FilePointerTarget = fopen(D_TargetFileNewName, "wb"); //以二进制方式写入文件
             if(FilePointerTarget == NULL)
             {
               printf("File[%s]creation/write failed! Please check whether the file path and name are entered correctly!\n", D_TargetFileNewName);
               printf("文件[%s]创建/写入失败！请检查文件路径和名称是否输入正确！\n", D_TargetFileNewName);
               getchar();
               return 0;
             }

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

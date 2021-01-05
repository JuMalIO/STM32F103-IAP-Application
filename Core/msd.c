#include "msd.h"
#include "ff.h"
#include <stdio.h>

static FATFS FatFs;
static FIL File;

void MSD_Init(void)
{
	f_mount(&FatFs, "", 1);
}

void MSD_DeleteFile(char* path)
{
	f_unlink(path);
}

_Bool MSD_IsExistingFile(char* path)
{
	if (f_open(&File, path, FA_READ) == FR_OK)
	{
		f_close(&File);
		return 1;
	}
	
	return 0;
}

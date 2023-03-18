#include <iostream>


#include "include.h"

int main(int argc, const char * argv)
{
	HMODULE hCommon = nullptr;
	HMODULE hWinHTTP = nullptr;
	HMODULE hMemCtrl = nullptr;

#if _WIN64
	hCommon = LoadLibraryA("WinSysCommonx64.dll");
	hWinHTTP = LoadLibraryA("WinSysHTTPx64.dll");
	hMemCtrl = LoadLibraryA("WinSysMemCtrlx64.dll");
#else
	hCommon = LoadLibraryA("WinSysCommon.dll");
	hWinHTTP = LoadLibraryA("WinSysHTTP.dll");
	hMemCtrl = LoadLibraryA("WinSysMemCtrl.dll");
#endif

	FileCtrl_API::fp_CopyFile mCopyFile = (FileCtrl_API::fp_CopyFile)GetProcAddress(hCommon, "CopyFile");
	mCopyFile((char*)"D:\\asd.txt", (char*)"D:\\asd2.txt");

	return 0;
}

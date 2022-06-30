// RAMUsage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

int main()
{
	while (true) {
		system("CLS");
		cout << "RAM Usage - Console version. Written by Daniel Fros. \n\n";
		// TOTAL PHYSICAL MEMORY (RAM):
		MEMORYSTATUSEX memoryData;
		memoryData.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memoryData);
		DWORDLONG totalPhysMem = memoryData.ullTotalPhys;
		cout << "TOTAL PHYSICAL MEMORY AVAILABLE: " << totalPhysMem << "\n";

		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);

		// PHYSICAL MEMORY CURRENTLY USED
		DWORDLONG physMemMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
		int percentage = (physMemMemUsed * 100) / totalPhysMem;
		cout << "MEMORY CURRENTLY USED: " << physMemMemUsed << "(" << percentage << "%)" << "\n";

		// YOU CAN ADJUST UPDATE TIME
		Sleep(3000);
	}

	return 0;
}
// RAMUsage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

string StatusScreen(int percentage) {
	string LSTATUS = "[                  ]";

	if (percentage >= 10)
		LSTATUS = "[..                ]";
	if (percentage >= 20)
		LSTATUS = "[....              ]";
	if (percentage >= 40)
		LSTATUS = "[.......           ]";
	if (percentage >= 55)
		LSTATUS = "[.........         ]";
	if (percentage >= 60)
		LSTATUS = "[..........        ]";
	if (percentage >= 65)
		LSTATUS = "[...........       ]";
	if (percentage >= 75)
		LSTATUS = "[.............     ]";
	if (percentage >= 80)
		LSTATUS = "[................  ]";
	if (percentage >= 90)
		LSTATUS = "[................. ]";

	return LSTATUS;
}

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
		cout << "TOTAL PHYSICAL MEMORY AVAILABLE: " << totalPhysMem << "KB" << "\n";

		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);

		// PHYSICAL MEMORY CURRENTLY USED
		DWORDLONG physMemMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
		int percentage = (physMemMemUsed * 100) / totalPhysMem;
		cout << "MEMORY CURRENTLY USED: " << physMemMemUsed << "KB" << "(" << percentage << "%)" << " " << StatusScreen(percentage) << endl;

		// YOU CAN ADJUST UPDATE TIME
		Sleep(3000);
	}

	return 0;
}
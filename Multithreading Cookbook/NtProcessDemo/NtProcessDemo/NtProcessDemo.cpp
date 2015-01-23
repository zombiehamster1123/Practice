// NtProcessDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <winternl.h>
#include <iostream>

using namespace std;

typedef NTSTATUS(NTAPI* QUERYINFORMATIONPROCESS) (
	IN	HANDLE ProcessHandle,
	IN	PROCESSINFOCLASS ProcessInformationClass,
	OUT	PVOID ProcessInformation,
	IN	ULONG ProcessInformationLength,
	OUT	PULONG ReturnLength OPTIONAL
);

int _tmain(int argc, _TCHAR* argv[])
{
	STARTUPINFO startupinfo = { 0 };
	PROCESS_INFORMATION processInformation = { 0 };

	bool bSuccess = CreateProcess(
		TEXT("C:\\Windows\\notepad.exe"), NULL, NULL,
		NULL, FALSE, NULL, NULL, NULL, &startupinfo,
		&processInformation);

	if (bSuccess)
	{
		cout << "Proccess started." << endl << "Process ID:\t"
			<< processInformation.dwProcessId << endl;

		PROCESS_BASIC_INFORMATION pbi;
		ULONG uLength = 0;

		HMODULE hDll = LoadLibrary(
			TEXT("C:\\Windows\\System32\\ntdll.dll"));

		if (hDll)
		{
			QUERYINFORMATIONPROCESS QueryInformationProcess =
				(QUERYINFORMATIONPROCESS)GetProcAddress(
				hDll, "NtQueryInformationProcess");

			if (QueryInformationProcess)
			{
				NTSTATUS ntStatus = QueryInformationProcess(
					processInformation.hProcess,
					PROCESSINFOCLASS::ProcessBasicInformation,
					&pbi, sizeof(pbi), &uLength);

				if (NT_SUCCESS(ntStatus))
					cout << "Process ID (from PCB):\t"
					<< pbi.UniqueProcessId << endl;
				else
					cout << "Cannot open PCB!" << endl
					<< "error code:\t" << GetLastError()
					<< endl;
			}
			else
				cout << "Cannot get "
				<< "NtQueryInformationProcess function!"
				<< endl << "Error code:\t"
				<< GetLastError() << endl;

			FreeLibrary(hDll);
		}
		else
			cout << "Cannot load ntdll.dll!" << endl
			<< "Error code:\t" << GetLastError() << endl;
	}
	else
		cout << "Cannot start process!" << endl
		<< "Error code:\t" << GetLastError() << endl;

	return 0;
}


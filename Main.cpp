#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
 
    DWORD processId;
    cout << "Enter the process ID: ";
    cin >> processId;
 HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, false, processId);
 cout << "Enter the value: ";
 int value = 0;
 cin >> value;
 cout << "Enter offset: ";
 LPVOID offset;
 cin >> offset;
    
    int Writing = WriteProcessMemory(process, (LPVOID)offset, &value, (DWORD)sizeof(value), 0);
    CloseHandle(process);
    return 0;

}

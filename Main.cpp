#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
  //Создаем перемнную для хранения PID(Айди процесса)
    DWORD processId;
    //Выводим текст
    cout << "Enter the process ID: ";
    //Получаем айди процесса
    cin >> processId;
    //Открываем процесс по айди
 HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, false, processId);
 //Проверка удалось ли открыть процесс,если нет - выводим ошибку
 if (process == NULL)
 {
    //Выводим текст
     cout << "Unable to open process. Error: -1\n";
     cout << "The program has finished working with code -1.\nPress any key: ";
     //Получаем нажатие любой клавиши
     cin;
     //Возвращаем код -1
   return -1;
 }
 //Если процесс удалось открыть
 else
 {
     //Выводим текст
     cout << "Enter the value: ";
     //Создаем переменную для хранения значения на которое хотим изменить существуещее значение
     int value = 0;
     //Получаем значение
     cin >> value;
     //Выводим текст
     cout << "Enter offset: ";
     //Создаем перемнную типа LPVOID для хранения адресса в памяти(Оффсета)
     LPVOID offset;
     //Получаем оффсет
     cin >> offset;
     //Записываем в память процесса наше значение
     int Writing = WriteProcessMemory(process, (LPVOID)offset, &value, (DWORD)sizeof(value), 0);
     //Если мы удачно всё записали выводим сообщение
     if (Writing > 0)
     {
         cout << "Operation is successful\n";
     }
     //Если мы ничего не записали выводим ошибку
     else
     {
         cout << "Operation is failed\n";
     }
     //Закрываем процесс
     CloseHandle(process);
    //Выводим текст о том,что программа успешно выполнила код
     cout << "The program has finished working.\nPress any key: ";
     //Получаем любую клавишу
     cin;
   
 }


}

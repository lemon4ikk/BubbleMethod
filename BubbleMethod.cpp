#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");    // RU локализация консоли

    srand(1234);    // инициализация генератора псевдослучайных чисел

    const int size = 64; // инициализация константы, которая отвечает за размер массива
    int arr[size];  // инициализация массива c заданым ранее размером
    
    char path_unsorted[] = "Unsorted.csv"; // Инициализация переменной, которая хранит название файла с неотсортрованным массивом 
    char path_sorted[] = "Sorted.csv";  // Инициализация переменной, которая хранит название файла с отсортрованным массивом 

    fstream unsorted, sorted;   // Создание объектов file и resaults класса fstream           

        unsorted.open(path_unsorted, fstream::trunc | fstream::in | fstream::out);      // Создание метода open и передача ему параметров trunc, in и out для объекта unsorted
        sorted.open(path_sorted, fstream::trunc | fstream::in | fstream::out);      // Создание метода open и передача ему параметров trunc, in и out для объекта sorted                            

        if (!unsorted.is_open())        // Проверка  условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
             cout << "Файл открыт!" << endl;
                for (int i = 0; i < size; i++)      // Заполнение массива случайными значениями от 0 до 100
                {   
                    arr[i] = rand() % 100;
                    unsorted << arr[i] << "\n";
                }

                for (int i = 0; i < size; i++)      // Сортировка
                {
                    for (int j = 0; j < size - 1; j++)
                    {
                        int buffer = arr[j+1];

                        if (arr[j] > arr[j+1]) 
                        {
                        arr[j+1] = arr [j];
                        arr[j] = buffer;
                        }
                    }
                }
        }
            
        if (!sorted.is_open())                                        // Проверка условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else
        {
            for (int i = 0; i < size; i++) 
                {
                    sorted << arr[i] << "\n";   // Заполнение файла данными
                }

                cout << "Данные в файле!";
        }

        unsorted.close();   // Закрытие файлов при помощи метода close
        sorted.close();

    return 0;
}

#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    srand(1234);

    const int size = 64;
    int arr[size];
    
    char path_unsorted[] = "Unsorted.csv";
    char path_sorted[] = "Sorted.csv";

    fstream unsorted, sorted;                                                       
        unsorted.open(path_unsorted, fstream::trunc | fstream::in | fstream::out);      
        sorted.open(path_sorted, fstream::trunc | fstream::in | fstream::out);                             

        if (!unsorted.is_open())
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
             cout << "Файл открыт!" << endl;
                for (int i = 0; i < size; i++) 
                {   
                    arr[i] = rand() % 100;
                    unsorted << arr[i] << "\n";
                }

                for (int i = 0; i < size; i++) 
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

                for (int i = 0; i < size; i++) 
                {
                    sorted << arr[i] << "\n";
                }

                cout << "Данные в файле!";
        }
            
        unsorted.close();
        sorted.close();

    return 0;
}
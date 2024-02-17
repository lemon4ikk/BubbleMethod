#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    srand(time(NULL));

    const int size = 64;
    int arr[size];
    
    char path[] = "Unsorted.csv";
    char path2[] = "Sorted.csv";

    fstream file, sort;                                                       
        file.open(path, fstream::trunc | fstream::in | fstream::out);      
        sort.open(path2, fstream::trunc | fstream::in | fstream::out);                             

        if (!file.is_open())
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
             cout << "Файл открыт!" << endl;
                for (int i = 0; i < size; i++) 
                {   
                    arr[i] = rand() % 100;
                    file << arr[i] << "\n";
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
                    sort << arr[i] << "\n";
                }

                cout << "Данные в файле!";
        }
            
        file.close();
        sort.close();

    return 0;
}
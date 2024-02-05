#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    srand(time(NULL));

    const int size = 64;
    int arr[size];
    
    char path[] = "bubble.csv";

    fstream file;                                                       
        file.open(path, fstream::trunc | fstream::in | fstream::out);                                  

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
                    file << arr[i] << ";";
                }

                file << "\n";

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
                    file  << arr[i] << ";";
                }

                cout << "Данные в файле!";
        }
            
        file.close();

    return 0;
}
#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

void function1(int* array, int size)
{
    for(int i=0 ; i<size ; i++)
    {
        int value= rand()%size;
        for(int j=0; j<i; ++j){
            if(array[j] == value)
            {
                value = rand() % size;
                j=-1;
            }
        }
        array[i] = value;
    }
}


void function2 (int* array, int size){
    bool used[size];
    int val1 = rand()%size;
    array[0] = val1;
    used[val1] = true;
    for(int i=1 ; i<size ; i++)
        while (true)
        {
            int value = rand()%size+1;
            if(used[value] == true)
                continue;
            else
                array[i] = value;
                used[value] = true;
                break;
        }
    }
void function3(int* array, int size){
    // Complexity: O(N)
    for(int i=0 ; i<size ; ++i){
        array[i] = i+1;
    }
    for(int i=1 ; i<size ; ++i)
    {
        int value = rand()%i;
        swap(array[i], array[value]);
    }
}
void displayArray(int* array, int size){
    cout <<"[ ";
    for(int i=0 ; i<size-1 ; ++i)
        cout << array[i] << ", ";
    cout << array[size-1] <<" ]";
}   
int main(){
    int N[7] = {250, 500, 1000, 2000, 4000, 8000, 1600};
    cout << setw(7) << "|";
    for(int i=0; i<7; ++i)
        cout << setw(7) << N[i] <<"|";
    cout<< endl;
    //for loop to display the running time of the algorithm 1 with the different sizes in the array N
    cout << setw(7) << "Algo1 |";
    for(int i=0; i<7; ++i)
    {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::high_resolution_clock::now();
        int arr[N[i]];
        function1(arr, N[i]);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        cout << fixed << setprecision(2) << elapsed_seconds.count() * pow(10, 3) <<" |"; 
    }
    cout << endl;

    return 0;
}
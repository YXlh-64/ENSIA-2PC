#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

int *randomArray(int size)
{
    int *array = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
    return array;
}

void displayArray(int *array, int size)
{
    cout << "the array is: [ " << array[0];
    for (int i = 1; i < size; i++)
        cout << " , " << array[i];
    cout << " ] " << endl;
}
// worst case for the bubble sort is when we want to sort in ascending order where it's sorted in descending order
void bubbleSort(int *array, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        // optimize the algorthim which get sorted before the worst case
        int permut = false;
        for (int j = 0; j < size - 1 - i; j++)
            if (array[j] < array[j + 1])
            {
                swap(array[j], array[j + 1]);
                permut = true;
            }
        // if no changes has been applied to the array (i.e the array is sorted)
        if (!permut)
            return;
    }
}

int return_kth(int kth, int *array)
{
    return array[kth - 1];
}

int main()
{
    /*Write a program to solve the selection problem. The selection problem
determines the Kth largest
element from a set of N numbers. One way to solve this problem is as follows:
1. Initialize an array of size N with elements
2. Apply bubble sort in descending order to the elements
3. Return the Kth element from the array
Let k = N/2. Draw a table showing the running time of your program for
increasing values of
N , for example N = 10, N = 100, N = 1000, N = 10000, etc. What do you notice?
N.B. you can fill the array using the random function rand().*/
    /*     int* array, size;
        cout << "Enter the size of the array: " <<endl;
        cin >> size;
        array =  randomArray(size);
        cout << "the array before modification is:" << endl;
        displayArray(array, size) ;
        cout << "the array after modification is: "<<endl;
        bubbleSort(array, size);
        displayArray(array, size); */

    // keep track of the running time of the program for different sizes of the array
    cout << setw(20) << "Size of the array " << setw(20) << "The running time" << endl;
    int duration[6] = {10, 100, 1000, 10000, 100000, 1000000};
    for (int i = 0; i < 6; i++)
    {
        std::chrono::time_point<std::chrono::system_clock> start, end; //auto start, end
        start = std::chrono::system_clock::now(); //chrono::high_resolution_clock::now
        int *array;
        array = randomArray(duration[i]);
        bubbleSort(array, duration[i]);
        int kth_element = return_kth(i / 2, array);
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        //auto duration = chrono::duration_cast<milliseconds> (end-start);
        cout << setw(19) << duration[i] << setw(21) << fixed << setprecision(7) << elapsed_seconds.count() << endl;
        delete array;
    }
    // delete[] array;
    return 0;
}
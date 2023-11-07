#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int find_kth(int nb_elements, int arr[], int kth)
{
    for (int i = 0; i < nb_elements; i++)
    {
        for (int j = 0; j < nb_elements - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr[kth - 1];
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
    srand(time(0));
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
        cout << arr[i] << endl;
    }
    int kth = 5;
    cout << "the " << kth << " position is " << find_kth(size, arr, kth);
    return 0;
}
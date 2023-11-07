#include <iostream>
#include <iomanip>
#include <chrono>

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

int function_1(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
        ++sum;
    return sum;
}

int function_2(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            sum++;
    return sum;
}

int function_3(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size * size; j++)
            sum++;
    return size;
}

int function_4(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < i; ++j)
            ++sum;
    return sum;
}

int function_5(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < i * i; ++j)
            for (int k = 0; k < j; ++k)
                ++sum;
    return sum;
}

int function_6(int *array, int size)
{
    int sum = 0;
    for (int i = 1; i < size; ++i)
        for (int j = 1; j < i * i; ++j)
            if (j % i == 0)
                for (int k = 0; k < j; ++k)
                    ++sum;
    return sum;
}

int main()
{
    // setting a seed
    srand(time(0));
    // 1. Giving an analysis of the running time (O(n))
    //(1). O(1)+(n+1)O(1) = O(n) => linear
    //(2). O(1)+(n+1)O(1)*(n+1) = O(1)+(n+1)² = n²+1+2*n = O(n²) => quadratic
    //(3). O(1)+(n²+1)*2*O(1)*(n+1) = (n²+1)*(n+1) = n^3+n²+n+1 = O(n^3) => cubic
    //(4). O(1)+sum from i=0 to i=n of (i+1)*O(1) = 1/2*(n+1)*(n+2) = O(n²) => quadratic
    //(5). O(1)+1/3*n^6 + 1/2*n^4 + 1/2n^3 + 11/12n² + 5/4*n + 1 = O(n^6)
    //(6). O(6) the exact same as the previous one
    int sizes[4] = {10, 100, 1000, 10000};
    cout << setw(18) << " Algorithm 1 |" << setw(12) << " Algorithm 2 |"
         << setw(12) << " Algorithm 3 |" << setw(12) << " Algorithm 4 |" << setw(12) << " Algorithm 5 |"
         << setw(12) << " Algorithm 6 |" << endl;

    for (int i = 0; i < 4; ++i)
    {
        cout << setw(3) << sizes[i];
        for (int j = 0; j < 6; ++j)
        {
            std::chrono::time_point<std::chrono::system_clock> start, end;
            start = std::chrono::system_clock::now();
            int *array;
            array = randomArray(i);
            if (j == 0){
                function_1(array, sizes[i]);
                end = std::chrono::system_clock::now();
                std::chrono::duration <double> seconds = end - start;
                cout << setw(12) << setprecision(5) << fixed << seconds.count() << "s |";
                continue;
            }
            else if (j == 1)
                function_2(array, sizes[i]);
            else if (j == 2)
                function_3(array, sizes[i]);
            else if (j == 3)
                function_4(array, sizes[i]);
            else if(j == 4)
                function_5(array, sizes[i]);
            else
                function_6(array, sizes[i]);
            end = std::chrono::system_clock::now();
            std::chrono::duration <double> seconds = end - start;
            cout << setw(11) << setprecision(5) << fixed << seconds.count() << "s |";
            delete array;
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
/* //Write a recursive function that returns the number of 1 in the binary
representation of N . Use the fact that this is equal to the number of 1
 in the representation of N/2, plus 1 if N is odd. */
int count_one(int num)
{
    // base case
    if (num == 1)
        return 1;

    // making progress
    if (num % 2 == 0)
    {
        return count_one(num / 2);
    }
    else
    {
        return 1 + count_one(num / 2);
    }
}

int main()
{
    int num;
    cout << "enter the number which you wanted to see how many ones the binary \
    representation contains"
         << endl;
    cin >> num;
    cout << "the number of 1s in the binary representation of the number " << num << " is " << count_one(num);
    return 0;
}
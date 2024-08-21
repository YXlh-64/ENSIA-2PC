#include <iostream>
#include <cmath>

using namespace std;

bool if_prime(int num){
    /*If the number is not prime, any factor greater than 
    the square root has to be combined with a factor smaller than the
    square root to obtain the number. So it suffices to check 
    if a number smaller than the square root divides our number*/
    for(int i=2; i<=sqrt(num) ; i++)
        if(num%i == 0)
            return false;
    return true;
    // complexity of the algorithm is O(sqrt(n))
}

int count_bin_digits(int num){
    //base case
    if(num<=1)
        return 1;
    return (1+count_bin_digits(num/2));
}
int main(){
    //the worst case of running the program 
    //in terms of N is O(sqrt(N))
    int num;
    cout << "enter a number" <<endl;
    cin >> num;
    cout <<"the number is prime ? "<<if_prime(num) <<endl;
    // B=O(num)
    // In terms of B, what is the worst-case running time of your program?
    int num;
    cout << "enter a number" <<endl;
    cin >> num;

    return 0;
}
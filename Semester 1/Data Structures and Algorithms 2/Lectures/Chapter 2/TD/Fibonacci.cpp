#include <iostream>
using namespace std;
// below are two different algorithms for computing fibonacci numbers
//first, iteratively
int iteratively(int num){
    int F0 = 1;
    int F1 = 1;
    int F2;
    for(int i=2; i<=num; ++i){
        F2 = F0 + F1;
        F0 = F1;
        F1 = F2;
    }
    return F2;
}

//second, recursively
int recursively(int num){
    if(num < 2) return 1;
    return recursively(num-1) + recursively(num-2);
}
int main(){
    int num;
    cout << "enter the number which you wanted to calculate its corresponding Fibonacci equivalent: " << endl;
    cin >> num;
    cout << "The fibonacci number is : recursively " << recursively(num) << " iteratively: " << iteratively(num) << endl;
    return 0;
}
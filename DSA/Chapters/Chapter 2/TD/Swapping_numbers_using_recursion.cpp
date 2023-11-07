#include <iostream>
using namespace std;

/*The following function does the exact same
int swap_number(int num){
    static int sum = 0;
    if(num < 10)
        return sum + num;
    else    
        sum = (sum+num%10)*10;
        return swap_number(num/10);
}
*/
int swap_number(int num, int sum = 0){
    if(num < 10)
        return sum + num;
    else    
        return swap_number(num/10, (sum+num%10)*10);
}
int main(){
    const int test = 1246547;
    cout << swap_number(test);
    return 0;
}
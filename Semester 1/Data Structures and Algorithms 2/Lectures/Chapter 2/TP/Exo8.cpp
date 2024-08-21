#include <iostream>
#include <chrono>
using namespace std;
//Complexity: O(N)
bool function(int* array, int N){
    for(int i=0 ; i<N ; ++i)
    {
        if(i == array[i])
            return true;
    }
    return false;
}
int main(){
    srand(time(0));
    
    return 0;
}
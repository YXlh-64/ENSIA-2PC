#include <iostream>
#include <vector>
using namespace std;

//Implement the binary search algorithm using only one two-way comparison
int find_value(const vector <int>& arr, int value, int start, int end){
    if(start == end){
        return (arr[end] == value)? end: -1;
    }
    int center = (end-start) / 2 + start;
    if(value < arr[center]) return find_value(arr, value, start, center);
    return (value > arr[center]) ? find_value(arr, value, center+1, end) : center;
}
int main(){
    vector <int> arr = {12, 34, 45, 67, 80, 82, 90};
    cout << find_value(arr, 45, 0, 6);
    return 0;
}
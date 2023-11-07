#include <iostream>
#include <vector>
using namespace std;
int find_value(const vector <int>& arr, int value, int start, int end){
    if(start == end){
        return (arr[end] == value)? end: -1;
    }
    int center = (end-start) / 2 + start;
    if(value < arr[center])
        return find_value(arr, value, start, center);
    if(value > arr[center])
        return find_value(arr, value, center+1, end);
    return center;
}
//complexity analysis:
// THe base-case: we have when n=1, T(1)=1
// For n>=2, T(n)=1+Bookkeping operations + T(n/2) = c+ T(n/2) (with c representing a constant time)
//  We have T(n)=c+T(n/2) = c + (c+ T(n/4))) = 2*c+T(n/2^2) = 2*c + (c + T(n/2^3)) = 3*c + T(n/2^3) = ... = i*c + T(n/2^i)
// The algorithm finishes when the base case is reached, i.e. T(n/2^i)=T(1) => 2^i = n => i = log(n)
// Thus, T(n) = log(n)*c + T(n/n) = c*log(n) + 1 = O(log(n))
// Note, in this case we haven't ignored the cost of the basic operations because there's nothing on which 
// the constant cost is ignored (remember in the maximum subsequence problem, we had O(n) that is why the cost
// of the constant operations wasn't taken into account)
int main(){
    vector <int> arr = {0, 2, 4, 6, 9};
    int value;
        cout << "Enter the value you wanted to find its index within the vector: "<<endl;
        cin >> value;
        cout << "The index of the value "<<value<<" is: " <<find_value(arr, value, 0, arr.size()-1)<<endl;
    return 0;
}
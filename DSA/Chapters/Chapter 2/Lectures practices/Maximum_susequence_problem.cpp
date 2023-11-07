#include <iostream>
#include <vector>
using namespace std;
//function to help determine the maximum between three integers
int max3(int v1, int v2, int v3){
    if(v1>=v2) return v1;
    if(v2>=v3) return v2;
    return v3;
}
// algorithm 1 of complexity O(N^3) => cubic
int algo1(vector<int> &arr)
{
    int max_sum = 0;
    for (int i = 0; i < arr.size(); i++)
        for (int j = i; j < arr.size(); j++)
        {
            int thisSum = 0;
            for (int k = i; k <= j; k++)
                thisSum += arr[k];

            if (thisSum > max_sum)
                max_sum = thisSum;
        }
    return max_sum;
}
// algorithm 2 of complexity O(N²) => quadratic
int algo2 (vector <int> &arr)
{
    int max_sum = 0;
    for (int i = 0 ; arr.size() ; i++){
        int this_sum = 0;
        for (int j=i ; j<arr.size() ; j++){
            this_sum += arr[j];
            if(this_sum > max_sum)
                max_sum = this_sum;
        }
    }
    return max_sum;
}
//algorithm 3 uses divide and conquer approach
int algo3 (int start, int end, vector<int>& arr){
    if(start==end){
        if(arr[start]>0)
            return arr[start];
        return 0;
    }
    int center= (start+end)/2;
    int maxRightSum = algo3(start, center, arr);
    int maxLeftSum = algo3(center+1, end, arr);
    //in the case where the maxLeftSum doesn't reach the left border and
    //the maxRightSum does not reach the right border
    int maxLeftBorderSum=0, leftBorderSum = 0;
    for(int i=center; i>start; --i)
    {
        leftBorderSum += arr[i];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum=0, rightBorderSum = 0;
    for(int i=center+1; i<end; ++i)
    {
        rightBorderSum += arr[i];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    return max3(maxLeftSum, maxRightSum,
     maxRightBorderSum + maxLeftBorderSum);
}
/*Algorithm3 complexity analysis:
* N always represents the size of the array,
* For n=1, T(1)=1
* For n>=2, T(n)= two recursive calls + some bookkeeping operations
+ two for loops, assuming N is even, we get:
    * The two recursive calls 2*T(n/2)
    * The two for loops are obviously O(n/2)+O(n/2) = 2*O(n/2) = O(n)
    * The bookkeeping operations are ignored compared to O(n)
* Therefore, T(n)= T(n/2)+T(n/2)+O(n/2)+O(n/2) => T(n)=2*T(n/2)+O(n)
For simplicity we'll represent O(n) as c*n where c is constant (by definition of big-Oh notation)
We have:
    T(1) = 1
    for n>=2, we have:
        T(n)=2*T(n/2)+c*n
    since T(n/2)=2*T(n/4)+c*(n/2), then:
        T(n)=2*(2*T(n/4)+c*n/2)+c*n = 4*T(n/4)+2*c*n
            =4*(2*T(n/8)+c*n/4)+2*c*n = 8*T(n/8)+3*c*n
            =8*(2*T(n/16)+c*n/8)+3*c*n = 16*T(n/16)+4*c*n
            .
            .
            .
        T(n)=2^i*T(n/2^i)+(i)*c*n
    When the base case is reached, the algorithm finishes, thus T(n/2^i)=T(1)=1, therefore 
    n/2^i=1 => n=2^i =>i=log(n)
    Thus, T(n)=2^(log(n))*1 + log(n)*c*n = 1+c*n*log(n) = O(n*log(n))
!*/
int algo4(const vector<int>& arr){
    int thisSum= 0, maxSum= 0;
    for(int i=0; i<arr.size(); ++i){
        thisSum+= arr[i];
        if(thisSum > maxSum)
            maxSum=thisSum;
        else if(thisSum < 0)
            thisSum=0;
    }
    return thisSum;
}   
/*Algorithm4 complexity analysis
T(n) = O(n) the most optimal solution is algo4!
*/
int main()
{

    vector<int> arr = {-12, -2};
    cout << "the maximum subsequence sum is: " << algo3(0, arr.size(), arr);
    return 0;
}
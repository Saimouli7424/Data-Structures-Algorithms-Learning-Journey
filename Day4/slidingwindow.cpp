#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> &array,int k){
    int maxsum =0, currentsum = 0;
    for(int i=0; i<k; i++)
    {
        currentsum += array[i];
    }
    maxsum = currentsum;

    for(int i=k; i<array.size(); i++)
    {
        currentsum+= array[i] - array[i-k];
        maxsum = max(maxsum,currentsum);
    }
    return maxsum;
}

int main(){
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Max sum of subarray of size " << k << " is " << maxSumSubarray(nums, k);
    return 0;
}
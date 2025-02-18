#include<bits/stdc++.h>
using namespace std;
bool twoSumSorted(vector<int> &arr, int target)
{
    int left =0;
    int right = arr.size()-1;
    while(left<right)
    {
        int sum = arr[left]+arr[right];
        if(sum==target){
            return true;
        }
        if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}
int main(){
    vector<int> nums = {1, 2, 3, 4, 6, 8, 9};
    int target = 10;
    cout << (twoSumSorted(nums, target) ? "Pair found" : "No pair found");
    return 0;
}
//Find K Closest Elements(Medium)
//Using binary search
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
            //it will check the present mid-x element to the next k element
            //if the mid-x is greater than the next k element-x then it will move to the right side of the array
            //to find the nearest least element to x in the array
                left = mid + 1;
            else
                right = mid;
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
        //it will return nearest least elements to x in the array
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> result = sol.findClosestElements(nums, k, x);

    cout << "K closest elements to " << x << ": ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}

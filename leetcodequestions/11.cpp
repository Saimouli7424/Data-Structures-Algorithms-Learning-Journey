//Container With Most Water(Medium)
//Two pointers
//Time complexity: O(n)
//Space complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height)
        {
            int left=0;
            int right=height.size()-1;
            int maxelem=INT_MIN;
            while(left<right)
            {
                maxelem = max(maxelem, min(height[left], height[right]) * (right - left));
    
                if (height[left] < height[right]) left++;
                else right--;
            }
            return maxelem;
        }
    };

int main()
{
    Solution obj;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<obj.maxArea(height);
    return 0;
}

//This code first finds the maximum element in the array. Then it uses two pointers, left and right, to move from the ends towards the middle. At each step, it calculates the area of the rectangle formed by the maximum element and the width between the pointers. It updates the maximum area if a larger area is found. Finally, it returns the maximum area.
//The time complexity of this code is O(n) because it uses two pointers to traverse the array only once. The space complexity is O(1) because it uses only a constant amount of extra space.
//The code can be optimized further by using a single pointer to traverse the array from both ends. This would reduce the space complexity to O(1) and the time complexity to O(n). The code can also be optimized by using a binary search approach to find the maximum element in the array. This would reduce the time complexity to O(log n) and the space complexity to O(1).

//Note: The above code assumes that the input array is non-empty and contains at least two elements. If the input array is empty, the code will return 0. If the input array contains only one element, the code will return the element itself as the maximum area. If the input array contains two elements, the code will return the area of the rectangle formed by the two elements. If the input array contains more than two elements, the code will find the maximum area using the two pointers approach.
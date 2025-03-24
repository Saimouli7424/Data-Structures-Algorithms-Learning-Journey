/*
same of subarray problem finding minimum of maximum element
Problem statement
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.



Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.
*/

//using binarysearch and greedysearch

#include <bits/stdc++.h>
using namespace std;

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int low = *max_element(boards.begin(), boards.end());
    if (k == n)
        return low;
    int high = accumulate(boards.begin(), boards.end(), 0);

    auto ispossible = [&](int mid)
    {
        int arrayscount = 1;
        int sum = 0;
        for (int num : boards)
        {
            if (sum + num > mid)
            {
                arrayscount++;
                sum = num;
                if (arrayscount > k)
                    return false;
            }
            else
                sum += num;
        }
        return true;
    };

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (ispossible(mid))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> boards = {2, 1, 5, 6, 2, 3}; // Example input
    int k = 2; // Number of painters

    int result = findLargestMinDistance(boards, k);
    cout << "Largest Minimum Distance: " << result << endl;

    return 0;
}

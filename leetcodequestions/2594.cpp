//Minimum Time to Repair Cars(Medium)
//Binary Search

#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) 
        {
            long long left=1;
            long long minelem=*min_element(ranks.begin(),ranks.end());
            long long right=minelem*cars*cars;
    
            while(left<right)
            {
                long long mid=left+(right-left)/2;
                if(check(ranks,mid,cars))
                {
                    right=mid;
                }else
                {
                    left=mid+1;
                }
            }
            return left;
        }
    
        bool check(vector<int>& ranks, long long mid, int cars)
        {
            long long totalCars=0;
            for (int r : ranks) {
                totalCars += sqrt(mid / r);
                if (totalCars >= cars) return true;
            }
            return totalCars >= cars;
        }
    };

int main()
{
    Solution obj;
    vector<int> ranks={4,2,3};
    int cars=6;
    cout<<obj.repairCars(ranks,cars)<<endl;
    return 0;
}

/*
Example Input
cpp
Copy
Edit
ranks = {4, 2, 3};
cars = 6;
Understanding Mechanic Work
Rank 4 → Needs 4 * x² time for x cars.
Rank 2 → Needs 2 * x² time for x cars.
Rank 3 → Needs 3 * x² time for x cars.
We need to find the minimum time required to repair 6 cars.

Step 1: Setting Binary Search Boundaries
Left (left) = 1 (minimum possible time).
Right (right) = min(ranks) * cars^2 = 2 * (6^2) = 72 (worst-case time).
Binary search will find the smallest valid mid.
Step 2: Binary Search Process
We perform binary search on time, checking whether it's possible to repair cars in mid time.

Iteration 1
Calculate mid
cpp
Copy
Edit
mid = (left + right) / 2 = (1 + 72) / 2 = 36
Check If 36 Time is Enough (canRepairAll(36))
We calculate cars each mechanic can repair:

Mechanic Rank (r)	Calculation (sqrt(36 / r))	Cars Repaired
4	sqrt(36 / 4) = sqrt(9) = 3	3
2	sqrt(36 / 2) = sqrt(18) ≈ 4.24 → 4	4
3	sqrt(36 / 3) = sqrt(12) ≈ 3.46 → 3	3
Total cars repaired = 3 + 4 + 3 = 10 (≥ 6, so it's enough!)
➡ Update right = mid = 36 (try smaller time).

Iteration 2
Calculate mid
cpp
Copy
Edit
mid = (1 + 36) / 2 = 18
Check If 18 Time is Enough (canRepairAll(18))
Mechanic Rank (r)	Calculation (sqrt(18 / r))	Cars Repaired
4	sqrt(18 / 4) = sqrt(4.5) ≈ 2.12 → 2	2
2	sqrt(18 / 2) = sqrt(9) = 3	3
3	sqrt(18 / 3) = sqrt(6) ≈ 2.44 → 2	2
Total cars repaired = 2 + 3 + 2 = 7 (≥ 6, so it's enough!)
➡ Update right = mid = 18 (try smaller time).

Iteration 3
Calculate mid
cpp
Copy
Edit
mid = (1 + 18) / 2 = 9
Check If 9 Time is Enough (canRepairAll(9))
Mechanic Rank (r)	Calculation (sqrt(9 / r))	Cars Repaired
4	sqrt(9 / 4) = sqrt(2.25) ≈ 1.5 → 1	1
2	sqrt(9 / 2) = sqrt(4.5) ≈ 2.12 → 2	2
3	sqrt(9 / 3) = sqrt(3) ≈ 1.73 → 1	1
Total cars repaired = 1 + 2 + 1 = 4 (< 6, not enough!)
➡ Update left = mid + 1 = 10.

Iteration 4
Calculate mid
cpp
Copy
Edit
mid = (10 + 18) / 2 = 14
Check If 14 Time is Enough (canRepairAll(14))
Mechanic Rank (r)	Calculation (sqrt(14 / r))	Cars Repaired
4	sqrt(14 / 4) = sqrt(3.5) ≈ 1.87 → 1	1
2	sqrt(14 / 2) = sqrt(7) ≈ 2.64 → 2	2
3	sqrt(14 / 3) = sqrt(4.66) ≈ 2.16 → 2	2
Total cars repaired = 1 + 2 + 2 = 5 (< 6, not enough!)
➡ Update left = mid + 1 = 15.

Iteration 5
Calculate mid
cpp
Copy
Edit
mid = (15 + 18) / 2 = 16
Check If 16 Time is Enough (canRepairAll(16))
Mechanic Rank (r)	Calculation (sqrt(16 / r))	Cars Repaired
4	sqrt(16 / 4) = sqrt(4) = 2	2
2	sqrt(16 / 2) = sqrt(8) ≈ 2.83 → 2	2
3	sqrt(16 / 3) = sqrt(5.33) ≈ 2.3 → 2	2
Total cars repaired = 2 + 2 + 2 = 6 (≥ 6, enough!)
➡ Update right = mid = 16.

Final Condition
left == right == 16
Minimum time required to repair 6 cars is 16.
Final Output
cpp
Copy
Edit
return 16;
Summary of Binary Search Steps
Step	Left	Right	Mid	Can Repair in Mid?	Move Left or Right?
1	1	72	36	✅ Yes (10 cars)	right = 36
2	1	36	18	✅ Yes (7 cars)	right = 18
3	1	18	9	❌ No (4 cars)	left = 10
4	10	18	14	❌ No (5 cars)	left = 15
5	15	18	16	✅ Yes (6 cars)	right = 16
6	16	16	16	✅ Yes (6 cars)	Return 16
*/
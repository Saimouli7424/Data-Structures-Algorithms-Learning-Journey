//Boyer-Moore Majority voting algorithm
//it assumpts always an element has a frequency greater than n/2 times of array length


#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(vector<int>& nums) {
    int candidate = -1, count = 0;

    // Step 1: Find the candidate using Boyer-Moore
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Step 2: Verify if it's the majority element
    int freq = 0;
    for (int num : nums) {
        if (num == candidate) freq++;
    }

    return (freq > nums.size() / 2) ? candidate : -1;  // Return -1 if no majority
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 3, 3, 3, 1};
    cout << "Majority Element: " << findMajorityElement(nums) << endl;
    return 0;
}

// Step 1: 3 (count = 1)
// Step 2: 3 (count = 2)
// Step 3: 4 (count = 1) -> Decrement since it's different
// Step 4: 2 (count = 0) -> Reset
// Step 5: 3 (count = 1)
// Step 6: 3 (count = 2)
// Step 7: 3 (count = 3)
// Step 8: 1 (count = 2) -> Decrement


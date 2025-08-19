//Task Scheduler(Medium)
//Time complexity: O(nlogn)
//Space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int maxElem = 0;

        // Count frequencies
        for (auto i: tasks) {
            mp[i]++;
            maxElem = max(maxElem, mp[i]);
        }

        // Count how many tasks have frequency == maxElem
        int maxElemCount = 0;
        for (auto it: mp) {
            if (it.second == maxElem) maxElemCount++;
        }

        // Formula: max(total tasks, skeleton length)
        return max((int)tasks.size(), (maxElem - 1) * (n + 1) + maxElemCount);
    }
};

int main() {
    Solution sol;

    // Testcase 1
    vector<char> tasks1 = {'A','C','A','B','D','B'};
    int n1 = 1;
    cout << "Testcase 1: " << sol.leastInterval(tasks1, n1) << endl;
    // Expected 6

    // Testcase 2
    vector<char> tasks2 = {'A','A','A','B','B','B'};
    int n2 = 2;
    cout << "Testcase 2: " << sol.leastInterval(tasks2, n2) << endl;
    // Expected 8 (A B idle A B idle A B)

    // Testcase 3
    vector<char> tasks3 = {'A','A','A','B','B','B'};
    int n3 = 0;
    cout << "Testcase 3: " << sol.leastInterval(tasks3, n3) << endl;
    // Expected 6 (just place tasks back-to-back)

    return 0;
}
/*
We are working with the formula:

result=max(tasks.size(),(maxFreq−1)×(n+1)+maxCount)

Where:

maxFreq = the maximum frequency of any task

maxCount = how many tasks appear maxFreq times

n = cooldown period

Example:

Tasks = ["A","A","A","B","B","B"], n = 2

Step 1: Count frequencies

A → 3

B → 3
So, maxFreq = 3, maxCount = 2 (since both A and B have the same maximum frequency).

Step 2: Skeleton idea

We only think about the most frequent tasks first (A and B).

We know A appears 3 times.
Imagine building “skeleton slots” for A first:

A _ _ A _ _ A


👉 Each A is placed with (n=2) cooldown gaps between them.
👉 This gives us (maxFreq - 1) = 2 full skeleton blocks (the last A doesn’t need cooldown after it).
👉 Each block length = (n+1) = 3 slots.

So total slots from skeleton = (maxFreq - 1) * (n+1) = 2 * 3 = 6.

Step 3: Add last block

But wait — we had 2 tasks (A and B) tied for max frequency.
So in the very last “block,” both must appear. That’s why we add maxCount:

6+2=8

Skeleton now looks like:

A B _ A B _ A B


= 8 slots filled. ✅

Step 4: Compare with tasks.size()

tasks.size() = 6

formula gave = 8

Take the max → answer = 8

This is correct, because cooldown forced us to add idles.

Why “-1” in (maxFreq-1)?

Because the last repetition of the most frequent task does not need cooldown after it.
For example, after the last A, we don’t care what comes next.

Why “+ maxCount”?

Because in the final block of the skeleton, we may have multiple tasks with the maximum frequency, so all of them must fit in.

✅ So in short:

(maxFreq - 1) * (n+1) builds all blocks except the last row.

+ maxCount places the last batch of the most frequent tasks.
 */
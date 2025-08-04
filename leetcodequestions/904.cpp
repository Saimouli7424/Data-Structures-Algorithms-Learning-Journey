// Fruit Into Baskets(Medium)
//time complexity is O(n)
//space complexity is O(1)
//using two pointers technique to keep track of the last two types of fruits and their counts
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lastFruit = -1, secondLastFruit = -1;
        int lastFruitCount = 0;
        int maxCount = 0, curCount = 0;

        for (int fruit : fruits) {
            if (fruit == lastFruit || fruit == secondLastFruit) {
                curCount++;
            } else {
                curCount = lastFruitCount + 1;
            }

            if (fruit == lastFruit) {
                lastFruitCount++;
            } else {
                lastFruitCount = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }

            maxCount = max(maxCount, curCount);
        }
        return maxCount;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 2, 1},
        {0, 1, 2, 2},
        {1, 2, 3, 2, 2},
        {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        for (int f : testCases[i]) cout << f << " ";
        cout << "\nOutput: " << sol.totalFruit(testCases[i]) << "\n\n";
    }

    return 0;
}

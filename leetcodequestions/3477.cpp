//Fruits Into Baskets II(Easy)
//Time complexity: O(n)
//Space complexity: O(1)
#include <iostream>
#include <vector>
using namespace std;
int totalFruits(vector<int>& fruits) {
    int n = fruits.size();
    if (n == 0) return 0;

    int maxFruits = 0;
    int left = 0, right = 0;
    int fruitCount[30001] = {0}; // Assuming fruit types are in the range [0, 30000]

    while (right < n) {
        fruitCount[fruits[right]]++;

        while (fruitCount[fruits[right]] > 2) {
            fruitCount[fruits[left]]--;
            left++;
        }

        maxFruits = max(maxFruits, right - left + 1);
        right++;
    }

    return maxFruits;
}
int main() {
    vector<int> fruits = {1, 2, 1, 2, 3, 4, 5, 1, 2};
    cout << "Maximum number of fruits in two baskets: " << totalFruits(fruits) << endl;
    return 0;
}

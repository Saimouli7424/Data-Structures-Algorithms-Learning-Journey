//Fruits Into Baskets II(Easy)
//Time complexity: O(n)
//Space complexity: O(1)
#include <iostream>
#include <vector>
using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    vector<bool> used(n, false);
    int unplaced = n;
    for (int x : fruits) {
        for (int i = 0; i < n; ++i) {
            if (baskets[i] >= x && !used[i]) {
                used[i] = true;
                --unplaced;
                break;
            }
        }
    }
    return unplaced;
}

int main() {
    vector<int> fruits = {4,2,5};
    vector<int> baskets = {3,5,2};
    cout << "Maximum number of fruits in two baskets: " << numOfUnplacedFruits(fruits,baskets) << endl;
    return 0;
}

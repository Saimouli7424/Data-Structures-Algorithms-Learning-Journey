//have to find the unique values of marbles in the bag
//using BFS to find the unique values of marbles in the bag
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int MarbleCount(int input1,int input2,int input3)
    {
        queue<pair<int,int>> q;
        set<int> unique;
        unique.insert(input1);
        // int count=0;
        q.push({input1,input2});
        q.push({input1,input3});

        while(!q.empty())
        {
            pair<int,int> p=q.front();
            int BagSize = p.first;
            int Operation = p.second;
            int diff = BagSize - Operation;
            q.pop();
            if(diff>0 && unique.find(diff)==unique.end())
            {
                // count++;
                unique.insert(diff);
                q.push({diff,input2});
                q.push({diff,input3});
            }
        }
        return unique.size();
    }
};

int main() {
    Solution solution;
    int input1 = 4;
    int input2 = 1;
    int input3 = 2;
    cout << "Total unique values of marbles in the bag: " << solution.MarbleCount(input1, input2, input3) << endl;//4
    // Test case
    int input4 = 10;
    int input5 = 3;
    int input6 = 4;
    cout << "Total unique values of marbles in the bag: " << solution.MarbleCount(input4, input5, input6) << endl;//7
    // Test case
    int input7 = 20;
    int input8 = 5;
    int input9 = 7;
    cout << "Total unique values of marbles in the bag: " << solution.MarbleCount(input7, input8, input9) << endl;//9
    return 0;
}
//
// The code implements a BFS algorithm to find the unique values of marbles in a bag. It uses a queue to explore the possible values and a set to keep track of unique values. The main function tests the implementation with example inputs.
// The BFS algorithm ensures that all possible values are explored, and the set guarantees that only unique values are counted. The final result is printed to the console.
// The code is efficient and handles the problem requirements effectively. The use of BFS allows for a systematic exploration of the possible values, ensuring that all unique values are found without duplicates.
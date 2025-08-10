//Asteroid Collision(Medium)
//using stack
//time complexity: O(n), space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (auto i : asteroids) {
            bool destroyed = false;

            while (!s.empty() && s.top() > 0 && i < 0) {
                if (abs(s.top()) == abs(i)) {
                    s.pop();
                    destroyed = true;
                    break;
                }
                else if (abs(s.top()) > abs(i)) {
                    destroyed = true;
                    break;
                }
                else {
                    s.pop();
                }
            }

            if (!destroyed) {
                s.push(i);
            }
        }

        vector<int> result;
        while (!s.empty()) {
            result.emplace_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    Solution sol;
    vector<int> asteroids = {8,-8};
    vector<int> result = sol.asteroidCollision(asteroids);
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;
    return 0;
}
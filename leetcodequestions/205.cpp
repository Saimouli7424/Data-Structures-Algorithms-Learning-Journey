//Isomorphic Strings
//Using Unordered Map
//Time Complexity: O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for(int i = 0; i < s.length(); i++) {
            char sc = s[i], tc = t[i];

            if((s_to_t.count(sc) && s_to_t[sc] != tc) ||
               (t_to_s.count(tc) && t_to_s[tc] != sc)) {
                return false;
            }

            s_to_t[sc] = tc;
            t_to_s[tc] = sc;
        }
        return true;
    }
};

int main() {
    Solution sol;

    string s1 = "egg";
    string t1 = "add";
    cout << "Isomorphic (egg, add)? " << (sol.isIsomorphic(s1, t1) ? "Yes" : "No") << endl;

    string s2 = "foo";
    string t2 = "bar";
    cout << "Isomorphic (foo, bar)? " << (sol.isIsomorphic(s2, t2) ? "Yes" : "No") << endl;

    string s3 = "paper";
    string t3 = "title";
    cout << "Isomorphic (paper, title)? " << (sol.isIsomorphic(s3, t3) ? "Yes" : "No") << endl;

    return 0;
}

//Count Unique Characters of All Substrings of a Given String(Hard)
//using contribution technique of each character in the string
/*
    Data Structures and Algorithms Used
    1. Data Structures Used
    ✅ Unordered Map (unordered_map<char, vector<int>>)

    Used to store the character positions in the string.

    Key: Character (char)

    Value: A vector of indices where the character appears.

    ✅ Vector (vector<int>)

    Used to store all occurrences of each character in the string.

    We modify it by inserting -1 at the beginning and n at the end to simplify boundary calculations.

    2. Algorithms Used
    ✅ Preprocessing Step (O(n))

    Looping over the string to store character indices in unordered_map.

    This takes O(n) time.

    ✅ Contribution Calculation (O(n))

    Iterating through each character's positions and computing its contribution.

    Since every character occurs at most n times, this step is also O(n).

    ✅ Final Complexity: O(n)

    The overall complexity is O(n), making it very efficient for large strings.

    Key Idea of the Algorithm
    Each unique character at position i contributes to multiple substrings.

    The formula (current - prev) * (next - current) counts all substrings where s[i] is the only occurrence of that character.

    By using unordered_map and vectors, we efficiently track character positions and compute their contributions.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s)
    {
        unordered_map<char, vector<int>> index;
        int n = s.size();
        
        // Step 1: Store indices of each character
        for (int i = 0; i < n; i++) {
            index[s[i]].push_back(i);
        }

        int count = 0;
        
        // Step 2: Calculate contribution of each character
        for(auto& [ch, positions]: index){
            positions.insert(positions.begin(), -1);
            positions.push_back(n);
            
            for(int i = 1; i < positions.size() - 1; i++)
            {
                int current = positions[i];
                int prev = positions[i - 1];
                int next = positions[i + 1];
                count += (current - prev) * (next - current);
            }
        }   
        return count;
    }
};

// Main function to test the implementation
int main() {
    Solution solution;
    string s = "ABA"; // Test case
    cout << "Total unique character contribution: " << solution.uniqueLetterString(s) << endl;
    return 0;
}

/*
Why Multiplication Works, But Addition Doesn't
✅ Multiplication ((cur - prev) * (next - cur)) Works Because:
(cur - prev) gives valid start positions

(next - cur) gives valid end positions

Their product gives all possible substrings where the current character is unique.

❌ Addition ((cur - prev) + (next - (cur - 1))) Overcounts Because:
Addition treats start and end positions separately, instead of considering combinations of start and end.

It mistakenly includes substrings where 'A' is not uniquely contributing, which leads to an incorrect count.
*/

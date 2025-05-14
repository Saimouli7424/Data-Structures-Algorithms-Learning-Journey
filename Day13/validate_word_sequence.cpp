#include <bits/stdc++.h>
using namespace std;

bool validate(string word, unordered_map<char, vector<int>> &mp)
{
    int prevIndex = -1;
    // Iterate through each character in the word
    for (auto ch : word)
    {
        if (mp.find(ch) != mp.end())
        {
            auto &result = mp[ch];
            bool found = false;

            // Try to find the smallest index greater than prevIndex
            for (int i = 0; i < result.size(); i++)
            {
                if (result[i] > prevIndex)
                {
                    prevIndex = result[i];
                    found = true;
                    break;
                }
            }

            // If no valid index was found for this character, return false
            if (!found)
                return false;
        }
        else
        {
            return false; // Character not found in the map
        }
    }
    return true;
}

int main()
{
    string s = "abcde";
    string words[] = {"ab", "bc", "cd", "dc", "ac", "bb", "ad", "aec"};

    unordered_map<char, vector<int>> mp;
    // Store indices of each character in the map
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]].push_back(i);
    }

    cout << "Valid words:\n";
    // Check which words are valid
    for (auto word : words)
    {
        if (validate(word, mp))
        {
            cout << word << " is valid\n";
        }
        else
        {
            cout << word << " is invalid\n";
        }
    }

    return 0;
}

/*
Valid words:
ab is valid
bc is valid
cd is valid
dc is invalid
ac is invalid
bb is invalid
ad is valid
aec is valid
*/
//Longest Unequal Adjacent Groups Subsequence II
//using DFS and hashmap got TLE and time complexity is O(n^2 * m) where n is the length of the string and m is the number of unique characters
/*
class Solution {
public:
    unordered_map<int,vector<int>>mp;
    vector<string> result;
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        for(int i=0;i<words.size();i++){
            mp[words[i].length()].emplace_back(i);
        }

        for(int i=0;i<words.size();i++){
            vector<string>temp;
            temp.push_back(words[i]);
            dfs(words,groups,words[i],temp,i,0,groups[i]);
        }
        return result;
    }

    void dfs(vector<string>& words,vector<int>& groups,string word,vector<string>temp,int index,int i,int prev)
    {
        int ssize = word.length();
        int n=mp[ssize].size();
        if (temp.size() > result.size()) {
            result = temp;
        }
        for(int j=i;j<n;j++)
        {
            int gindex = mp[ssize][j];
            if(gindex>index && prev!=groups[gindex] && check(word,words[gindex])){
                temp.emplace_back(words[gindex]);
                dfs(words, groups, words[gindex], temp, gindex, 0, groups[gindex]);
                temp.pop_back();
            }
        }
    }

    bool check(string first,string second){
        int count=0;
        for(int i=0;i<first.length();i++){
            if(first[i]!=second[i])count++;
            if(count>1)return false;
        }
        if(count==1)return true;
        return false;
    }
};
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] == groups[j]) continue;
                if (words[i].length() != words[j].length()) continue;
                if (hammingDist(words[i], words[j]) != 1) continue;
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        // Find the index with the maximum value in dp
        int index = max_element(dp.begin(), dp.end()) - dp.begin();

        while (index != -1) {
            ans.push_back(words[index]);
            index = prev[index];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    int hammingDist(const string& s1, const string& s2) {
        int dist = 0;
        for (int i = 0; i < s1.length(); ++i)
            if (s1[i] != s2[i]) ++dist;
        return dist;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<string> words1 = {"abc", "bbc", "acc", "adc"};
    vector<int> groups1 = {1, 2, 1, 2};
    auto res1 = sol.getWordsInLongestSubsequence(words1, groups1);
    cout << "Test Case 1 Result: ";
    for (const string& w : res1) cout << w << " ";
    cout << "\n";

    // Test Case 2
    vector<string> words2 = {"aab", "abb", "bbb", "bbc", "bcc"};
    vector<int> groups2 = {1, 2, 1, 2, 1};
    auto res2 = sol.getWordsInLongestSubsequence(words2, groups2);
    cout << "Test Case 2 Result: ";
    for (const string& w : res2) cout << w << " ";
    cout << "\n";

    // Test Case 3
    vector<string> words3 = {"xyz", "xya", "xzz", "xzx", "xzz"};
    vector<int> groups3 = {1, 2, 1, 2, 3};
    auto res3 = sol.getWordsInLongestSubsequence(words3, groups3);
    cout << "Test Case 3 Result: ";
    for (const string& w : res3) cout << w << " ";
    cout << "\n";

    return 0;
}

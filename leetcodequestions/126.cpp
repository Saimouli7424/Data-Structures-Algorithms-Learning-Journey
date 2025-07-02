//Word Ladder II(Hard)
//using BFS for depth calculation for each word and DFS for path finding
//time complexity: O(n * m^2) where n is the number of words and m is the length of each word
//space complexity: O(n * m) for the graph and visited map
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    unordered_map<string, int> depthMap;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};  // endWord not present in wordList
        wordSet.erase(beginWord);

        queue<string> q;
        q.push(beginWord);
        depthMap[beginWord] = 1;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = depthMap[word];
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;
                    word[i] = ch;
                    if (wordSet.count(word)) {
                        q.push(word);
                        depthMap[word] = steps + 1;
                        wordSet.erase(word); // erase after pushing to prevent duplicates in the same level
                    }
                }
                word[i] = original;
            }
        }

        if (depthMap.count(endWord)) {
            vector<string> path = { endWord };
            dfs(path, beginWord, endWord);
        }

        return result;
    }

    void dfs(vector<string>& path, string& beginWord, string word) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        int steps = depthMap[word];
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == original) continue;
                word[i] = ch;
                if (depthMap.count(word) && depthMap[word] == steps - 1) {
                    path.push_back(word);
                    dfs(path, beginWord, word);
                    path.pop_back();
                }
            }
            word[i] = original;
        }
    }
};

// -------------------- MAIN FUNCTION WITH TEST CASES --------------------

int main() {
    Solution obj;

    vector<string> wordList1 = {"hot","dot","dog","lot","log","cog"};
    string begin1 = "hit", end1 = "cog";
    auto res1 = obj.findLadders(begin1, end1, wordList1);
    cout << "Test Case 1:\n";
    for (auto path : res1) {
        for (auto word : path)
            cout << word << " ";
        cout << endl;
    }

    cout << "-------------------------\n";

    vector<string> wordList2 = {"a","b","c"};
    string begin2 = "a", end2 = "c";
    auto res2 = obj.findLadders(begin2, end2, wordList2);
    cout << "Test Case 2:\n";
    for (auto path : res2) {
        for (auto word : path)
            cout << word << " ";
        cout << endl;
    }

    cout << "-------------------------\n";

    vector<string> wordList3 = {"most","mist","miss","lost","fist","fish"};
    string begin3 = "lost", end3 = "miss";
    auto res3 = obj.findLadders(begin3, end3, wordList3);
    cout << "Test Case 3:\n";
    for (auto path : res3) {
        for (auto word : path)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}


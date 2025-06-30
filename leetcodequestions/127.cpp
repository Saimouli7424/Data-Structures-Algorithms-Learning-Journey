//Word Ladder(Hard)
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool Ladder(string prev,string curr){
        int diff=0;
        for(int i=0;i<prev.length();i++){
            if(prev[i]!=curr[i])diff++;
        }
        return diff==1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.length()!=endWord.length() || find(wordList.begin(),wordList.end(),endWord)==wordList.end())return 0;

        int n=wordList.size();
        //laststring,length
        queue<tuple<string,int>>q;
        q.push({beginWord,1});

        int len=INT_MAX;
        vector<int>visited(n,0);
        while(!q.empty())
        {
            auto[s,l]=q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(visited[j])continue;
                string word=wordList[j];

                if(s.length()!=word.length())continue;

                if(Ladder(s,word)){
                    if(word==endWord)return l+1;
                    q.push({word,l+1});
                    visited[j]=1;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    string begin1 = "hit", end1 = "cog";
    cout << "Test Case 1: " << sol.ladderLength(begin1, end1, wordList1) << endl;
    // Expected: 5 (hit → hot → dot → dog → cog)

    // Test Case 2
    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
    string begin2 = "hit", end2 = "cog";
    cout << "Test Case 2: " << sol.ladderLength(begin2, end2, wordList2) << endl;
    // Expected: 0 (cog not in wordList)

    return 0;
}

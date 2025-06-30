//Word Ladder(Hard)
#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    //optimal using unordered_set and queue which done operations in O(1) time
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*Time Complexity:- O(N*L*26)=O(N*L);
        / Space Complexity:- unordered_set stores N words: O(N)
                             queue may grow up to N: O(N)*/
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            if(word==endWord)return len;

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,len+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
    /*
    //My approach time complexity is O(n^2*m) where n is the number of words and m is the length of each word.
    //Space complexity is O(n) for the visited array.
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
    }*/
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

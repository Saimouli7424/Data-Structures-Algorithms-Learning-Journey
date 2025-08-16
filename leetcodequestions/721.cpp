//Accounts Merge(Medium)
//using UnionFind
//Time Complexity: O(n * α(n)), where n is the number of accounts and α is the inverse Ackermann function.
//Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

// DSU class
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionBySize(int x, int y) {
        int uPx = findParent(x), uPy = findParent(y);
        if(uPx == uPy) return;

        if(size[uPx] < size[uPy]) {
            parent[uPx] = uPy;
            size[uPy] += size[uPx];
        } else {
            parent[uPy] = uPx;
            size[uPx] += size[uPy];
        }
    }
};

// Solution class
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex; // email -> first account index
        DSU dsu(accounts.size());

        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string &email = accounts[i][j];
                if(emailToIndex.count(email)) {
                    dsu.unionBySize(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> emailsByParent;
        for(auto &[email, idx] : emailToIndex) {
            int parent = dsu.findParent(idx);
            emailsByParent[parent].push_back(email);
        }

        vector<vector<string>> res;
        for(auto &[idx, emails] : emailsByParent) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[idx][0]); // add name
            res.push_back(emails);
        }

        return res;
    }
};

// Helper function to print result
void printAccounts(const vector<vector<string>> &accounts) {
    for(const auto &acc : accounts) {
        cout << "[";
        for(int i = 0; i < acc.size(); i++) {
            cout << acc[i];
            if(i != acc.size()-1) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    Solution sol;

    // Test case 1
    vector<vector<string>> accounts1 = {
        {"John", "a@gmail.com", "b@gmail.com"},
        {"John", "b@gmail.com", "c@gmail.com"},
        {"Mary", "d@gmail.com"}
    };
    cout << "Test case 1:\n";
    printAccounts(sol.accountsMerge(accounts1));
    cout << "\n";

    // Test case 2
    vector<vector<string>> accounts2 = {
        {"Alex","alex1@mail.com","alex2@mail.com"},
        {"Alex","alex2@mail.com","alex3@mail.com"},
        {"Bob","bob@mail.com"}
    };
    cout << "Test case 2:\n";
    printAccounts(sol.accountsMerge(accounts2));
    cout << "\n";

    // Test case 3
    vector<vector<string>> accounts3 = {
        {"Alice", "alice@mail.com"},
        {"Alice", "alice@mail.com", "alice2@mail.com"},
        {"Alice", "alice2@mail.com", "alice3@mail.com"}
    };
    cout << "Test case 3:\n";
    printAccounts(sol.accountsMerge(accounts3));
    cout << "\n";

    return 0;
}


/*
 //my approach a little big but same time complexity
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<int>>mp;

        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                mp[accounts[i][j]].push_back(i);
            }
        }

        DSU dsu(accounts.size());
        for(auto it:mp){
            for(int i = 1; i < it.second.size(); i++){
                dsu.unionBySize(it.second[0], it.second[i]);
            }
        }

        unordered_map<int, set<string>> emailsByParent; // parent index -> emails
        for(auto &it : mp){
            for(int idx : it.second){
                int parent = dsu.findParent(idx);
                emailsByParent[parent].insert(it.first);
            }
        }

        vector<vector<string>> res;
        for(auto &it : emailsByParent){
            int idx = it.first;
            vector<string> merged;
            merged.push_back(accounts[idx][0]); // account name
            merged.insert(merged.end(), it.second.begin(), it.second.end()); // emails (sorted automatically because set)
            res.push_back(merged);
        }

        return res;
    }
 */
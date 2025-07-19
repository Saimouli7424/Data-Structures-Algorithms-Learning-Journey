//Remove Sub-Folders from the Filesystem(Medium)
//Time complexity: O(n log n + n*l) for sorting and O(n) for the final check
//Space complexity: O(n) for storing the result
#include <bits/stdc++.h>
using namespace std;

vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    vector<string> result;

    for (const string& path : folder) {
        // Check if the current path is not a subfolder of the last added folder
        //path.find is o(n*l) where l is the length of the path
        if (result.empty() || path.find(result.back() + "/") != 0) {
            result.push_back(path);
        }
    }

    return result;
}

void printResult(const vector<string>& result) {
    for (const string& folder : result) {
        cout << folder << endl;
    }
    cout << "--------" << endl;
}

int main() {
    // Test Case 1
    vector<string> folder1 = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    cout << "Test Case 1:" << endl;
    printResult(removeSubfolders(folder1));

    // Test Case 2
    vector<string> folder2 = {"/a", "/a/b/c", "/a/b/d"};
    cout << "Test Case 2:" << endl;
    printResult(removeSubfolders(folder2));

    // Test Case 3
    vector<string> folder3 = {"/abc", "/ab", "/abc/def", "/abc/def/ghi", "/ab/cd"};
    cout << "Test Case 3:" << endl;
    printResult(removeSubfolders(folder3));

    return 0;
}

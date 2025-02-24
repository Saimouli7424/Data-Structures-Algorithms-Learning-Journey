//leetcode 412
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n = 20; 
    vector<string> Data;
    Data.reserve(n); 

    for (int i = 1; i <= n; ++i) {
        string val;
        
        if (i % 3 == 0) val += "Fizz";
        if (i % 5 == 0) val += "Buzz";
        if (val.empty()) val = to_string(i);

        Data.emplace_back(move(val));
    }

    
    for (const auto& str : Data) {
        cout << str << " ";
    }
    
    return 0;
}

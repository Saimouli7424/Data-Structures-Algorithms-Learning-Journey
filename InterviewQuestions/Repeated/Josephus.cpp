
// Josephus Problem
// The Josephus problem is a theoretical problem related to a certain elimination game.
// The game is played with n people standing in a circle, with a number m (1 <=
// m <= n) indicating the step count for elimination. The person at position m is eliminated,
// and the process continues until only one person remains. The task is to find the position
// of the last person standing.
// Example: n = 5, m = 2, the sequence of elimination is:
// 1 2 3 4 5 ->
// 1 3 4 5 -> 1 4 5 -> 1 5 -> 1
// The last person standing is at position 1.
// Solution: The problem can be solved using a mathematical approach. We can use the
//my approach for k=2
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    vector<int> arr={1,2,3,4};
    bool killed = false;
    int count;
    int val=-1;
    do{
        count=0;
        for(int i=0;i<arr.size();i++){
            if(!killed && arr[i]!=-1){
                killed=true;
                count++;
                val=arr[i];
                continue;
            }
            if(killed && arr[i]!=-1){
                arr[i]=-1;
                killed=false;
            }
        }
    }while(count!=1);
    
    cout<<val;
    return 0;
}
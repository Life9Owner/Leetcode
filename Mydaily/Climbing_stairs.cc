#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
/// @brief this is the basic problem of dynamic programming.
//Now I have a new solution that using memorization recursive approach.
class Solution {
public:
    int dfs(vector<int>& memo,int i)
    {
        if(i==0){
            return 1;
        }
        if(i==1)
        {
            return 1;
        }
        if(memo[i]!=-1)return memo[i];
        memo[i]=dfs(memo,i-1)+dfs(memo,i-2);
        return memo[i];
    }
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return dfs(memo,n);
    }
};
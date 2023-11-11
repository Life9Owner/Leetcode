#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> path;
    void dfs(vector<int>& candidates,int target,vector<vector<int>>& ans,int index)
    {
        if(target==0)
        {
            ans.push_back(path);
        }
        for(int i=index;i<candidates.size();i++)
        {
            // 1 1 1 2 5 3
           if(i>index&&candidates[i-1]==candidates[i])continue;
            if(target-candidates[i]>=0)
            {
                path.push_back(candidates[i]);
                dfs(candidates,target-candidates[i],ans,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,ans,0);
        return ans;
    }
};
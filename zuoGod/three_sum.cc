#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            vector<vector<int>> ans;
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++)
            {
                if(i>0&&nums[i-1]==nums[i])continue;
                int j=i+1,k=nums.size()-1;
                int target=0-nums[i];

                while(j<k)
                {
                    if(nums[j]+nums[k]==target)
                    {
                        ans.push_back({nums[j],nums[k],-target});
                        while(j<k&&nums[j]==nums[j+1])j++;
                        while(j<k&&nums[k]==nums[k-1])k--;
                        j++;
                        k--;

                    }
                    else if(nums[j]+nums[k]<target)
                    {
                        j++;
                    }
                    else{
                        k--;
                    }
                }
            }
            return ans;
        }
        

};
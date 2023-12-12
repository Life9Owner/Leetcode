#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        // -1 1 1 2 3
        for(int i=0;i<nums.size();i++)
        {
            int left=i+1;
            while(left<nums.size()&&(nums[i]+nums[left])<target)
            {
                left++;
            }
            cnt+=(left-i-1);
        }
        return cnt;
    }
};

//I find it is not so efficient,so I use binary sort to optimize it.
//here is my new solution:
class Solution1{
public:
    int countPairs(vector<int>& nums, int target) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        // -1 1 1 2 3
        for(int i=0;i<nums.size();i++)
        {
            int left=i+1,right=nums.size()-1;
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                if(nums[i]+nums[mid]<target)
                {
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            cnt+=(left-1-i);
        }
        return cnt;
    }
};
// a solution using api of cpp
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            int k = lower_bound(nums.begin(), nums.begin() + i, target - nums[i]) - nums.begin();
            res += k;
        }
        return res;
    }
};
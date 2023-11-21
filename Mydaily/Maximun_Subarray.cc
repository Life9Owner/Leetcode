#include<iostream>
#include<utility>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
        {
            return 0;
        }
        return maxSubArraySum(nums,0,len-1);
    }
    int maxCrossingSum(vector<int>& nums,int left,int mid,int right)
    {
        int sum=0;
        int leftSum=INT_MIN;
        for(int i=mid;i>=left;i--)
        {
            sum+=nums[i];
            leftSum=max(sum,leftSum);
        }
        sum=0;
        int rightSum=INT_MIN;
        for(int i=mid+1;i<=right;i++)
        {
            sum+=nums[i];
            rightSum=max(rightSum,sum);
        }
        return leftSum+rightSum;
    }
    int maxSubArraySum(vector<int>& nums,int left,int right)
    {
        if(left==right){
            return nums[left];
        }
        int mid=left+(right-left)/2;
        return max3(maxSubArraySum(nums,left,mid),maxSubArraySum(nums,mid+1,right),maxCrossingSum(nums,left,mid,right));
    }
    int max3(int num1,int num2,int num3)
    {
        return max(max(num1,num2),num3);
    }
};
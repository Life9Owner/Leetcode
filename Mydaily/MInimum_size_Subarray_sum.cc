#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // Compute prefix sums
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        // If the total sum is still less than the target, no such subarray exists
        if(nums[n - 1] < target) return 0;
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int left = i, right = n - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                int sum = nums[mid] - (i > 0 ? nums[i - 1] : 0);
                if(sum < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            // Ensure that 'left' is in bounds and check the subarray sum
            if(left < n && nums[left] - (i > 0 ? nums[i - 1] : 0) >= target) {
                ans = min(ans, left - i + 1);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

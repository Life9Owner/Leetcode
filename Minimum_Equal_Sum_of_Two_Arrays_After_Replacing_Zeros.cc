#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    pair<long long, int> get(const vector<int>& nums) {
        long long sum = 0;
        int countZero = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) sum += nums[i];
            else countZero++;
        }

        return make_pair(sum, countZero);
    }

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        pair<long long, int> sum_zero1 = get(nums1);
        pair<long long, int> sum_zero2 = get(nums2);

        sum_zero1.first += sum_zero1.second;
        sum_zero2.first += sum_zero2.second;

        long long diff = sum_zero1.first - sum_zero2.first;

        if(diff == 0) {
            return sum_zero1.first;
        } else if(diff > 0) {
            if(sum_zero2.second > 0) {
                return sum_zero2.first + diff;
            } else {
                return -1;
            }
        } else {
            if(sum_zero1.second > 0) {
                return sum_zero1.first - diff; // Changed `+ diff` to `- diff` here to correct the logic
            } else {
                return -1;
            }
        }

        return -1;
    }
};
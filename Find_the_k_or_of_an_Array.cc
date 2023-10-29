#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;

        // We'll check 32 bits, assuming 32-bit integers
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;

            // Count how many numbers have this bit set
            for (int num : nums) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }

            // If at least k numbers have this bit set, set the result's bit
            if (count >= k) {
                result |= (1 << bit);
            }
        }

        return result;
    }
};

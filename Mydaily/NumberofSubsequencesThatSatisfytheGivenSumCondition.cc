#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// class Solution {
// public:
    // unordered_map<int,int> hash;
    // vector<int> path;
    // bool check(vector<int>& path,int target)
    // {
    //     if(path.size()==0)return false;
    //     return path[0]+path[path.size()-1]<=target;
    // }
    // int dfs(vector<int>& nums,int index,int target)
    // {
    //     if(index>=nums.size()) 
    //     {
    //         for(auto x:path)
    //         {
    //             cout<<x<<" ";
    //         }
    //         cout<<endl;
    //         return check(path,target)==true?1:0;
    //     }
        
    //     int res=0;
    //     if(hash.count(nums[index]))
    //     {
    //         return hash[nums[index]];
    //     }
    //     for(int i=index;i<nums.size();i++)
    //     {
    //         path.push_back(nums[i]);
    //         res+=dfs(path,i+1,target); 
    //         path.pop_back();   
    //     }
        
    //     return res%int(1e9+7);
    // }
    // int numSubseq(vector<int>& nums, int target) {
    //     sort(nums.begin(),nums.end());
    //     return dfs(nums,0,target);
    // }
// };

//     const int MOD = 1e9 + 7;

// class Solution {
// public:
//     int numSubseq(std::vector<int>& nums, int target) {
//         std::sort(nums.begin(), nums.end()); // Sort the numbers
//         int count = 0;
//         std::vector<int> currentSubseq;
//         dfs(nums, target, 0, currentSubseq, count);
//         return count;
//     }

// private:
//     void dfs(std::vector<int>& nums, int target, int index, std::vector<int>& currentSubseq, int& count) {
//         if (!currentSubseq.empty() && currentSubseq.front() + currentSubseq.back() <= target) {
//             count = (count + 1) % MOD;
//         }

//         for (int i = index; i < nums.size(); i++) {
//             if (!currentSubseq.empty() && currentSubseq.front() + nums[i] > target) {
//                 // As the array is sorted, further elements will only be greater.
//                 break;
//             }
//             currentSubseq.push_back(nums[i]);
//             dfs(nums, target, i + 1, currentSubseq, count);
//             currentSubseq.pop_back(); // Backtrack
//         }
//     }
// };
// class Solution {
// public:
//     int numSubseq(std::vector<int>& nums, int target) {
//         std::sort(nums.begin(), nums.end());
//         int count = 0;
//         dfs(nums, target, 0, nums.size() - 1, count);
//         return count;
//     }

// private:
//     void dfs(std::vector<int>& nums, int target, int left, int right, int& count) {
//         if (left > right) return;
        
//         if (nums[left] + nums[right] <= target) {
//             // If the smallest and largest numbers fit the condition, all combinations
//             // between left and right are valid because the array is sorted.
//             count = (count + powMod(2, right - left)) % MOD; // 2^(right-left)subsequences
//             dfs(nums, target, left + 1, right, count); // Try next subsequence
//         } else {
//             // If the current pair is invalid, the pairs with the current right
//             // and any number after left are also invalid.
//             dfs(nums, target, left, right - 1, count); // Try with a smaller maximum
//         }
//     }

//     int powMod(int base, int exp) {
//         int result = 1;
//         base %= MOD;
        
//         while (exp > 0) {
//             if (exp % 2 == 1)
//                 result = (int)((long long)result * base % MOD);
//             base = (int)((long long)base * base % MOD);
//             exp /= 2;
//         }
        
//         return result;
//     }
// };
class Solution {
public:

    vector<int> path;
    bool check(vector<int>& path,int target)
    {
        if(path.size()==0)return false;
        return path.front()+path.back()<=target;
    }
    int dfs(vector<int>& nums,int index,int target)
    {
    int res=0;
        
        if(check(path,target)==true)
        {
            res=(res+1)%(int)(1e9+7);
            cout<<res<<" ";
            // for(auto x:path)
            // {
            //     cout<<x<<" ";
            // }
            cout<<endl;
        }
        
        
        for(int i=index;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            res+=dfs(nums,i+1,target); 
            path.pop_back();   
        }
        
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return dfs(nums,0,target);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5, 6, 7}; // Example input
    int target = 9; // Example target
    int result = sol.numSubseq(nums, target);
    cout << "Number of subsequences: " << result << endl;
    return 0;
}
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int left = 0;
        int right = A.size() - 1;

        // 注意防止越界
        while (left < A.size() - 1 && A[left] < A[left + 1]) left++;

        // 注意防止越界
        while (right > 0 && A[right] < A[right - 1]) right--;

        // 如果left或者right都在起始位置，说明不是山峰
        if (left == right && left != 0 && right != A.size() - 1) return true;
        return false;
    }
};

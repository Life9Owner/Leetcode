#include<vector>
#include<iostream>
using namespace std;
int coins1(vector<int> arr,int aim)
{
    if(arr.size()==0||aim<0)
    {
        return 0;
    }
    return process1(arr,0,aim);
}
int process1(vector<int> arr,int index,int aim)
{
    int res=0;
    if(index==arr.size())
    {
        res=aim==0?1:0;
    }
    else{
         for(int i=0;arr[index]*i<=aim;i++)
         {
            res+=process1(arr,index,aim-arr[index]*i);
         }
    }
    return res;
}
int coins2(vector<int> arr,int aim)
{
    if(arr.size()==0||aim<0)
    {
        return 0;
    }
    vector<vector<int> > map(arr.size()+1,vector<int>(aim+1,0));
    return process2(arr,0,aim,map);
}
int process2(vector<int> arr,int index,int aim,vector<vector<int>>& map)
{  
    int res=0;
    if(index==arr.size())
    {
        res=aim==0?1:0;
    }
    else{
        int maxValue=0;
        for(int i=0;arr[index]*i<=aim;i++)
        {
            maxValue=map[index+1][aim-arr[index]*i];
            if(maxValue!=0)
            {
                res+=maxValue==-1?0:maxValue;
            }
            else{
                res+=process2(arr,index+1,aim-arr[index]*i,map);
            }
        }
    }
    map[index][aim]=res==0?-1:res;
    return res;
}
int main()
{

    return 0;
}
/*better code with memory */
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int process2_plus(vector<int>& arr, int index, int aim, vector<vector<int>>& map) ;
int coins2_plus(vector<int>& arr, int aim) {
    if (arr.empty() || aim < 0) {
        return 0;
    }
    vector<vector<int>> map(arr.size() + 1, vector<int>(aim + 1, -1));
    return process2_plus(arr, 0, aim, map);
}

int process2_plus(vector<int>& arr, int index, int aim, vector<vector<int>>& map) {
    if (aim == 0) {
        return 1;
    }
    if (index == arr.size() || aim < 0) {
        return 0;
    }
    if (map[index][aim] != -1) {
        return map[index][aim];
    }

    int res = 0;
    for (int i = 0; arr[index] * i <= aim; i++) {
        res += process2_plus(arr, index + 1, aim - arr[index] * i, map);
        res %= MOD; // Modulo at each addition to avoid overflow
    }
    
    map[index][aim] = res;
    return res;
}

int main() {
    int n, aim;
    cin >> n >> aim;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << coins2_plus(arr, aim) << endl;
    return 0;
}

/*dp code*/
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int coins3(const vector<int>& arr, int aim) {
    int n = arr.size();
    if (n == 0 || aim < 0) {
        return 0;
    }
    vector<int> dp(aim + 1, 0);
    dp[0] = 1; // Base case: there's 1 way to make aim 0, which is to choose no coins

    for (int i = 0; i < n; ++i) {
        for (int j = arr[i]; j <= aim; ++j) {
            dp[j] += dp[j - arr[i]];
            if (dp[j] >= MOD) {
                dp[j] -= MOD; // Ensure the value stays within the MOD range
            }
        }
    }

    return dp[aim];
}

int main1() {
    int n, aim;
    cin >> n >> aim;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << coins3(arr, aim) << endl;
    return 0;
}


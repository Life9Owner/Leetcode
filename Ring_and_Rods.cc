#include<iostream>
#include<vector>
#include<set>
using namespace std;

//my solution:
class Solution {
public:
  
        
     
    int countPoints(string rings) {
        vector<set<char>> vec(10,set<char>{});
        for(int i=0;i+1<rings.size();i+=2)
        {
           
           vec[rings[i+1]-'0'].insert(rings[i]);        
        }
        int cnt=0;
        for(auto x:vec)
        {
            if(x.size()==3)
            {
                cnt++;
            }
        }
        return cnt;
    
    }
};

//the better one
class Solution {
public:
    static constexpr int POLE_NUM = 10;
    int countPoints(string rings) {
        vector<int> state(POLE_NUM);
        int n = rings.size();
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int pole_index = rings[i + 1] - '0';
            if (color == 'R') {
                state[pole_index] |= 1;
            } else if (color == 'G') {
                state[pole_index] |= 2;
            } else {
                state[pole_index] |= 4;
            }
        }
        int res = 0;
        for (int i = 0; i < POLE_NUM; i++) {
            res += state[i] == 7;
        }
        return res;
    }
};

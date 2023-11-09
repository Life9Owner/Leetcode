#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
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
    int countPoints(string rings) {
        vector<int> state(10,0);
        for(int i=0;i<rings.size();i+=2)
        {
            if(rings[i]=='R')
            {
                state[rings[i+1]-'0']|=1;
            }
            else if(rings[i]=='G')
            {
                state[rings[i+1]-'0']|=2;
            }
            else
            {
                state[rings[i+1]-'0']|=4;
            }
        }
        int cnt=0;
        for_each(state.begin(),state.end(),[&cnt](int x){
            if(x==7)
            {
               cnt++; 
            }
         
        });
        return cnt;
    }
};

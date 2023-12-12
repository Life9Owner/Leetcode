#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<pair<int,int>> stk;
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            if(stk.empty()==true)
            {
                stk.push(pair<int,int>(temperatures[i],i));
            }
            while(!stk.empty()&&stk.top().first<=temperatures[i])
            {
                stk.pop();
            }  
             if(!stk.empty())
            {
                 ans[i]=stk.top().second-i;
            }
            stk.push({temperatures[i],i});
        }
    
        return ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<pair<int,int>> stk;
        stk.push({0,temperatures[0]});
       for(int i=1;i<temperatures.size();i++)
       {
           while(!stk.empty()&&stk.top().second<temperatures[i])
           {
               
               ans[stk.top().first]=i-stk.top().first;
               stk.pop();
           }
         stk.push({i,temperatures[i]});
           
       }
           
        return ans;
    }
};
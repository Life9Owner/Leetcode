#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits(words.size(),0);
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                bits[i]|=1<<(words[i][j]-'a');
            }
        }
        int res=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(()bits[i]&bits[j])==0)
                {
                    res=max(res,int(words[i].size()*words[j].size()));
                }
            }
            
        }
        return res;
    }
};
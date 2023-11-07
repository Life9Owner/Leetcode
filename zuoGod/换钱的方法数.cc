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
    vector<vector<int> > map(arr.size(),vector<int>(aim+1,0));
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
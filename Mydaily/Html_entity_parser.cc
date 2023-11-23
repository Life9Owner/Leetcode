#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//this solution is not so efficient,I will work out a better latter.
class Solution {
public:
    void input(unordered_map<string,char>& hash_map)
    {
        hash_map.insert({"&quot;",'"'});
        hash_map.insert({"&apos;",'\''});
        hash_map.insert({"&amp;",'&'});
        hash_map.insert({"&gt;",'>'});
        hash_map.insert({"&lt;",'<'});
        hash_map.insert({"&frasl;",'/'});
    }
    void clear(string& str){
        str="";
    }
    string entityParser(string text) {
        unordered_map<string,char> hash_map;
        input(hash_map);
        string ans="";
        bool begin=true;
        string str="";
        for(int i=0;i<text.size();i++)
        {
            if(begin==false)//ans stops
            {
                if(text[i]!='&')
                {
                    str+=text[i];
                }
            }
            else{
                if(text[i]!='&')
                {
                    ans+=text[i];
                }
            }
            if(text[i]=='&')
            { 
                if(str!="")
                {  
                    ans+=str;
                    clear(str);
                }
                
                str+=text[i];
                begin=false;
            }
            else if(text[i]==';')
            {
                if(hash_map.count(str))
                {
                    ans.push_back(hash_map[str]);
                }    
                else{
                    ans+=str;
                }
                clear(str);
                begin=true;
            }
            if(str!=""&&i==text.size()-1)
            {
                ans+=str;
            }
            
        }
        return ans;
    }
};
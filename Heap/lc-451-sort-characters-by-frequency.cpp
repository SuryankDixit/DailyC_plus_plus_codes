#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<char,int> pi;
    unordered_map<char,int> m;
    
    class compare{
        public:
            bool operator()(const pi &a,const pi &b){
                if(a.second < b.second || (a.second==b.second && a.first < b.first))
                    return true;
                return false;
            }
    };
    
    string frequencySort(string s) {
        for(auto x:s)
            m[x]++;
        
        priority_queue<pi,vector<pi>, compare> p;
        for(auto x:m)
            p.push(x);
        string ans="";
        while(!p.empty()){
            auto x=p.top();
            p.pop();
            char ch=x.first;
            int n = x.second;
            for(int i=0;i<n;i++)
                ans+=ch;
        }
        return ans;
    }
};



// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> m;
//         for(auto x:s)
//             m[x]++;
        
//         sort(s.begin(),s.end(),[&](char a,char b){
//             if(m[a]>m[b] || (m[a]==m[b] && a<b))
//                 return true;
//             return false;
//         });
//         return s;
//     }
// };
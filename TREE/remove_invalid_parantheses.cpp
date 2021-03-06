
// 301. Remove Invalid Parentheses
//https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> vis;
        vector<string> ans;
        queue<string> q;
        q.push(s);
        int found=0;
        while(!q.empty())
        {
            string temp=q.front();
            q.pop();
            if(vis.find(temp)!=vis.end())
                continue;
            vis.insert(temp);
            if(is_balanced(temp))
            {
                found=1;
                ans.push_back(temp);
            }
            if(found)
                continue;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]==')' || temp[i]=='(')
                {
                    string v=temp.substr(0,i)+temp.substr(i+1,temp.size());
                    q.push(v);
                }
            }
        }
   
        return ans;
    }
    
    bool is_balanced(string &s)
    {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                count++;
            else if(s[i]==')')
                count--;
            
            if(count<0)
                return false;
        }
        if(count>0)
            return false;
     
       return true;
    }
};

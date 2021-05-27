class Solution {
public:
    
    int minDistance(string word1, string word2) {
        
        if(word1.size()==0)
            return word2.size();
        else if(word2.size()==0)
            return word1.size();
        
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return distance(word1,word2,0,0,dp);
    }
    
    int distance(string &s1,string &s2,int i,int j,vector<vector<int>> &dp) 
        //  i and j are indexes of s1 and s2
    {
        // base condition is : if any of the string finishes 
        // s1=""  s2="abc"  => i index ended and j index in remaining so total distance is s2.size()-j;
        
        if(i==s1.size()) 
            return s2.size()-j; 
        if(j==s2.size())
            return s1.size()-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s1[i]==s2[j])
            dp[i][j]=distance(s1,s2,i+1,j+1,dp);
        else
        {
            // 1 is the cost of insertion, deletion and replacement;
            int insert=distance(s1,s2,i,j+1,dp)+1 ;
            int delete_=distance(s1,s2,i+1,j,dp)+1;
            int replace=distance(s1,s2,i+1,j+1,dp)+1;
            dp[i][j]=min(min(insert,delete_),replace);
        }
        return dp[i][j];
            
    }
};

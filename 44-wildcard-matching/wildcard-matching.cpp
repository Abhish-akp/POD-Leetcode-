class Solution {
public:
    bool isMatch(string s, string p) {
        int l1= s.length();
        int l2= p.length();

        vector<vector<bool>>dp(l1+1,vector<bool>(l2+1,0));
        dp[0][0]=1;
        for(int i=1;i<l2+1;i++){
            if (p[i-1] == '*'){
                dp[0][i] = dp[0][i-1];
            }
        }
        
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(p[j-1]== '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if(p[j-1]== '?' || s[i-1]==p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[l1][l2];
    }
};
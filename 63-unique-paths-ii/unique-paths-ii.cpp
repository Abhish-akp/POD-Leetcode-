class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m=obs.size();
        int n=obs[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        bool check=false;

        if(obs[0][0]==1 || obs[m-1][n-1]==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(check || obs[0][i]){
                dp[0][i]=0;
                check=true;
            }
            else{
                dp[0][i]=1;
            }
        }
        check=false;
        for(int j=1;j<m;j++){
            if(check || obs[j][0]){
                dp[j][0]=0;
                check=true;
            }
            else{
                dp[j][0]=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obs[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
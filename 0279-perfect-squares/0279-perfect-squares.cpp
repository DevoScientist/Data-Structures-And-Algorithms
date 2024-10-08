class Solution {
public:

    int minsquare(int n , vector<int>& dp)
    {
        if(n <= 0) return 0;

        if(dp[n] != -1) return dp[n];
        
        int ans = n;

        for(int i = 1 ; i*i <= n; ++i)
        {
            int sq = i*i;
            ans = min(ans , 1 + minsquare(n - sq , dp));
        }

        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1 , -1);
        return minsquare(n , dp);
    }
};
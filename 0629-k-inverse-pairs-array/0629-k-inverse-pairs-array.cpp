class Solution {
public:
    int m=1e9+7;
    int kInversePairs(int n, int k) {
        
        vector<vector<long long>> dp(n+1 , vector<long long> (k+1,-1));//dp[n][k] it gives the number of K-inv. pair for {n , k}.
        for(int i = 0;i<n;i++) dp[i][0] = 1;
        return f(n , k , dp);
        
    }
private: 
    long long int f(int n , int k , vector<vector<long long>>& dp)
    {
        if(k<0)
        return 0LL;
        
        if(n==0)
        return k==0;
        if(dp[n][k]!=-1)
        return dp[n][k];
        dp[n][k] = (f(n-1 ,k , dp)%m - f(n-1 , k-n , dp)%m + f(n , k-1 , dp)%m + m)%m;

        return dp[n][k];
    }
};
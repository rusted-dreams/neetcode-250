class Solution {
    int solve(int n, vector<int>& cost, vector<int>& dp) {
        if(n < 0) return 0;
        if(n == 1) return cost[n];
        if(dp[n] != -1) return dp[n];
        int prev = solve(n-1, cost, dp);
        int prev2 = solve(n-2, cost, dp);
        if (n<cost.size()){
            prev += cost[n];
            prev2 += cost[n];
        }
        return dp[n] = min(prev, prev2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return solve(n, cost, dp);
    }
};

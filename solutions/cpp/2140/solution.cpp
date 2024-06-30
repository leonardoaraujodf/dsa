class Solution {
public:
    long long mostPoints2(vector<vector<int>>& questions) {
        vector<long long> memo(questions.size(), 0);
        return dp(0, memo, questions);
    }
    
    long long dp(int i, vector<long long> &memo, vector<vector<int>> &questions) {
        if (i >= questions.size()) {
            return 0;
        }
        
        if (memo[i] != 0) {
            return memo[i];
        }
        
        int j = i + questions[i][1] + 1;
        memo[i] = max(questions[i][0] + dp(j, memo, questions), dp(i + 1, memo, questions));
        return memo[i];
    }
    
    long long mostPoints(vector<vector<int>> &questions) {
        int n = questions.size();
        vector<long> dp(n + 1);
        
        for (int i = n - 1; i >= 0; i--) {
            int j = i + questions[i][1] + 1;
            dp[i] = max(questions[i][0] + dp[min(j, n)], dp[i + 1]);
        }
        
        return dp[0];
    }
};
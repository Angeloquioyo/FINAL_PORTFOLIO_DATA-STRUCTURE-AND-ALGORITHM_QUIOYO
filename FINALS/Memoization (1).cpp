#include <iostream>
#include <vector>
#include <algorithm>   
using namespace std;

int getMinStepsMemo(int n, vector<int>& memo) {
    if (n == 1) return 0;  

    if (memo[n] != -1) return memo[n];

    int res = 1 + getMinStepsMemo(n - 1, memo);

    if (n % 2 == 0)
        res = min(res, 1 + getMinStepsMemo(n / 2, memo));

    if (n % 3 == 0)
        res = min(res, 1 + getMinStepsMemo(n / 3, memo));

    memo[n] = res;  
    return res;
}

int getMinStepsBottomUp(int n) {
    vector<int> dp(n + 1, 0);  
    dp[1] = 0;  

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;  

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    vector<int> memo(n + 1, -1);  
    int stepsMemo = getMinStepsMemo(n, memo);
    cout << "\n[Memoization] Minimum steps to reduce " << n << " to 1: " << stepsMemo << endl;

    int stepsBottomUp = getMinStepsBottomUp(n);
    cout << "[Bottom-Up DP] Minimum steps to reduce " << n << " to 1: " << stepsBottomUp << endl;

    cout << "\nNote: Both approaches give the same answer. Bottom-Up is faster for large n.\n";
    return 0;
}

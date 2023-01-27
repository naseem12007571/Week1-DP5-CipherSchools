class Solution {


public:
    double myPow(double x, int N) {
        if (!N) return 1.0;

        bool takeRecip = false;

        long n = (long) N;

        unordered_map<long,double> dp; // power, answer
        dp[0] = 1.0;
        dp[1] = x;

        if (n < 0) {
            // compute x^-n then invert at the end
            n = -n;
            takeRecip = true;
        }

        double res;

        res = helper(x, n, dp);

        if (takeRecip) {
            return 1.0/res;
        } else {
            return res;
        }
    }

    // recursive helper
    double helper(double x, int n, unordered_map<long,double>& dp) {
        // n should be even
        if (dp.find(n) != dp.end()) {
            return dp[n];
        } else if (dp.find(n/2) != dp.end()) {
            double ans;
            if (n % 2) {
                ans = dp[n/2] * dp[n/2] * x;
            } else {
                ans = dp[n/2] * dp[n/2];
            }
            
            dp[n] = ans;
            return dp[n];
        } else if (n % 2) {
            // odd power
            return helper(x, n/2, dp) * helper(x, n/2, dp) * x;
        } else {
            // even
            return helper(x, n/2, dp) * helper(x, n/2, dp);
        }
    }
};

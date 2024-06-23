#include <iostream>
#include <vector>
#define ll long long


/*
 * GREAT EXAMPLE OF FORWARD DP
 * 		formulating bottom up approach is much simpler than top down
 * 		we can only construct tower going from a smaller height to a bigger height 
*/
class Solution {
	public:
		const int MOD = 1e9 + 7;
		const int N = 1e6 + 6;
		void solve() {
			this->dp = std::vector<std::vector<ll>>(2, std::vector<ll>(N + 1, 0));
			solver(N);
			int t;
			// n is size of array and m is upper bound for each element
			std::cin >> t;
			while(t--) {
				int n;
				std::cin >> n;
				std::cout << (this->dp[0][n] + this->dp[1][n]) % MOD << std::endl;
			}
		}
	private:
		std::vector<std::vector<ll>> dp;	
		ll solver(int n) {
			// 0 -> fused blocks foundation
			// 1 -> disjoint blocks foundation
			// base case	
			dp[0][1] = 1;	// there's only one of building towers of height 1 with both kind of blocks
			dp[1][1] = 1;
			for (int h = 2; h <= n; h++) {
				dp[0][h] = (2 * dp[0][h - 1] + dp[1][h - 1]) % MOD;
				dp[1][h] = (dp[0][h - 1] + 4 * dp[1][h - 1]) % MOD;
			} 
			return dp[0][n] + dp[1][n];
		}
};

int main() {
	auto sol = Solution();
	sol.solve();
	return 0;
}

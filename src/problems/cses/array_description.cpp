#include <iostream>
#include <vector>
#define ll long long

class Solution {
	public:
		void solve() {
			std::vector<int> arr;
			int n, m;
			// n is size of array and m is upper bound for each element
			std::cin >> n >> m;
			while(arr.size() < n) {
				int temp;
				std::cin >> temp;
				arr.push_back(temp);
			}
			this->dp = std::vector<std::vector<ll>>(n, std::vector<ll>(m + 2, -1)); 

			std::cout << std::endl;
			std::cout << solver(0, -1, m, arr) << std::endl;
		}
	private:
		const ll MOD = 1000000000 + 7;
		std::vector<std::vector<ll>> dp;	
		ll solver(int i, int prev, int m, std::vector<int>& arr) {
			// |a[i] - a[i - 1]|, |a[i] - a[i + 1]| <= 1
			if (i == arr.size()) return 1;
			ll cnt = 0;
			if (this->dp[i][prev + 1] != -1) return this->dp[i][prev + 1];

			if (arr[i] != 0) {
				// maybe the 'prev' we have been propagating so far actually doesnt work with fixed arr[i] 
				if (i == 0 || std::abs(arr[i] - prev) <= 1) cnt = (cnt + solver(i + 1, arr[i], m, arr));
			}// fixed value
			else {
				// arr[i] = 0;
				if (i == 0) {
					for (int ith = 1; ith <= m; ith++) {
						cnt = (cnt + solver(i + 1, ith, m, arr));
					}
				} else {
					if (prev - 1 >= 1) cnt = (cnt + solver(i + 1, prev - 1, m, arr));
					cnt = (cnt + solver(i + 1, prev, m, arr));
					if (prev + 1 <= m) cnt = (cnt + solver(i + 1, prev + 1, m, arr));
				}
			}
			return this->dp[i][prev + 1] = cnt % MOD;
		}
};

int main() {
	auto sol = Solution();
	sol.solve();
	return 0;
}

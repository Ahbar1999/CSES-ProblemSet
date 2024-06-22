#include <iostream>
#include <unordered_map>
#include <climits>

class Solution {
	public:
		void solve() {
			int n;
			std::cin >> n;
			std::cout << std::endl;
			std::cout << solver(n) << std::endl;
		}
	private:
		std::unordered_map<int, int> dp;
		int solver(int num) {
			if (num < 10) return 1;
			int ans = INT_MAX;
			int temp = num;
			if (dp.find(num) != dp.end()) return dp[num];
			while(temp) {
				int d = temp % 10;
				temp /= 10;
				if (d == 0) continue;
				ans = std::min(ans, solver(num - d) + 1);
			}

			return this->dp[num] = ans;
		}
};

int main() {
	auto sol = Solution();
	sol.solve();
	return 0;
}

#include <iostream>
#include <climits>
#include <vector>

class Solution {
	public:
		void solve() {
			int a, b;
			std::cin >> a >> b;
			this->dp = std::vector<std::vector<int>>(std::max(a, b) + 1, std::vector<int>(std::max(a, b) + 1, -1));
			std::cout << std::endl;
			std::cout << solver(a, b) << std::endl;
		}
	private:
		std::vector<std::vector<int>> dp;
		int solver(int a, int b) {
			if (a == 0 || b == 0 || a == b) return 0;
			if (this->dp[a][b] != -1) return this->dp[a][b];
			int moves = INT_MAX;
			for (int sz = 1; sz < a; sz++) moves = std::min(moves, solver(sz, b) + solver(a - sz, b));
			for (int sz = 1; sz < b; sz++) moves = std::min(moves, solver(a, b - sz) + solver(a, sz));
			return this->dp[a][b] = (moves + 1);
		}
};

int main() {
	auto sol = Solution();
	sol.solve();
	return 0;
}

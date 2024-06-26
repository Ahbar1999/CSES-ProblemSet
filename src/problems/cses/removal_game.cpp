#include <iostream>
#include <vector>
#include <cstring>
#define ll long long

class Solution {
	public:
		void solve() {
			int n;
			std::vector<int> nums;
			std::cin >> n;
			// this->dp = std::vector<std::vector<std::vector<ll>>>(n, std::vector<std::vector<ll>>(n, std::vector<ll>(2, -1))); 
			while(n--) {
				int temp;
				std::cin >> temp;
				nums.push_back(temp);
			}

			memset(this->dp, -1, sizeof(this->dp));
			std::cout << solver(nums) << std::endl;
		}

	private:
		ll dp[5000][5000][2];
		// std::vector<std::vector<std::vector<ll>>> dp;
		ll f(int i, int j, bool turn, std::vector<int>& nums) {
			if(i > j) return 0;
			if (this->dp[i][j][turn] != -1) return this->dp[i][j][turn];
			ll score1 = f(i + 1, j, !turn, nums);
			ll score2 = f(i, j - 1, !turn, nums);
			return this->dp[i][j][turn] = (turn ? std::max(score1  + nums[i], score2  + nums[j]) : std::min(score1, score2));
		} 


		ll solver(std::vector<int>& nums) {
			return this->f(0, nums.size() - 1, true, nums);	
		}
};

int main() {
	auto sol = Solution();
	sol.solve();
	return 0;
}

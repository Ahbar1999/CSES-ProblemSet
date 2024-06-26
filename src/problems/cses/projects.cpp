#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define __TODO__ 0;
#define ll long long

class Solution {
	public:
		void solve() {
			int n;
			std::cin >> n;
			std::vector<std::vector<ll>> projects;

			while(n--) {
				ll s, e, r;
				std::cin >> s >> e >> r;	// starting day, ending day, reward
				projects.push_back({e, s, r});
			}

			std::cout << solver(projects) << std::endl;
		}

	private:

		ll solver(std::vector<std::vector<ll>>& projects) {
			std::sort(projects.begin(), projects.end());
			std::map<ll, ll> dp;	 // dp[i], stores max profit of projects ending at ith day 
			ll all_max = 0;
			dp[0] = 0;	// initialize
			for (int i= 0; i < projects.size(); i++) {
				ll start = projects[i][1];
				ll end = projects[i][0];
				ll profit = projects[i][2];
				auto it = dp.lower_bound(start);	// find the project that ended before this one starts
				it--;	// we need the project with its end date < current project's start date(strictly less)
				all_max = std::max(all_max, profit + it->second);
				dp[end] = all_max;
			}
			
			return all_max;	
		}
};

int main() {
	auto sol = Solution();
	sol.solve();
	return 0;
}

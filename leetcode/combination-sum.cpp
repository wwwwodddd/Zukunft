class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> re;
        fuck(re, candidates, vector<int>(), target, 0);
		return re;
	}
	void fuck(vector<vector<int>> &re, vector<int>& candidates, vector<int> s, int target, int x) {
		if (target == 0) {
			re.push_back(s);
		}
		if (target <= 0) {
			return;
		}
		if (x == candidates.size()) {
			return;
		}
		fuck(re, candidates, s, target, x + 1);
		s.push_back(candidates[x]);
		target -= candidates[x];
		fuck(re, candidates, s, target, x);
	}
};

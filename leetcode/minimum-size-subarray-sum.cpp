class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int answer = 0;
        int r = 0;
        int l = 0;
        int sum = 0;
        while (true) {
            if (sum >= s) {
                if (answer == 0 || answer > r - l) {
                    answer = r - l;
                }
                sum -= nums[l++];
            }
            if (sum < s) {
                if (r == nums.size()) {
                    break;
                }
                sum += nums[r++];
            }
        }
        return answer;
    }
};
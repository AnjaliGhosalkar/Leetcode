class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        for (int x : nums) {
            int count = 0;

            // Check every subarray of size k
            for (int i = 0; i <= n - k; i++) {
                for (int j = i; j < i + k; j++) {
                    if (nums[j] == x) {
                        count++;
                        break;  // x found in this window
                    }
                }
            }

            // x appears in exactly one window
            if (count == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};
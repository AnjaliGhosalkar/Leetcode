class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        // Counts how many times each number
        // appears inside our current window
        unordered_map<int, int> freq;

        // Starting point of our window
        int left = 0;

        // Stores the longest valid subarray
        int ans = 0;

        // right moves through the array
        for (int right = 0; right < nums.size(); right++) {

            // We added nums[right] to our window,
            // so increase its frequency
            freq[nums[right]]++;

            // If the current window is invalid,
            // shrink it from the left
            while (freq[nums[right]] > k) {

                // Remove nums[left] from the window
                freq[nums[left]]--;

                // Move left forward
                left++;
            }

            // Window is now valid.
            // Calculate its length.
            int length = right - left + 1;

            // Keep the biggest length
            ans = max(ans, length);
        }

        return ans;
    }
};
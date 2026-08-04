class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());

        set<int> s(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = minimum; i <= maximum; i++) {
            if (s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int x : nums)
            freq[x]++;

        // Store {element, frequency}
        vector<pair<int, int>> v(freq.begin(), freq.end());

        // Sort by frequency (descending)
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Pick top k elements
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(v[i].first);

        return ans;
    }
};
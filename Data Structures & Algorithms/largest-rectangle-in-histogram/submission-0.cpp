class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<pair<int, int>> stack;  // pair: (index, height)

        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int start = i;

            while (!stack.empty() && stack.back().second > h) {
                auto [index, height] = stack.back();
                stack.pop_back();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            stack.push_back({start, h});
        }

        for (auto [i, h] : stack) {
            maxArea = max(maxArea, h * ((int)heights.size() - i));
        }
        return maxArea;
    }
};
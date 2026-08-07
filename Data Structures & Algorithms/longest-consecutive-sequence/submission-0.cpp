class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uni(nums.begin(),nums.end());
        int longest = 0;

        for(int i=0;i<nums.size();i++){
            if(uni.find(nums[i]-1) == uni.end()){
                int length = 1;
                int currentNum = nums[i];
                while(uni.find(currentNum + 1) != uni.end()){
                    currentNum += 1;
                    length += 1;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};

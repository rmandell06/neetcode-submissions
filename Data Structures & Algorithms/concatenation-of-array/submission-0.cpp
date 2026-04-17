class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> vals = nums;
        nums.insert(nums.end(), vals.begin(), vals.end());
        return nums;
    }
};
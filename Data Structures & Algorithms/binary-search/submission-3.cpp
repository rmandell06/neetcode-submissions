class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int index = (l+r) / 2;
        int num = nums[index];
        while(num != target){
            if(r == l) return -1;

            if(num < target) l += (r - l + 1)/2;
            else{
                r -= (r - l + 1)/2;
            }
            index = (l+r)/2;
            num = nums[index];
        }

        return index;
    }
};

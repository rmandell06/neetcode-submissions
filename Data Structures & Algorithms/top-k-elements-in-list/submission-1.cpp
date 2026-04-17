class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<std::vector<int>> bucket_sort(nums.size() + 1, std::vector<int>());
        std::map<int, int> freq;
        for(int& num : nums){
            freq[num]++;
        }

        for(auto& [key, value] : freq){
            bucket_sort[value].push_back(key);
        }

        std::vector<int> output;
        int index = nums.size();



        while(output.size() != k){
            if(!bucket_sort[index].empty()){
                // output.insert(output.end(),bucket_sort[index].begin(), bucket_sort[index].end());
                for(auto num : bucket_sort[index]){
                    output.push_back(num);
                }
            }
            index--;
        }

        return output;
    }
};

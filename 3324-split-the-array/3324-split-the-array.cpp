class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> frequency;
        for(int num : nums)
        {
            frequency[num]++;
            if(frequency[num] > 2)
                return false;
        }
        return true;
    }
};
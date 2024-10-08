class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n  = nums.size();
        for(int i = 0;i<n;i++) 
        {
            if(m.find(target - nums[i]) != m.end())
                return {i , m[target - nums[i]]};
            else
                m[nums[i]] = i; 
        }
        return {};
    }
};
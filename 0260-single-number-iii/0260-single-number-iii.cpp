class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_of_all = 0;
        for(int element : nums)
        {
            xor_of_all ^= element;
        }
       
        long long mask = (xor_of_all) & (-xor_of_all);
       
        int group_1 = 0;
        int group_2 = 0;
        for(int element : nums)
        {
            
            if((element & mask))
                group_1 ^= element;
            else 
                group_2 ^= element;
        }
        return {group_1 , group_2};
    }

};
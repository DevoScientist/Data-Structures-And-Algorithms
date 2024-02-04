class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> New_arr;
        for(auto x : arr)
        {
            set<char> s(x.begin() , x.end());
            if(s.size() == x.size()) New_arr.push_back(x);
            else continue;
        }

        string op = "";
        return subsets(New_arr ,0, op);
    }
private :
    int subsets(vector<string>& arr ,int pos , string op)
    {
        int count = 0;
        if(pos == arr.size())
            return op.size(); // returns size of the sub string.
        int z = subsets(arr , pos + 1 , op);
        
        // checking for if the elements of the upcoming string is already present in op or not.
        bool checker = false;
        for(auto x : arr[pos])
        {
            auto it = find(op.begin(), op.end(), x);
            if(it != op.end()) checker = true;
        }

        if( !checker ) //if not present is op, then we can go to next node;
            op += arr[pos];
        else
            return z; // prune this branch and go to the parent Node.
        return max(z , subsets(arr , pos + 1 , op ) /* -> the next recursion with pos in op */);
                // returns the maximum size among all feasible sub-sequences.
    
    }
};
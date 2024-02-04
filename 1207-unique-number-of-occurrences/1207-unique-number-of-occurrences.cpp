class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int ,int> freq;
        for(auto x : arr)
            freq[x]++;
        set<int> s;
        for(auto pair : freq)
            s.insert(pair.second);
        if(s.size() != freq.size()) return false;
        else return true;
    }
};
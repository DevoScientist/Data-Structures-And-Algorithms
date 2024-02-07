class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char , int> freq;
        for(auto c : s)
            freq[c]++;
        
        auto cmp = [&](char a, char b)
        {
            if(freq[a] == freq[b])
                return (int)a > (int) b;
            return freq[a] > freq[b];
        };
        
        sort(s.begin(),s.end(),cmp);
        return s;
    } 
};
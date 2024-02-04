class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int , int> win,lose;
        for(int i =0; i < matches.size(); i++)
        {
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        for (auto it = win.begin(); it != win.end(); ++it)
        {
            auto it2 = lose.find(it->first);
            if(it2 == lose.end()) ans[0].push_back(it->first);
        }

        for (auto it = lose.begin(); it != lose.end(); ++it) 
            if(it->second == 1) ans[1].push_back(it->first);
            
        return ans;
    }
};
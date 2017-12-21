class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for(string s : strs)
        {
            string t=s;
            sort(t.begin(),t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> ret;
        for(auto m : mp)
        {
            vector<string> ana(m.second.begin(),m.second.end());
            ret.push_back(ana);
        }
        return ret;
    }
};

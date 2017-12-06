class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows>s.length()||numRows==1) return s;
        string ret;
        vector<vector <char>> zig(numRows);
        for(int i=0;i<s.length();i++)
        {
            if(i%(2*numRows-2)<numRows) zig[i%(2*numRows-2)].push_back(s[i]);
            else zig[(2*numRows-2)-i%(2*numRows-2)].push_back(s[i]);
        }
        for(int i=0;i<zig.size();i++)
        {
            for(int j=0;j<zig[i].size();j++)
            {
                ret.push_back(zig[i][j]);
            }
        }
        return ret;
    }
};
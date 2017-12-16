class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if(candidates.empty()) return ret;
        sort(candidates.begin(),candidates.end());
        vector<int> solution;
        backtrack(candidates, target, ret, solution, 0);
        return ret;
    }
private:
    void backtrack(vector<int>& candidates,int target,vector<vector<int>>& ret,vector<int>& solution, int begin)
    {
        if(target==0)
        {
            ret.push_back(solution);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            solution.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], ret, solution, i);
            solution.pop_back();
        }
    }
};
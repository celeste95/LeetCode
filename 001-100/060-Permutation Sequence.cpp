class Solution {
    //TLE
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        for(int i=1;i<=n;i++) num.push_back(i);
        vector<vector<int>> result(permute(num));
        string ret;
        for(int i=0;i<result[k-1].size();i++) ret+=(to_string(result[k-1][i]));
        return ret;
    }
private:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    //swap(num[begin], num[i]);
		}
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        int i, j, t, sum, jie;
        jie = 1;
        for (i = 1; i <= n; i++){
            jie = i * jie;
            ans += to_string(i);
        }
        for (i = 0; i < n; i++){
            jie /= n - i;
            for (sum = 0, j = 1; j <= n; j++){
                if (sum + jie >= k) break;
                sum += jie;
                swap(ans[i], ans[i + j]);
            }
            k -= sum;
        }
        return ans;
    }
};
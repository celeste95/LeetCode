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

string getPermutation(int n, int k) {
    int pTable[10] = {1};
    for(int i = 1; i <= 9; i++){
        pTable[i] = i * pTable[i - 1];
    }
    string result;
    vector<char> numSet;
    numSet.push_back('1');
    numSet.push_back('2');
    numSet.push_back('3');
    numSet.push_back('4');
    numSet.push_back('5');
    numSet.push_back('6');
    numSet.push_back('7');
    numSet.push_back('8');
    numSet.push_back('9');
    while(n > 0){
        int temp = (k - 1) / pTable[n - 1];
        result += numSet[temp];
        numSet.erase(numSet.begin() + temp);
        k = k - temp * pTable[n - 1];
        n--;
    }
    return result;
}
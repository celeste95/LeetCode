class Solution {
	//my solution 3ms
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        if(numRows==0) return a;
        a.push_back({1});
        if(numRows==1) return a;
        a.push_back({1,1});
        if(numRows==2) return a;
        for(int i=2;i<numRows;i++)
        {
            a.push_back({1});
            int j=1;
            while(j<i)
            {
                a[i].push_back(a[i-1][j-1]+a[i-1][j]);
                j++;
            }
            a[i].push_back(1);
        }
        return a;
    }
};

class Solution {
	//example solution 0ms
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ret;
        for(int i=0;i<numRows;i++){
            ret.push_back(vector<int>(i+1,0));
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    ret[i][j]=1;
                }else{
                    ret[i][j]=ret[i-1][j-1]+ret[i-1][j];
                }
            }
        }
        return ret;
    }
};
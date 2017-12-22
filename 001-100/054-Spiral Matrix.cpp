class Solution {
    //n*n matrix
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int lenm=matrix.size();
        for(int i=0;i<(lenm+1)/2;i++)
        {
            int j,k,l,m;
            for(j=i;j<lenm-i-1;j++) ret.push_back(matrix[i][j]);
            for(k=i;k<lenm-i-1;k++) ret.push_back(matrix[k][j]);
            for(l=lenm-i-1;l>i;l--) ret.push_back(matrix[k][l]);
            for(m=lenm-i-1;m>i;m--) ret.push_back(matrix[m][l]);
        }
        if(lenm%2) ret.push_back(matrix[lenm/2][lenm/2]);
        return ret;
    }
};

class Solution {
private:
    bool next(int& i,int& j,vector<vector<bool>>& visited,int& dir)
    {
        visited[i][j]=true;
        switch(dir)
        {
            case 0:
            {
                if(!visited[i][j+1]){j++;return true;}
                else dir=(dir+1)%4;
            }
            case 1:
            {
                if(!visited[i+1][j]){i++;return true;}
                else dir=(dir+1)%4;
            }
            case 2:
            {
                if(j>0&&!visited[i][j-1]){j--;return true;}
                else dir=(dir+1)%4;
            }
            case 3:
            {
                if(i>0&&!visited[i-1][j]){i--;return true;}
                else dir=(dir+1)%4;
            }
        }
        if(visited[i][j+1]&&visited[i+1][j]&&(j==0||visited[i][j-1])&&(i==0||visited[i-1][j]))
            return false;
        return next(i,j,visited,dir);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m=matrix.size();
        if(m==0) return ret;
        int n=matrix[0].size();
        int dir=0;
        vector<vector<bool>> visited(m+1,vector<bool>(n+1,true));
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) visited[i][j]=false;
        int i=0,j=0;
        while(1) {
            ret.push_back(matrix[i][j]);
            if(!next(i,j,visited,dir)) break;
        }
        return ret;
    }
};


public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        
        List<Integer> res = new ArrayList<Integer>();
        
        if (matrix.length == 0) {
            return res;
        }
        
        int rowBegin = 0;
        int rowEnd = matrix.length-1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;
        
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Traverse Right
            for (int j = colBegin; j <= colEnd; j ++) {
                res.add(matrix[rowBegin][j]);
            }
            rowBegin++;
            
            // Traverse Down
            for (int j = rowBegin; j <= rowEnd; j ++) {
                res.add(matrix[j][colEnd]);
            }
            colEnd--;
            
            if (rowBegin <= rowEnd) {
                // Traverse Left
                for (int j = colEnd; j >= colBegin; j --) {
                    res.add(matrix[rowEnd][j]);
                }
            }
            rowEnd--;
            
            if (colBegin <= colEnd) {
                // Traver Up
                for (int j = rowEnd; j >= rowBegin; j --) {
                    res.add(matrix[j][colBegin]);
                }
            }
            colBegin ++;
        }
        
        return res;
    }
}
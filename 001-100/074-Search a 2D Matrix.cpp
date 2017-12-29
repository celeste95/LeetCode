class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.size()==0) return false;
//         if(matrix[0].size()==0) return false;
//         int top=0;
//         int bottom=matrix.size()-1;
//         while(top<=bottom)
//         {
//             int mid = top + ((bottom - top) >> 1); 
//             if(matrix[mid][0]>target) bottom = mid - 1;
//             else top = mid + 1;
//         }
//         return binary_search(matrix[top].begin(),matrix[top].end(),target);
//     }
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if(matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n - 1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int e = matrix[mid/n][mid%n];
        if(target < e)
        {
            end = mid - 1;
        }
        else if(target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
};


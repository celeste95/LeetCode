class Solution {
	//my solution 3ms O(n) space 
public:
    vector<int> getRow(int rowIndex) {
        vector<int> array;
        array.push_back(1);
        if(rowIndex==0) return array;
        array.push_back(1);
        if(rowIndex==1) return array;
        int i=1;
        while(i<rowIndex)
        {
            for(int j=array.size()-1;j>0;j--)
            {
                array[j]+=array[j-1];
            }
            array.push_back(1);
            i++;
        }
        return array;
    }
};

class Solution {
	//0 ms solution 构造整个数组
public:
    vector<int> getRow(int rowIndex) {
        vector<int> array;
        array.push_back(1);
        if(rowIndex==0) return array;
        array.push_back(1);
        if(rowIndex==1) return array;
        int i=1;
        while(i<rowIndex)
        {
            for(int j=array.size()-1;j>0;j--)
            {
                array[j]+=array[j-1];
            }
            array.push_back(1);
            i++;
        }
        return array;
    }
};
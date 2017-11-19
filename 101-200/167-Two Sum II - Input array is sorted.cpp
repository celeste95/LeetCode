class Solution {
	//暴力搜索
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int i=0,j=0;
        for(int i=0;i<numbers.size();i++)
        {
            j=i+1;
            while(numbers[i]+numbers[j]<target) j++;
            if(numbers[i]+numbers[j]==target)
            {
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
        }
    }
};

// two pointers O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        vector<int> ret;
        while (low < high) {
            if (numbers[low] + numbers[high] == target) {
                ret.push_back(low + 1);
                ret.push_back(high + 1);
                return ret;
            } else if (numbers[low] + numbers[high] < target) {
                low++;
            } else { // > target
                high--;
            }
        }
        throw "not found error";
        return ret;
    }
};
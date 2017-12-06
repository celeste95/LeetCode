class Solution {
public:
    int maxArea(vector<int>& height) {
		//O(n^2) TLE
        int max=0;
        for(int i=0;i<height.size()-1;i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                int temp = (j-i)*min(height[i],height[j]);
                max = temp > max ? temp : max;
            }
        }
        return max;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
		//O(n) AC
        int water=0;
        int left=0,right=height.size()-1;
        while(right>left)
        {
            int h=min(height[left],height[right]);
            water=max(water,h * (right-left));
            while(height[left]<=h && left<right) left++;
            while(height[right]<=h && left<right) right--;
        }
        return water;
    }
};
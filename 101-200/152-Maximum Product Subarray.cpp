class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return maxpro(nums,0,nums.size()-1);
    }
    int maxpro(vector<int>& nums,int start,int end)
    {
        if(start>end) return 0;
        if(start==end) return nums[start];
        for(int i=start;i<=end;i++) {
            if(nums[i]==0) return max(0,max(maxpro(nums,start,i-1),maxpro(nums,i+1,end)));
        }
        //int minuscnt=0;
        int product=1;
        for(int i=start;i<=end;i++) {
            product*=nums[i];
            //if(i<0) minuscnt++;
        }
        if(product>0)  return product;
        else{
            int first,last;
            int leftmax=1,rightmax=1;
            for(int i=start;i<=end;i++) {
                if(nums[i]<0) {
                    first=i;
                    break;
                }
            }
            for(int i = end;i>=start;i--) {
                if(nums[i]<0) {
                    last=i;
                    break;
                }
            }
            for(int i = start;i<=last-1;i++) {
                leftmax*=nums[i];
            }
            for(int i = first+1;i<=end;i++) {
                rightmax*=nums[i];
            }
            return max(leftmax,rightmax);
        }
    }
};

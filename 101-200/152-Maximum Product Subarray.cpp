class Solution {
    //my solution
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

class Solution {
    //example solution
 public:
    int maxProduct(int A[], int n) {
    	int frontProduct = 1;
    	int backProduct = 1;
  		int ans = INT_MIN;
  		for (int i = 0; i < n; ++i) {
  			frontProduct *= A[i];
  			backProduct *= A[n - i - 1];
  			ans = max(ans,max(frontProduct,backProduct));
  		    frontProduct = frontProduct == 0 ? 1 : frontProduct;
  		    backProduct = backProduct == 0 ? 1 : backProduct;
        }
        return ans;
    }
};

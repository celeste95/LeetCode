class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        vector<int> profit(prices);
        profit[0]=0;
        int maxprofit=0;
        for(int i=1;i<prices.size();i++)
        {
            profit[i]=max(prices[i]-prices[i-1]+profit[i-1],0);
            if (profit[i]>maxprofit) maxprofit=profit[i];
        }
        return maxprofit;
    }
};
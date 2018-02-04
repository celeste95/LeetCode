class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length=gas.size();
        int remaining=0;
        int start=0;
        for(int i=0;;i++) {
            if(i>2*length) return -1;
            remaining+=(gas[i%length]-cost[i%length]);
            if((i+1)%length==start&&remaining>=0) return start;
            if(remaining<0) {
                start=(i+1)%length;
                remaining=0;
            }
        }
    }
};

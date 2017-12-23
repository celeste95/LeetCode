/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool compare(Interval a, Interval b)
    {
        if(a.start != b.start) return a.start < b.start;
        else return a.end < b.end;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.size()==0) return ret;
        sort(intervals.begin(),intervals.end(),compare);
        int left = intervals[0].start;
        int right = intervals[0].end;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start>right)
            {
                Interval temp(left,right);
                ret.push_back(temp);
                left=intervals[i].start;
                right = intervals[i].end;
            }
            else
            {
                right= intervals[i].end>right ? intervals[i].end : right;
            }
        }
        Interval temp(left,right);
        ret.push_back(temp);
        return ret;
    }
};

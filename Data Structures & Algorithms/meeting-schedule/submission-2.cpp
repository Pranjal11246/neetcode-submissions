/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()<=1)return true;
        sort(intervals.begin(),intervals.end(),[]( const Interval& a, Interval& b){
           return a.end<b.end;
        });
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(res[0].end > intervals[i].start)return false;
            res.pop_back();
            res.push_back(intervals[i]);
        }

        return true;
    }
};

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


struct heapcmp{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<pair<int,int>, vector<pair<int,int>>, heapcmp> activeRooms;

        for (int i = 0; i < intervals.size(); i++){
            if (activeRooms.empty()) activeRooms.push({intervals[i].start,intervals[i].end});
            else{
                if (intervals[i].start >= activeRooms.top().second) {
                    activeRooms.pop();                                   
                }
                activeRooms.push({intervals[i].start,intervals[i].end});
                
            }
        }
        return activeRooms.size();
    }
};

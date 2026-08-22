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
        static bool cmp(const Interval& a, const Interval& b){
            return a.start < b.start;
        }

        int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < intervals.size(); i++){
            if (!minHeap.empty()){
                if (minHeap.top() <= intervals[i].start){
                    minHeap.pop();
                }
            }
            minHeap.push(intervals[i].end);
        }
        return minHeap.size();
    }
};

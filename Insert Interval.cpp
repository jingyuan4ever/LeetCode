#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		if (intervals.empty()){
			intervals.push_back(newInterval);
			return intervals;
		}
		auto first = intervals.end();
		auto last = intervals.begin() - 1;
		for (auto it = intervals.begin(); it != intervals.end(); it++){
			if (it->start <= newInterval.end)
				last = it;
		}
		for (auto it = intervals.end() - 1; it >= intervals.begin(); it--){
			if (it->end >= newInterval.start)
				first = it;
		}
		if (last < first){
			intervals.insert(first, newInterval);
			return intervals;
		}
		if (first->start < newInterval.start)
			newInterval.start = first->start;
		if (last->end > newInterval.end)
			newInterval.end = last->end;
		last++;
		intervals.erase(first, last);
		intervals.insert(first, newInterval);
		return intervals;
	}
};
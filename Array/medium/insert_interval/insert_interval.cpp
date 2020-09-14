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
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> arr;
	int ns = newInterval.start;					// 插入新区间的起始值
	int ne = newInterval.end;					// 插入新区间的末尾值
	int i = 0;

	for (; i < intervals.size(); i++)
	{
		if (ne < intervals[i].start)			// 如果新区间的末尾值比老区间的起始值都小，则直接退出
			break;
		else if (ns > intervals[i].end)			// 如果新区间的起始值比老区间的末尾值都大，则直接插入
			arr.push_back(intervals[i]);
		else									// 如果ns比老区间的起点值大但是比老区间的末尾值小，则更新
		{
			ns = min(ns, intervals[i].start);
			ne = max(ne, intervals[i].end);
		}
	}

	newInterval.start = ns;
	newInterval.end = ne;
	arr.push_back(newInterval);					// 将新区间插入
	for (; i < intervals.size(); i++)			// 将原始数组中剩余的数据区间插入新数组
		arr.push_back(intervals[i]);

	return arr;
    }
};

给定一组不重叠的时间区间，在时间区间中插入一个新的时间区间(如果有重叠的话就合并区间)。
这些时间区间初始是根据它们的开始时间排序的。
示例1:
给定时间区间[1,3]，[6,9]，在这两个时间区间中插入时间区间[2,5]，并将它与原有的时间区间合并，变成[1,5],[6,9].
示例2：
给定时间区间[1,2],[3,5],[6,7],[8,10],[12,16],在这些时间区间中插入时间区间[4,9]，并将它与原有的时间区间合并，变成[1,2],[3,10],[12,16].
这是因为时间区间[4,9]覆盖了时间区间[3,5],[6,7],[8,10].

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1: 
Given intervals[1,3],[6,9], insert and merge[2,5]in as[1,5],[6,9].

Example 2: 
Given[1,2],[3,5],[6,7],[8,10],[12,16], insert and merge[4,9]in as[1,2],[3,10],[12,16].

This is because the new interval[4,9]overlaps with[3,5],[6,7],[8,10].
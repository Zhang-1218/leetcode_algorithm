问题：
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest


思路：
首先进行数组排序，时间复杂度 O(nlogn)O(nlogn)
在数组 nums 中，进行遍历，每遍历一个值利用其下标i，形成一个固定值 nums[i]
再使用前指针指向 start = i + 1 处，后指针指向 end = nums.length - 1 处，也就是结尾处
根据 sum = nums[i] + nums[start] + nums[end] 的结果，判断 sum 与目标 target 的距离，如果更近则更新结果 ans
同时判断 sum 与 target 的大小关系，因为数组有序，如果 sum > target 则 end--，如果 sum < target 则 start++，如果 sum == target 则说明距离为 0 直接返回结果


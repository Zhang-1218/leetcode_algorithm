class Solution {
public:
    /*
    *  贪心解法: 从左向右迭代，逐个数字相加，当小于0时，则将和重置为0
    */
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;

        int m(nums.size()), sum(0), result(INT_MIN);

        for(int i = 0; i < m; i++)
        {
            sum += nums[i];
            result = max(sum, result);
            //如果sum < 0，重新开始找子序串
            if(sum < 0)
            {
                sum = 0;
            }
        }

        return result;
    }
}

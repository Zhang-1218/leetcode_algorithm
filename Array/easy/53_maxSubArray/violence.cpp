class Solution {
public:
    // 暴力解法
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int m(nums.size()), sum(0), max(INT_MIN);

        // 嵌套循环：寻找所有和的子序列
        for(int i = 0; i < m; i++)
        {
            sum = 0;
            for(int j = i; j < m; j++)
            {
                sum += nums[j];

                //更新最大子序列
                if(sum > max)
                    max = sum;
            }
        }
        return max;
    }
};

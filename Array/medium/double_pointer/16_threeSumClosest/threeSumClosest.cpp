class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        if(nums.size()<3)   return 0;

        sort(nums.begin(), nums.end());           // 排序

        int i(0), left(0), right(0), sum(0);
        int dif(nums[0]+nums[1]+nums[2]);         // 保存最接近的数值

        /*
        *   嵌套循环，双指针
        */
        while(i < nums.size())                    // 控制第一位数据 
        {
            left = i+1;
            right = nums.size()-1;
            while(left < right)                   // 双指针移动
            {
                sum = nums[i] + nums[left] + nums[right];
                if(abs(target-sum) < abs(target-dif)) // 更新数据
                    dif = sum;
            
                if(sum > target)                   // 和大于目标值，移动右指针
                    right--;
                else if(sum < target)              // 和小于目标值，移动左指针
                    left++;
                else
                    return sum;
            }
            
            i++;                                   // 更新双指针移动区间
        }

        return dif;
    }
};

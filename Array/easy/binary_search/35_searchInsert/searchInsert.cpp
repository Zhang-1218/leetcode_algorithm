class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(nums.empty())
            return 0;
        
        int m(0), n(nums.size()-1), mid;

        // 二分查找
        while(m <= n)
        {
            mid = (m+n)/2;
            if(nums[mid] < target)
            {
                m = mid+1;
            }
            else if(nums[mid] > target)
            {
                n = mid-1;
            }
            else
            {
                return mid;
            }
        }

        return m;
    }
};

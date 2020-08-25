class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        if(nums[0]>0) return ans;
        int i = 0;

        while(i<nums.size()){
            if(nums[i]>0) break;
            int left = i+1, right = nums.size()-1;
            
            while(left< right){
               
                // 转换为long long避免加法过程中溢出
                long long y = static_cast<long long>(nums[i]);
                long long x = static_cast<long long>(nums[left]);
                long long z = static_cast<long long>(nums[right]);

                if(x + y > 0-z)
                    right--;
                else if(x + y < 0-z)
                    left++;
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
            
		    // 相同的left和right不应该再次出现，因此跳过
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    while(left<right && nums[right] == nums[right-1])
                        right--;

                    left++;
                    right--;
                }
            }

            // 避免nums[i]作为第一个数重复出现
            while(i+1<nums.size()&&nums[i] == nums[i+1])
                i++;
            // 更新双指针移动区间
	    i++;
        }
        return ans;
    }
};

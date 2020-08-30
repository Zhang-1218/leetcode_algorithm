// 逆序对
namespace inversion_pair
{
	int process(vector<int>& nums, int left, int right);
	int merge(vector<int>& nums, int left, int mid, int right);

	void reverse_pair(vector<int>& nums)
	{
		if (nums.empty() || nums.size() < 2) // 异常判断
			return;

		int sum = process(nums, 0, nums.size() - 1);
		cout << sum << endl;
	}

	int process(vector<int>& nums, int left, int right)
	{
		if (left == right)
			return 0;

		int mid = left + ((right - left) >> 1);	// 寻找中位数
		return process(nums, left, mid) + process(nums, mid + 1, right) + merge(nums, left, mid, right);
	}

	int merge(vector<int>& nums, int left, int mid, int right)
	{
		vector<int> tmp(right - left + 1, 0);	// 创建临时数组保存合并数值
		int i(0), l(left), r(mid + 1), ret(0);

		while (l <= mid && r <= right)			// 左右子数组有序合并
		{
			// 左子数组中当前数严格大于右组数时，右组中有多少个(right - r + 1)数严格小于此时左组当前数nums[l]的，进行累加
			ret += nums[l] > nums[r] ? (right - r + 1) * 1 : 0;
			// 按照升序将原始左右子数组中的数据拷贝进入临时数组中
			tmp[i++] = (nums[l] < nums[r] ? nums[l++] : nums[r++]);
		}

		while (l <= mid)						// 左子数组有剩余数据
		{
			tmp[i++] = nums[l++];
		}
		while (r <= right)						// 右子数组有剩余数据
		{
			tmp[i++] = nums[r++];
		}

		for (int j = 0; j < tmp.size(); j++)	// 从临时数组中拷贝有序数据至原始数组中
		{
			nums[left + j] = tmp[j];
		}

		return ret;
	}

	void test()
	{
		int arr[] = { 5, 3, 9, 6, 7, 0};
		vector<int> nums(arr, arr + 6);
		reverse_pair(nums);
	}
}

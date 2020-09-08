/*
	*  荷兰国旗问题：
	*  给定一个数组和一个数key，请把小于key的数放在数组的左边，大于num的数放在数组的右边，等于key的数据放在中间。返回小于、大于区的分隔符
	*  要求时间复杂度为O(N),空间复杂度为O(1)
*/
vector<int> division_Three_array(vector<int>& nums, int key)
{
	if (nums.empty())
		return{};

	int len(nums.size()), flag_min(0), flag_max(len - 1);

	for (int i = 0; i <= flag_max; i++)
	{
		if (nums[i] < key)						// 当前数小于key
		{
			swap(nums[i], nums[flag_min++]);	// 当前值与小于区的下一个数据进行交换，小于区右扩
		}
			
		else if (nums[i] > key)					// 当前数大于key
		{
			swap(nums[flag_max--], nums[i--]);	// 当前数与大于区的前一个数据交换，大于区左扩，当前值不动
		}
	}

	return{ flag_min, flag_max };
}
	
// 荷兰国旗
vector<int> Dutch_flag_issue(vector<int>& nums, int L, int R, int key)
{
	if (nums.empty())
		return{};

	int less = L - 1;
	int more = R;
	int index = L;

	while (index < more)
	{
		if (nums[index] < key){					// 当前值小于key
			swap(nums[++less], nums[index++]);	// 当前值与小于区的下一个数据进行交换，小于区右扩, 索引加1
		}
		else if (nums[index] > key){			// 当前值大于key
			swap(nums[--more], nums[index]);	// 当前值与大于区的前一个数据进行交换，大于区左扩, 索引不变
		}
		else{									// 当前值等于key
			index++;							// 索引加1
		}
	}

	return{ less, more};
}

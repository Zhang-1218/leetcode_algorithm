	/*
	 * 划分数组：
	 * 给定一个数组和一个数key，请把小于等于key的数放在数组的左边，大于num的数放在数组的右边
     * 要求时间复杂度为O(N),空间复杂度为O(1)
	 */
	void division_Two_array(vector<int>& nums, int key)
	{
		if (nums.empty())
			return;

		int len = nums.size();
		int flag(0);	// 分割位

		for (int i = 0; i < len; i++)  
		{
			if (nums[i] <= key)
			{
				// 当i与flag不相等，说明当前数前面存在大于关键字的数据
				// 故
				if (i != flag)
				{
					swap(nums[i], nums[flag]);
				}
				// 小于等于区扩大一位
				flag++;
			}
		}

	}

	void division_Two(vector<int>& nums, int key)
	{
		if (nums.empty())
			return;

		int len(nums.size()), index(0), left(0);
		while (index < len)
		{
			if (nums[index] <= key)					// 当前数小于等于key
			{
				swap(nums[index++], nums[left++]);	// 当前数与小于等于区的下一个数据进行交换，同时小于等于区右扩
													// 注意left本身代表小于等于区的数据个数，所以其直接作为下标得到的是小于等于区的下一个数据
			}
			else
			{
				index++;							// 当前数大于key，索引增加
			}
		}
	}

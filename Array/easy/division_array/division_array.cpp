//给定一个数组和一个数key，请把小于等于key的数放在数组的左边，大于num的数放在数组的右边
// 要求时间复杂度为O(N),空间复杂度为O(1)
void division_array(vector<int>& nums, int key)
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
			// 故当前数与小于等于区的下一个数据进行交换
			if (i != flag)
			{
				int temp = nums[i];
				nums[i] = nums[flag];
				nums[flag] = temp;
			}
			// 小于等于区扩大一位
			flag++;
		}
	}

}

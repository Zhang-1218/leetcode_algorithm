// 快速排序：所有内部排序算法中平均性能最优的排序算法
// 时间复杂度：最坏O(N2), 最好O(NlogN)
// 空间复杂度：最坏O(N), 最好O(logN)
// 快排不稳定

/*
	* 快排1.0：
	* 选取最后一个数为枢纽元素，每次递归将确定此数的位置（其他重复的不做处理），再以其作为分割位，递归划分左右子区
	* 时间复杂度：最坏O(N2)，最好O(NlogN)
*/
int Partition_1_0(vector<int>& nums, int left, int right)
{
	int index(left), low(left - 1), high(right);
	while (index < high)
	{
		if (nums[index] <= nums[right])
		{
			swap(nums[index++], nums[++low]);
		}
		else
		{
			index++;
		}
	}
	swap(nums[low+1], nums[right]);
	return low;
}

void Quick_Sort_1_0(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int low = Partition_1_0(nums, left, right);
		Quick_Sort_1_0(nums, left, low);
		Quick_Sort_1_0(nums, low + 1, right);
	}
}

/*
* 快排2.0：
* 选取最后一个数为枢纽元素，每次递归将确定此数的位置（存在重复，进行聚拢）
* 左子区为小于区，中间区为等于区，右子区为大于区，再以等于区的左右下标作为分割位，分别递归划分左右子区
* 时间复杂度：最坏O(N2)，最好O(NlogN)
*/
vector<int> Partiton_2_0(vector<int>& nums, int left, int right)
{
	int index(left), low(left - 1), high(right);

	while (index < high)
	{
		if (nums[index] < nums[right])
		{
			swap(nums[index++], nums[++low]);
		}
		else if (nums[index] > nums[right])
		{
			swap(nums[--high], nums[index]);
		}
		else
		{
			index++;
		}
	}
	swap(nums[high], nums[right]);
	return {low, high};
}

void Quick_Sort_2_0(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		//swap(nums[left + rand() % (right - left)], nums[right]);
		vector<int> p = Partiton_2_0(nums, left, right);
		Quick_Sort_1_0(nums, left, p[0]);
		Quick_Sort_1_0(nums, p[1] + 1, right);
	}
}

/* 
	* 快排3.0:
	* 随即从当前表中选取枢纽元素，进行递归排序，并且对于将选取的枢纽元素全部集中在一起
	* 再次递归时，左右子区的大小由枢纽元素区所定
	* 时间复杂度：因为随机选取枢纽元素，所以每种情况都是1/N，经数学证明，最终可收敛于O(NlogN)
*/
vector<int> Partiton_3_0(vector<int>& nums, int left, int right)
{
	int index(left), low(left - 1), high(right);

	while (index < high)
	{
		if (nums[index] < nums[right])
		{
			swap(nums[index++], nums[++low]);
		}
		else if (nums[index] > nums[right])
		{
			swap(nums[--high], nums[index]);
		}
		else
		{
			index++;
		}
	}

	swap(nums[high], nums[right]);
	return{ low, high };
}

void Quick_Sort_3_0(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		swap(nums[left + rand() % (right - left)], nums[right]);
		vector<int> p = Partiton_3_0(nums, left, right);
		Quick_Sort_1_0(nums, left, p[0]);
		Quick_Sort_1_0(nums, p[1] + 1, right);
	}
}

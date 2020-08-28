// 寻找数组当中两个出现次数为奇数个数的数字
void findTwoNum(vector<int>& nums)
{
	// 假设两个奇数个数分别为a，b
	int a(0), b(0), key(0);

	// 数组中所有数字进行异或，得到结果为 a = a^b
	for (int n : nums)
	{
		a = a^n;
	}

	// 求取 a^b 中二进制位最右边（第一位）为1的数值
	key = a & (~a + 1);
	
	// a^b 的结果展示了两数二进制位中的不同的位，所以可以据此对数组进行划分
	for (int n : nums)
	{
		if (key & n) // 当与key与为真时，说明是同一个数
		{
			b ^= n;
		}
	}

	b = a^b;	// b = (a^b)^b = a;
	a = a^b;	// a = (a^b)^a = b;

	cout << a << " " << b << endl;
}

void test()
{
	int arr[] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4};
	vector<int> nums(arr, arr+16);
	findTwoNum(nums);
}

#include<iostream>
#include<vector>

using namespace std;

void SubAscendArray()
{
	int len(0), i(0), flag(1);
	scanf("%d", &len);
	vector<int> nums(len, -1);

	while (i < len)
	{
		scanf("%d", &nums[i++]);
	}

	vector<int> v1(len, -1), v2(len, -1);
	for (i = 0; i < len; i++)			// 以下标i结尾的最长子序列
	{
		v1[i] = flag;
		if (i < len - 1)
		{
			flag = (nums[i] > nums[i + 1] ? 1 : (flag + 1));
		}
	}
	flag = 1;
	for (int i = len - 1; i >= 0; i--)	// 以下标i开始的最长子序列
	{
		v2[i] = flag;
		if (i != 0)
		{
			flag = (nums[i] < nums[i - 1] ? 1 : (flag + 1));
		}	
	}

	int maxlen(1), mm(0);
	for (i = 0; i < len; i++)
	{
		if (i > 0 && i < len - 1)							// 处于数组中间数据
		{
			if (nums[i + 1] - nums[i - 1] >= 2)				// 判断数据是否可以进行变换
			{
				mm = v1[i - 1] + v2[i + 1] + 1;				// 获取子序列长度
			}
		}
		else{												// 处于数组起始或末尾，单独处理
			mm = (i == 0 ? v2[i + 1] + 1 : v1[i - 1] + 1);	
		}

		if (maxlen < mm)									// 更新最长子序列长度
		{
			maxlen = mm;
		}
	}
	cout << maxlen << endl;
}

int main()
{
    SubAscendArray();
    return 0;
}


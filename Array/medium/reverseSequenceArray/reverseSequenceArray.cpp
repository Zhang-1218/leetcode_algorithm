#include<iostream>
#include<vector>
using namespace std;

void reverseSequenceArray()
{
    int len(0), n(0);
    cin >> len;
    
    vector<int> nums(len, -1);

	while (n != len)
	{
		cin >> nums[n++];
	}
    
    // 前半部分数据顺序，为原始数据以最后一个数据为起点从后向前，以2为步长进行递减
    for(int i = n - 1; i >= 0; i -= 2)
    {
        cout << nums[i] << " ";
    }
    // 后半部分数据顺序，根据n为奇偶进行区分，n为奇数则为原始数据以第2个元素（n为偶数则为原始数据以第1个元素）为起点从前向后，以2为步长进行递增
    for(int j = n%2; j < n; j+=2)
    {
        cout << nums[j] << " ";
    }

}

int main()
{
    reverseSequenceArray();
    return 0;
}


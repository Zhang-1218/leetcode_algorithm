
#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 循环比对两个单词是否相等
bool compare(string str1, string str2)
{
    int len = str1.size();
    
    // 单词循环多次
    for(int i = 0; i < len; i++)
    {
        bool flag = true;
        // 每次循环进行比对
        for(int j = 0; j < str2.size(); j++)
        {
            if(str1[(i+j)%len] != str2[j])
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            return true;
    }
    
    return false;
}

void loopWord()
{
    int k(0), i(0);
	cin >> k;

	vector<string> words(k, "");

    // 将所有单词加入vector中
	while (i != k)
	{
		cin >> words[i];
		i++;
	}
    
    // 嵌套循环，将每个单词与所有其他单词对比
	for (int j = 0; j < words.size(); j++)
	{
		for (int l = j + 1; l < words.size(); l++)
		{
            // 如果两个单词长度不相等，则跳过
			if (words[j].size() != words[l].size())
			{
				continue;
			}
			else
            {
                if(compare(words[j], words[l])) // 判断两个单词是否相等
                {
                    words.erase(words.begin() + l); // 相同将另一个单词从数组中删除
                    l--;                            // 删除数据后，要更新索引
                }
            }
        }
    }
    
    cout << words.size();
}

int main()
{
    loopWord();
    return 0;
}



#include<iostream>
#include<vector>
#include<string>

using namespace std;

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
				char ch;
				string s = words[j];
                // 嵌套循环，将单词整体循环至原始单词
				for (int p = 0; p < s.size()-1; p++)
				{
					bool flag = false;
					for (int k = s.size() - 1; k > 0; k--)
					{
						if (k == s.size() - 1)
							ch = s[k];
						s[k] = s[k - 1];
						if (k == 1)
							s[0] = ch;
                        
                        // 每完整循环一次，就进行比对
						if (!s.compare(words[l]))
						{
							words.erase(words.begin() + l); // 相等将另外的单词擦除
							l--;                            // 更新下标
							flag = true;
							break;
						}
					}
					if (flag)
						break;
				}
			}
		}
	}

    // words中保存的单词就是所有循环的单词
	cout << words.size() << endl;
}

int main()
{
    loopWord();
    return 0;
}


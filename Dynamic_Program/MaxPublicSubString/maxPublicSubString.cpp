#include<iostream>
#include<string>
#include<vector>

using namespace std;

// 动态规划dp求解
void maxSubString()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    
    int len1(str1.size()), len2(str2.size()+1);
    int dp[100][100] = {0}; // 表示str1以i结尾和str2以j结尾的子串的最长公共连续子串长度
    int max(-1);
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            if(str1[i] == str2[j]) // 只有当i、j相等时才能去看dp[][]是否满足条件
            {
                if(i > 0 && j > 0)
                {
                    dp[i][j] = dp[i-1][j-1] + 1;    // i=j且大于0即不是初值，所以此时dp[i][j]就等于其子问题再加1
                }else
                {
                    dp[i][j] = 1;                   // 起始位置，dp值为1
                }
            }
            // 每次dp后，更新最大值
            if(max < dp[i][j])
            {
                max = dp[i][j];
            }
        }
    }
        
    cout << max << endl;
}

int main()
{
    maxSubString();
    return 0;
}


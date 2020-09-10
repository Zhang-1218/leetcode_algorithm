#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void findTrangle()
{
    int k(0), count(0);
    cin >> k;
    vector<int> lenarr(k, -1);
    while(k != -1)
    {
        cin >> lenarr[k-1];
        k--;
    }
    int n = lenarr.size();
    sort(lenarr.begin(), lenarr.end());
    
    // 三角形两脚之和大于第三边
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = i+1; j < n - 1; j++)
            for(int k = j+1; k < n; k++)
            {
                if(lenarr[i] + lenarr[j] > lenarr[k])
                    count++;
            }
    }
    
    cout << count << endl;
}

int main()
{
    findTrangle();
    return 0;
}



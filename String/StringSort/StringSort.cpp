#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void StringSort()
{
    string s;
    while(getline(cin, s))
    {
        vector<char> strs;
        for(int i = 0; i < 26; i++)
        {
            for(auto c : s)
            {
                if(c ==('a'+i) || c == ('A'+i))
                {
                    strs.push_back(c);
                }
            }
        }
        
        int j = 0;
        for(auto c : s)
        {
            if(std::find(strs.begin(), strs.end(), c) != strs.end())
            {
                cout << strs[j++];
            }else{
                cout << c;
            }
        }
        
        cout << endl;
    }
}

int main()
{
    StringSort();
    return 0;
}

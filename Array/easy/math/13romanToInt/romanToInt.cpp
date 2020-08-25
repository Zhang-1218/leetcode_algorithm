class Solution {
public:
    /*
	罗马数字转整数
    */
    int romanToInt(string s) {

        int prev(0), result(0);

        for(int i=0; i<s.size(); i++)
        {
            int temp=getNum(s[i]);     // 遍历下一位数据
            
	    if(prev < temp)	       // 保留值（前面数据）小于遍历位，执行减法
            {
                result-=prev;
            }
            else 		       // 保留值（前面数据）大于遍历位，执行>加法
            {
                result+=prev;
            }
            prev=temp;                 // 保留当前数值
        }

        return result+prev;

    }

    int getNum(char ch)
    {
        switch(ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }        
    }

};

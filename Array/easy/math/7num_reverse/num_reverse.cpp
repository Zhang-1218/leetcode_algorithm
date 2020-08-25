class Solution {
public:
    //方法：数字模除转换
        int reverse(int x) {
        
        int m(0);
        long n(0);  // 定义long，防止int溢出

        while(x!=0)
        {
            m=x%10;
            x=x/10;
            n=n*10+m;

            if(n>INT_MAX || n<INT_MIN) // 溢出检查
                return 0;
        }

        return int(n);
    }

};

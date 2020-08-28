//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    /*
    * 思路：因为从上到下、从左到右都是递增的，所以考虑从最后一个子数组中的最小值（第一个数值）进行比对，两种情况：
    * 1、当其比目标值大，说明此子数组不符合条件，行数减一（上移），与上一层子数组的第一个数组继续进行比对
    * 2、当其比目标值小，说明目标值只可能存在此子数组中，与子数组中所有的数值进行一一比对
    */
    bool Find(int target, vector<vector<int> > array) {
        int row(array.size()), col(array[0].size());
        if(!row||!col) return false;
        
        int i(row-1), j(0);
        
        while(i >= 0 && j < col){
            if(array[i][j] > target)      // array[i]数组中最小值都比target大，故排除此子数组，更新子数组下标
                i--;
            else if(array[i][j] < target) // array[i]数组中最小值比target小，target可能在此子数组中，更新子数组数值下表
                j++;
            else 
                return true;
        }
        return false;
    }
};

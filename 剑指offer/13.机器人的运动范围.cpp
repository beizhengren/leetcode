class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows < 1 || cols < 1 || threshold < 0) return 0;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                //只能push_back或者emplace_back，不能直接下标赋初值
                memo.emplace_back(false);
            }
        }
        return helper(threshold, rows, cols, 0, 0);
    }
    
private:
    int helper(int k, int rows, int cols, int strRow, int strCol){
        if( strRow <0 || strRow >= rows || strCol <0 || strCol >= cols) return 0;
        int Num = 0;
        int idx = strRow * cols + strCol;
        if(getSum(strRow, strCol) <= k && memo[idx] == false){
            memo[idx] = true;//满足条件 标记
            Num = 1;//满足条件至少为1。一次调用结果：0 或者 自己本身次数1+递归次数
            for(int i = 0; i < 4; ++i){
                int newRow = strRow + arr[i][0];
                int newCol = strCol + arr[i][1];
                Num += helper(k, rows, cols, newRow, newCol);//递归加上后边的
            }
        }
        return Num;
    }
    vector<bool> memo;
    int arr[4][2] = {{0,1}, {1,0}, { -1, 0}, {0, -1}};
    int getSum(int a, int b){
        int sum = 0, sum1 = 0, sum2 = 0;
        while(a){
            sum1 += a%10;//这里是+=
            a /= 10;
        }
        
        while(b){
            sum2 += b%10;
            b /= 10;
        }
        sum = sum1 + sum2;
        return sum;
    }
};

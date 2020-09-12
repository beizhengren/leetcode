class Solution {
public:
    int Fibonacci(int n) {
        //递归终止条件
        if(n==0) return 0;
        if(n==1) return 1;
        //最终结果
        int sum = 0;
        //初始值
        int sum1 = 0;
        int sum2 = 1;  
        for(int i = 2; i < n+1; ++i){
            sum = sum1+sum2;
            sum1 = sum2;
            sum2 = sum;
        }
        return sum;
    }
};

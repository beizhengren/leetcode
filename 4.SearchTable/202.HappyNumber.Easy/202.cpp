class Solution {
public:
    int digitSquareSum(int n) {
    int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if(fast == 1) return 1;
        } while(slow != fast);
    return 0;
}
  
};

/*
  
    
    
    bool isHappy(int n) {       
        if(n < 10) return false;

        int sum = 0;
        while(sum != 1){
            vector<int> vec;
            while( n / 10){
                vec.emplace_back(n % 10);    
                n /= 10;
            }
        
            for(int i = 0; i < vec.size(); ++i){
                sum += vec[i] * vec[i];
            }
            n = sum;
            if(n < 10) return false;
        }
       return true;
    }
    */

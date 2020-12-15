class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(),[](int a, int b){return abs(a) > abs(b);});
        for (int i = 0; i < A.size() && K > 0; ++i) {
            if (A[i] < 0 ) {
                A[i] = -A[i];
                --K;
            }
        }
        
        if (K > 0 && K&0x01 ) {
            A[A.size()-1] *= -1;
        }
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
        }
        return sum;
    }

};

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;//这个必须得加上
        return helper(sequence, 0, sequence.size()-1);
    }
    
    bool helper(const vector<int>& sequence, int beg, int end){
        // 必须是>=0; ==0是一个（叶子）节点；>0是空，本质上就是左子树或者右子树为空的情况
        if(beg >= end) return true;
        //0. seek root
        auto root = sequence[end];
        //1. seek left tree
        int i = beg;
        while(sequence[i] < root) ++i;
        /*for(; i < end; ++ i){
            if(sequence[i]>root)
                break;
        }*/
        
        int j = i;
        while(sequence[j] >root) ++j;
        /*
        for(; j < end; ++j){
            if(sequence[j] < root)
                return false;
        }
        */
        return j == end && helper(sequence, beg, i-1) && helper(sequence, i, end-1);
    }
};

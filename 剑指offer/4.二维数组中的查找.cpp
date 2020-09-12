class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //从右上角开始
        int cols = array[0].size();
        int rows = array.size();
        if(cols == 0 || rows == 0) return false;
        int row = 0;
        int col = cols-1;
        while(row < rows && col >=0){
            if(array[row][col] > target){
                --col;                
            }
            else if (array[row][col] < target){
                ++row;
            }
            else return true;
        }
        return false;
    }
};

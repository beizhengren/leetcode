class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows < 1  || cols < 1 || str == nullptr){
            return false;
        }
        for( int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                memo.emplace_back(false);        
            }
        }
        int strIdx = 0;
        for( int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(helper(matrix, rows, cols, str, strIdx, i, j))
                    return true;
            }
        }
        return false;
    }

private:
    //递归语义：起点为strRow strCol，从字符串str的strIdx开始寻找，看是否有满足条件的路径。
    bool helper(const char* matrix, int rows, int cols, const char* str, int& strIdx, int strRow, int strCol){
        if(str[strIdx] == '\0') return true;//递归终止条件，找到最后一个时候返回true；
        int mIdx = strRow * cols + strCol;
        
        if(  strRow >= 0 && strRow < rows && strCol >= 0 && strCol < cols && matrix[mIdx] == str[strIdx] && memo[mIdx]==false){
            ++strIdx;
            memo[mIdx] = true;
            for(int i = 0; i < 4; ++i){
                int newRow = strRow + arr[i][0];
                int newCol = strCol + arr[i][1];
                if(helper(matrix, rows, cols, str, strIdx, newRow, newCol)){
                    return true;
                }
            }
            --strIdx;
            memo[mIdx] = false;
        }
        return false;
    }
    int arr[4][2]={{0, -1}, {-1,0}, {0,1}, {1,0}};
    vector<bool>memo;    
};

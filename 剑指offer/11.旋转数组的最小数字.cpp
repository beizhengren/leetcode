//二分 log(n)
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        //数组旋转0个或者全部个数的元素
        if(rotateArray[0] < rotateArray[rotateArray.size()-1]) return rotateArray[0];
        //数组旋转[0, rotateArray.size()-1]个元素
        //那么，数组第一个肯定>数组最后一个元素。
        return getMin(rotateArray, 0, rotateArray.size()-1);
    }
private:
    int getMin(const vector<int>& arr, int beg, int end){
        
        while(beg<end){//因为终止是end - beg ==1。或者arr[beg]>=arr[end].
            if(end - beg == 1) return arr[end];//相差为1的时候找到（严格递增）
            int mid = beg + (end-beg)/2;//防止越界
            if(arr[beg] <= arr[mid]){
                beg = mid;
            }
            if(arr[end] >= arr[mid] ){
                end = mid;
            }
            //如果出现相等的情况，只能逐个扫描
            if(arr[beg] == arr[mid] && arr[end] == arr[mid]){
                int min = arr[mid];
                for(int i = beg+1; i < end; ++i){
                    if(arr[i] <= min)
                        min = arr[i];
                }
                return min;
            }
        }
    }
};

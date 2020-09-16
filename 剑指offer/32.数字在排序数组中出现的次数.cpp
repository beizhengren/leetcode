class Solution {
public:
    //k即便在[ data[0], data[size-1] ] 范围内, data中也不一定就存在数字与其相等.
    int GetNumberOfK(vector<int> data ,int k) {
        int size = data.size();
        if(size == 0) return 0;
        
        int cnt = 0;
        int low = 0, high = size - 1, mid = 0;
        while(low < high){
            mid = low + (high -low) / 2;
            if(data[mid] == k) break;
            else if(data[mid] < k) low = mid + 1;//严格的条件关系
            else high = mid - 1;//严格的条件关系
        }

        //从mid-1往前找
        for(int i = mid; i >= 0; --i){
            if(data[i] == k){
                cnt++;
            }else break;//没找到直接break;
        }
        //从mid+1往后找
        for(int i = mid + 1; i < size; ++i){
                if(data[i] == k){
                    cnt++;
                }else break;
        }
        
        return cnt;
    }
    
};

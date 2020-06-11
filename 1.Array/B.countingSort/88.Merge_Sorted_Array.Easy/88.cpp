class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //index
        // calculate the index of the last element of the merged array
        auto idx = m + n - 1;
        auto idx1 = m - 1;
        auto idx2 = n - 1;
        //from rear to begin
        while(idx1 >= 0 && idx2 >= 0){
            if(nums1[idx1] > nums2[idx2]){ nums1[idx--] = nums1[idx1--];}
            else{nums1[idx--] = nums2[idx2--];}    
        }
        
        // if nums2 is reserved, just copy the rest of nums2 to nums1 location, otherwise no need to do anything
        while(idx2 >= 0 ){
            nums1[idx--] = nums2[idx2--];
        }       
    }
};

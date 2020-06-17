class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
     int l = 0, r = numbers.size() - 1;
     while(l < r) {
        auto sum = numbers[l] + numbers[r];
        if(sum == target) {
            int array[2] = {l + 1, r + 1};
            return vector<int>(array, array + 2);
        } else if(sum > target) {
             r--;
        }else{
            l++;
        }
        
     }
        throw(invalid_argument("the input has no sloution"));
    }
};

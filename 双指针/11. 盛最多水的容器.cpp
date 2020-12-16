class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0;
        int r = height.size()-1;
        while (l <= r) {
            int temp = (r - l) * (min (height[l], height[r]));
            result = max(result, temp);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
};

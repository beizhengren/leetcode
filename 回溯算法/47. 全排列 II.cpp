//Solution 1
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        //去重必须排序
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }

private:
    void backtracking(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if(i > 0 && used[i-1] == false && nums[i] == nums[i-1]) {
                continue;
            }

            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> result;
    vector<int> path;
};

//Solution 2
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        //用uset去重，同样也必须排序
        //491上升子序列是有“上升”的限制不能排序，因此即使两个相同元素是间隔的，
        //也会因为“上升”这个限制给剔除掉。
        //而，对于两个元素不是间隔的就和排好序的一样（即sort）
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }

private:
    void backtracking(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        //用于只记录当前层不同树枝的元素选取情况
        //这个比上一种方法多用了个数组，即去重。（类似递增子序列491，但是递增子序列是用i+1限制每次遍历的范围，不得不用uset去重。）
        //而上一种发法used既限定了遍历的范围，又可以去重。
        bool uset[21] {false};
        for (int i = 0; i < nums.size(); ++i) {
            if(i > 0 && uset[nums[i] + 10] == true && nums[i] == nums[i-1]) {
                continue;
            }

            if (used[i] == false) {
                used[i] = true;
                uset[nums[i] + 10] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> result;
    vector<int> path;
};

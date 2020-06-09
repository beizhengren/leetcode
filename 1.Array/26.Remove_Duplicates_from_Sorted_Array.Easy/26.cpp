///solution 1 (152ms)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(auto it = nums.begin(); it != nums.end();){
            auto itR = it;
            ++itR;

            if(itR != nums.end()){
                if(*it == *itR) nums.erase(itR);
                else{ ++it;}
            }else{break;}
        }
        return nums.end() - nums.begin();*/
    }
}

///solution 2 (12ms)

	int count{0};
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums [i-1]) { ++count; }//有重复count++;
            else{
                nums[i-count] = nums[i];//不相等就赋值给前面的
            }
        }
        return nums.size() - count;//运行结束之后vector的size不变，只是需要的元素前移，并没有删除

///solution 3 (12 ms)
//删除元素
       return distance(nums.begin(),unique(nums.begin(), nums.end()));


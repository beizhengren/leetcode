class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); ++i){
            unordered_map<int, int> m1;
            for(int j = 0; j < points.size(); ++j){
                if(j!=i)
                    m1[distance(points[i], points[j])]++;
            }

            for(const auto& it: m1){
                res += it.second * (it.second - 1);
            }
        }
        return res;
    }

private:
    //it's essential to use reference, or time limit exceeded
    int distance(const vector<int>& vecA, const vector<int>& vecB){
        int sum = 0;
        for(int i = 0; i < vecA.size(); ++i){
            sum += (vecA[i] - vecB[i]) * (vecA[i] - vecB[i]);
        }
        return sum;
    }

};

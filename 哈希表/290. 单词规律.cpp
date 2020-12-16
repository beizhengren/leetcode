

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap;
        vector<string> vecString;
        split(s, vecString);
        if (pattern.size() != vecString.size()) {return false;}
        // 以pattern中的每个元素为key，s中的单词为value
        // 判断是否相同的key对应相同的value
        // 成立。但有问题：key不同对应的value可能相同。
        for (int i = 0; i < pattern.size(); ++i) {
            if (umap.find(pattern[i]) == umap.end()) {
                umap.insert({pattern[i], vecString[i]});
            } else {
               if(umap[pattern[i]] == vecString[i]){continue;               }else {return false;}
            }
        }
        // 以s中的每个单词为key，pattern中的元素为value
        // 判断是否相同的单词key对应相同的字符value
        // 可以解决上面第一次循环存在的问题
        unordered_map<string, char> umap2;
        for (int i = 0; i < vecString.size(); ++i) {
            if (umap2.find(vecString[i]) == umap2.end()) {
                umap2.insert({vecString[i], pattern[i]});
            } else {
                if (umap2[vecString[i]] != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    void split (const string& s, vector<string>& vecString) {
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                int len = i - start;
                vecString.emplace_back(s.substr(start, len));
                start = i + 1;
            }
        }
        vecString.emplace_back(s.substr(start, s.size()-start));
    }
};

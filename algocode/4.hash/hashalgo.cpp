//题目主要来源于leetcode

/*无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度  */


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> wins;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (wins.find(s[i]) != wins.end()){
                wins.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            wins.insert(s[i]);
        }
        return maxStr;
    }
};



/*有效的数独
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
  */


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>> row(9), col(9), block(9);
        for(int i = 0; i < 9; ++ i){
            for(int j = 0; j < 9; ++ j){
                int no =  (i / 3)* 3 + j / 3;
                char cur = board[i][j];
                if(cur == '.')
                    continue;
                if(row[i].count(cur) || col[j].count(cur) || block[no].count(cur))
                    return false;
                row[i][cur] = 1;
                col[j][cur] = 1;
                block[no][cur] = 1;
            }
        }
        return true;
    }
};


/*字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。  */



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int sub = 0;
        string tmp;
        unordered_map<string,int> work;
        for(const auto& str:strs)
        {
            tmp = str;
            sort(tmp.begin(),tmp.end());
            if(work.count(tmp))
            {
               res[work[tmp]].push_back(str);
            }
            else
            {
                vector<string> vec(1,str);
                res.push_back(vec);
                work[tmp] = sub++;
            }
        }
        return res;
    }
};

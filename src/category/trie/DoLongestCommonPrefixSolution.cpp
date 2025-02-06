/**
 * 14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

提示：
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 如果非空，则仅由小写英文字母组成

链接： https://leetcode.cn/problems/longest-common-prefix/description/?envType=problem-list-v2&envId=trie
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 字典树节点定义
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class DoLongestCommonPrefixSolution {
public:
    TrieNode* root;

    DoLongestCommonPrefixSolution() {
        root = new TrieNode();
    }

    // 插入单词
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    // 找到所有插入单词的最长公共前缀
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";

        // 插入字符串到 Trie 中
        for (const string &word: strs) {
            insert(word);
        }

        TrieNode* node = root;
        string prefix = "";

        // 遍历 Trie 获取最长公共前缀
        while (node) {
            // If the node has only one child, continue the prefix
            if (node->children.size() == 1 && !node->isEndOfWord) {
                char c = node->children.begin()->first;
                prefix += c;
                node = node->children[c];
            } else {
                break;
            }
        }

        return prefix;
    }

    string longestCommonPrefix1(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }

        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                // 索引 i > 字符串长度  或者 字符串目标索引 i 字符不等于 c  不用在继续比较了
                if ((i >= strs[j].size()) || (strs[j][i] != c)) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};


// 测试用例 g++ -std=c++11 DoLongestCommonPrefixSolution.cpp -o DoLongestCommonPrefixSolution
int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    DoLongestCommonPrefixSolution lcp;
    string prefixStr = lcp.longestCommonPrefix(strs);
    cout << "Longest common prefix: " << prefixStr << endl;
}
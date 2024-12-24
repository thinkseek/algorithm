/**
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长
子串的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

提示：
0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=problem-list-v2&envId=string
*/
#include <string>
#include <unordered_set>
using namespace std;
#include "DoMaxNoDuplicateStringsSolution.h"

// 实现
// 使用滑动窗口（Sliding Window）技术，来实现这一功能
int DoMaxNoDuplicateStringsSolution::lengthOfLongestSubstring(std::string input) {
    // 输入校验
    // 空字符串，不存在这个问题，做默认处理
    if(input.length() <= 0) {
        return 0;
    }

    // 1、工具字段（使用start/end双指针滑动窗口）
    int start = 0; //起始指针
    unordered_set<char> char_set; //记录字符串的字符，用来判断是否重复

    // 记录字段
    int max_start = 0; //子串起始位置
    int max_length = 0; //最长子串长度
    string max_substr = ""; //最大子串长度

    // 2、执行滑动分析，从头开始滑动 end 作为滑动指针
    for(int end=0; end<input.length(); ++end) {
        // 判断字符是否出现重复，如果出现了，移动起始指针 start 前进，并清理重复字符，直到没有重复字符结束
        while(char_set.find(input[end]) != char_set.end()) {
            char_set.erase(input[start]); // 删除重复字符，直到没有重复字符结束
            ++start;
        }

        // 记录容器，不存在重复的 ADD
        char_set.insert(input[end]);

        // 重复子串长度计算，只记录最大长度的子串即可；长度相等的子串，记录第一次匹配的结果
        if(end - start + 1 > max_length) {
            max_length = end - start + 1;
            max_start = start;
            max_substr = input.substr(max_start, max_length);
        }
    }

    cout << "字符串长度：" << max_length << " 字符串：" << max_substr << endl;
    return max_length;
}


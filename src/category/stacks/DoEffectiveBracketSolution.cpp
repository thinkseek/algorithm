/**
* 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([])"
输出：true

提示：
1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/

#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class DoEffectiveBracketSolution {
public:
    // 使用栈结构解决这个问题
    bool isValid(string s) {
        // 定义栈结构对象
        std::stack<char> stk;

        // 符合要求的字符对
        std::unordered_map<char, char> mapping = {
                {')', '('},
                {'}', '{'},
                {']', '['}
        };

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (stk.empty() || stk.top() != mapping[s[i]]) {
                    return false;
                }
                // 匹配就弹出即可，开始下一个字符匹配
                stk.pop();
            }
        }


        return stk.empty(); // 空即为有效字符串，否则则是非法字符串
    }
};
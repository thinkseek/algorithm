/**
 * 9. 回文数
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
例如，121 是回文，而 123 不是。

示例 1：
输入：x = 121
输出：true

示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3：
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。

提示：
-231 <= x <= 231 - 1

进阶：你能不将整数转为字符串来解决这个问题吗？

链接：https://leetcode.cn/problems/palindrome-number/description/
 */

#include <string>
#include <iostream>
using namespace std;
class DoPalindromeNumberSolution {
public:
    bool isPalindrome(int x) {
        // 负数 和 非0数字，确认不是回文
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        // 整数转字符串
        string str = to_string(x);

        // 字符串逆序
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        // 判断值是否一致
        return str == revStr;
    }
};

int main() {
    DoPalindromeNumberSolution* st = new DoPalindromeNumberSolution();
    cout << "result:" << st->isPalindrome(121) << endl;
    cout << "result:" << st->isPalindrome(-121) << endl;
    cout << "result:" << st->isPalindrome(0) << endl;
    return 0;
}
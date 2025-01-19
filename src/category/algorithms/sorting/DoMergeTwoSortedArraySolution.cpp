/**
 * 88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

示例 2：
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。

示例 3：
输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

提示：
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？
链接： https://leetcode.cn/problems/merge-sorted-array/
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DoMergeTwoSortedArraySolution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        // 1.将num2合并到nums1，需要考虑nums1的 0 占位，这个是更新逻辑
        for (int i = m; i < (m + n); ++i) {
            nums1[i] = nums2[i - m];
        }

        // 2.排序
        // 标准库
        sort(nums1.begin(), nums1.end());

        // 自助排序（冒泡方式）
//        for (int i = 0; i < nums1.size(); ++i) {
//            for (int j = i + 1; j < nums1.size(); ++j) {
//                if (nums1[i] > nums1[j]) {
//                    int tmp = nums1[i];
//                    nums1[i] = nums1[j];
//                    nums1[j] = tmp;
//                }
//            }
//        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    DoMergeTwoSortedArraySolution *st = new DoMergeTwoSortedArraySolution();
    st->merge(nums1, m, nums2, n);

    // 打印新数组
    for (int num: nums1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

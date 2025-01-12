/**
 * 704. 二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

提示：
你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
链接： https://leetcode.cn/problems/binary-search/?envType=problem-list-v2&envId=binary-search
 */

#include <vector>
#include <iostream>

using namespace std;

class DoBinarySearchSolution {
public:
    // 自定义二分查找实现
    // 二分查找算法的基本思想是在一个有序数组中通过反复将搜索范围减半来查找特定元素。以下是一个简单的自定义实现：
    int search(vector<int> &nums, int target) {
        // 数组已经排序好，直接遍历
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // 检查中间元素是否是目标值
            if (nums[mid] == target) {
                return mid; // 返回目标值的索引index
            }

            // 如果中间元素大于目标值，则忽略右半部分
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                // 否则，中间元素小于目标值，则忽略左半部分
                left = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 5};
    int target = -1;
    DoBinarySearchSolution *st = new DoBinarySearchSolution();
    int index = st->search(nums, target);
    cout << "num index:" << index << endl;
    return 0;
}

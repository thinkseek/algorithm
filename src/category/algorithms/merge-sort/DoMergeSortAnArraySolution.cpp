/**
 * 912. 排序数组
给你一个整数数组 nums，请你将该数组升序排列。
你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。

示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]

示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

提示：
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

链接： https://leetcode.cn/problems/sort-an-array/?envType=problem-list-v2&envId=merge-sort
 */

#include <vector>
#include <iostream>

using namespace std;

class DoMergeSortAnArraySolution {
public:
    // 标准库函数实现排序
    vector<int> sortArrayByStd(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }

    // 归并排序自定义实现
    vector<int> sortArray(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        mergeSortArray(nums, left, right);
        return nums;
    };
private:
    // 归并排序函数
    void mergeSortArray(vector<int> &nums, int left, int right) {
        // 对游标分治拆分，当left >= right 就拆分结束了，最终只需要做两个数之间的排序
        if (left < right) {
            int mid = left + (right - left) / 2;
            // 拆分，拆为两个子数组递归实现排序
            mergeSortArray(nums, left, mid); // 先排序 left-mid 这个子数组
            mergeSortArray(nums, mid + 1, right);

            // 归并，合并两个子数组并完成排序
            merge(nums, left, mid, right);
        }
    };

    // 合并数组
    // 举例说明：
    //  输入：5, 1, 1, 2, 0, 0  left=0,mid=2,right=5
    //  输出：0,0,2,5,1,1
    void merge(vector<int> &nums, int left, int mid, int right) {
        int n1 = mid - left + 1; // 左边的元素数量 3
        int n2 = right - mid; // 右边的元素数量 3

        // 创建临时数组，左边元素数组，右边元素数组
        vector<int> L(n1), R(n2);

        // 拷贝数据到临时数组 L[] 和 R[]
        for (int i = 0; i < n1; ++i) {
            L[i] = nums[left + i];
        }
        for (int j = 0; j < n2; ++j) {
            R[j] = nums[mid + 1 + j];
        }

        // 排序、合并临时数组回到 nums
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            // 实现从小到大排序
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                ++i;
            } else {
                nums[k] = R[j];
                ++j;
            }

            ++k;
        }

        // 拷贝 L[] 的剩余元素（如果有），通过递归继续排序
        while (i < n1) {
            nums[k] = L[i];
            ++i;
            ++k;
        }
        // 拷贝 R[] 的剩余元素（如果有）, 通过递归继续排序
        while (j < n2) {
            nums[k] = R[j];
            ++j;
            ++k;
        }
    }
};

int main() {
//    vector<int> nums = {5, 1, 1, 2, 0, 0};
    vector<int> nums = {-5, -2, -2};
    DoMergeSortAnArraySolution *st = new DoMergeSortAnArraySolution();
//    vector<int> newNums = st->sortArrayByStd(nums);
    vector<int> newNums = st->sortArray(nums);
    // 输出结果
    for (auto num: newNums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
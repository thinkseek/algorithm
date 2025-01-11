/**
* 15. 三数之和
* 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

提示：
3 <= nums.length <= 3000
-105 <= nums[i] <= 105

链接： https://leetcode.cn/problems/3sum/description/?envType=problem-list-v2&envId=array
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class DoThreeSumSolution {
public:
    // 双指针滑动窗口计数
    vector <vector<int>> threeSum(vector<int> &nums) {
        // 异常校验，必须大于3个数字
        int nums_len = nums.size();
        if (nums_len < 3) {
            return vector<vector<int>> {};
        }

        // 1、给数组排序
        sort(nums.begin(), nums.end());

        // 2、使用遍历 + 双指针游标计算（都移动）
        vector <vector<int>> expect_nums; // 记录匹配的组合结果
        // 遍历目标数组，依次匹配计算
        for (int i = 0; i < nums_len - 2; ++i) {
            // 4、优化：去重，已经匹配过的数字（i），不用重复，减少重复计算
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }

            // 3、双指针滑动 + 遍历数字（i），三数求和
            int left = i + 1; // 起始移动游标
            int right = nums_len - 1; // 尾部游标
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    // 记录符合条件的组合数字
                    expect_nums.push_back(vector<int> {nums[i], nums[left], nums[right]});

                    // 4、优化：去除重复计算（加分）
                    while(left<right && nums[left] == nums[left+1]) ++left; //左游标和前一个数值相等，左指针移动
                    while(left<right && nums[right] == nums[right-1]) --right;//左游标和后一个数值相等，右指针移动

                    // 没有数值重复，左右都移动，加速匹配
                    ++left;
                    --right;
                } else if (sum < 0) {
                    // 为负数，起始游标继续右移
                    ++left;
                } else {
                    // 为正数，尾部游标继续左移
                    --right;
                }
            }
        }

        return expect_nums;
    }
};


/** ************************** **/
// 测试用例 g++ -std=c++11 DoThreeSumSolution.cpp -o DoThreeSumSolution
int main()
{
    // 测试数据
    vector<int> nums = {-1,0,1,2,-1,-4};
//    vector<int> nums = {0,1,1};
//    vector<int> nums = {0,0,0};

    // New Instance
    DoThreeSumSolution ts;
    vector<vector<int>> ret = ts.threeSum(nums);
    cout << '[';
    for (int i = 0; i < ret.size(); ++i) {
        // 遍历每个符合要求的结果
        cout << '[';
        vector<int> sub_vector = ret[i];
        for (int k = 0; k < sub_vector.size(); ++k) {
            cout << sub_vector[k];
            if(k != sub_vector.size() - 1) {
                cout << ",";
            }
        }
        cout << ']';
        if(i != ret.size() - 1) {
            cout << ",";
        }
    }
    cout << ']' << endl;
    return 0;
}

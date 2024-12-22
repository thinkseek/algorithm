// =====================================================================================
//
//       Filename:  TwoSumSolution.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  2020/6/26 下午7:08
//       Revision:  none
//       Compiler:  g++
//
//         Author:  fsnail.wang@gmail.com
//
// =====================================================================================

/**
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

链接：https://leetcode-cn.com/problems/two-sum
*/
#include <iostream>
#include <vector>

class DoTwoSumSolution
{
public:
    vector<int> twoSum(vector<int> & nums, int target) {
        vector<int> vc;
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i) {
            for (int j = i+1; j < numsSize; ++j) {
                // 边界条件，两数之和为 target 即可
                // 注意要求返回的是两数的游标
                if(nums[i] + nums[j] == target) {
                    vc.push_back(i);
                    vc.push_back(j);
                    break;
                }
            }
        }

        return vc;
    }
};

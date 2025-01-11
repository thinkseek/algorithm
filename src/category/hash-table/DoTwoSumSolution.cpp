/**
 * 1. 两数之和
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
#include <unordered_map>
using namespace std;

class DoTwoSumSolution
{
public:
    // 方案1：使用暴力循环遍历
    vector<int> twoSum2(vector<int> & nums, int target) {
        // 异常的判断
        vector<int> vc;
        int nums_size = nums.size();
        if(nums_size < 2) {
            return vc;
        }

        // 二维循环遍历，组合匹配计算；注意要求返回的是两数的游标
        for (int i = 0; i < nums_size; ++i) {
            for (int j = i+1; j < nums_size; ++j) {
                // 边界条件，两数之和为 target 即可
                if(nums[i] + nums[j] == target) {
                    vc.push_back(i);
                    vc.push_back(j);
                    break;
                }
            }
        }

        return vc;
    }

    // 方案2：使用hashtable实现
    vector<int> twoSum(vector<int> & nums, int target) {
        // 异常的判断
        vector<int> vc;
        int nums_size = nums.size();
        if(nums_size < 2) {
            return vc;
        }

        // 一维偏历数组，使用hash判重，查找
        unordered_map<int,int> pair_map; // 数值，数值对应的游标
        for(int i=0; i<nums_size; ++i) {
            // 配对的差值
            int expected_num = target - nums[i];
            if(pair_map.count(expected_num)) {
                // 存在，说明查到了，即可结束
                return {pair_map[expected_num],i};
            }

            // hashtable没查到，则写入记录
            pair_map[nums[i]] = i;
        }

        return vc;
    }
};


/** ************************** **/
// 测试用例 g++ -std=c++11 DoTwoSumSolution.cpp -o DoTwoSumSolution
int main()
{
    // 测试数据
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // New Instance
    DoTwoSumSolution ts;
    vector<int> ret = ts.twoSum(nums, target);
    cout << '[';
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i];
        if(i != ret.size() - 1) {
            cout << ",";
        }
    }
    cout << ']' << endl;
    return 0;
}

/**
 * LCR 060. 前 K 个高频元素
给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。

示例 1：
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2：
输入: nums = [1], k = 1
输出: [1]

提示：
1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

进阶：所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

注意：本题与主站 347 题相同：https://leetcode-cn.com/problems/top-k-frequent-elements/

链接： https://leetcode.cn/problems/g5c51o/description/?envType=problem-list-v2&envId=bucket-sort
 */
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

class DoBucketSortSolution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // 使用 unordered_map 来记录每个数字的频率
        unordered_map<int, int> btMap; // 数字元素，元素出现频次

        // 1.频率计算
        for (int num: nums) {
            btMap[num]++;
        }

        // 2. 使用优先队列（最小堆）来找出前 K 个高频元素;
        // 使用 pair<int, int>，第一个元素，第二个元素出现频次
        // 小顶堆按频率排序的，当堆的大小超过 k 时，弹出频率最小的元素
        auto compare = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;  // a > b 表示 a 的优先级低于 b
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        for (const auto &pair: btMap) {
            pq.push(pair);
            // 如果堆的大小超过 k，则弹出频率最小的元素。
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // 3. 从优先队列中提取结果
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        // 4. 因为小顶堆是先弹出频率最小的，所以结果需要反转
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> testNums = {1, 1, 1, 2, 2, 3};
//    vector<int> testNums = {4, 1, -1, 2, -1, 2, 3};
    int topK = 2;
    DoBucketSortSolution *st = new DoBucketSortSolution();
    vector<int> result = st->topKFrequent(testNums, topK);
    cout << "TopK:";
    for (int topNum: result) {
        cout << topNum << " ";
    }
    cout << endl;
    return 0;
}
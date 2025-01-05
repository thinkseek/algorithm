/**
* 703. 数据流中的第 K 大元素
设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
请实现 KthLargest 类：
KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。

示例 1：
输入：
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
输出：[null, 4, 5, 5, 8, 8]

解释：
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // 返回 4    // 2, 3, 4, 5, 8
kthLargest.add(5); // 返回 5    // 2，3，4, 5, 5, 8
kthLargest.add(10); // 返回 5   // 2，3，4, 5, 5, 8, 10
kthLargest.add(9); // 返回 8    // 2，3，4, 5, 5, 8, 9, 10
kthLargest.add(4); // 返回 8    // 2，3，4, 4, 5, 5, 8, 9, 10

示例 2：
输入：
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
输出：[null, 7, 7, 7, 8]

解释：
KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // 返回 7
kthLargest.add(10); // 返回 7
kthLargest.add(9); // 返回 7
kthLargest.add(9); // 返回 8

提示：
0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
最多调用 add 方法 104 次

链接： https://leetcode.cn/problems/kth-largest-element-in-a-stream/description/?envType=problem-list-v2&envId=heap-priority-queue
*/

#include <vector>
#include <queue>
#include <functional>
using namespace std;

class KthLargest {
private:
    int numK; // 记录第 K 大元素
    priority_queue<int, vector<int>, greater<int> > minHeap; // 构建一个最小堆，保持大小是K，堆顶即为要查找的数字

public:
    KthLargest(int k, vector<int>& nums) {
        numK = k;
        // 使用 std::greater<int> 作为比较器，创建一个最小堆
        minHeap = priority_queue<int, vector<int>, greater<int> >();

        // 初始化堆，堆大小保持为 k
        for(int num : nums){
            add(num);
        }
    }

    int add(int val) {
        // 堆元素个数小于 K 个时，将元素写入堆
        if(minHeap.size() < numK) {
            minHeap.push(val);
        } else { // 堆的 size 等于 K 了

            // 当前元素大于堆顶元素，则替换堆顶元素。
            if (val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
            }

            // 否则栈顶已经是 topK 最小值了，直接获取堆顶元素即可
        }

        // 堆顶元素即为第 K 大元素
        return minHeap.top();
    }
};

// 扩展
// 在 std::priority_queue 的上下文中，std::greater<T> 被用作比较函数对象，以定义一个最小堆。默认情况下，std::priority_queue 是一个最大堆，即堆顶元素是优先级最高的元素（对于内置类型，通常是值最大的元素）。但是，如果你将 std::greater<T> 作为第三个模板参数传递给 std::priority_queue，那么它就会变成一个最小堆，堆顶元素将是优先级最低的元素（对于内置类型，通常是值最小的元素）。
// 创建一个最小堆的优先队列
// std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

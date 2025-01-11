/**
 * 225. 用队列实现栈
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
实现 MyStack 类：
void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

注意：
你只能使用队列的标准操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

示例：
输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False

提示：
1 <= x <= 9
最多调用100 次 push、pop、top 和 empty
每次调用 pop 和 top 都保证栈不为空
进阶：你能否仅用一个队列来实现栈。

链接： https://leetcode.cn/problems/implement-stack-using-queues/description/
 */
#include <queue>
#include <iostream>
using namespace std;

class MyStack {
private:
    queue<int> q1; // 空队列，用于新元素放入队首
    queue<int> q2; // 主结构，用于实现栈的特性

public:
    // 构造函数
    MyStack() {}

    // 入栈函数；栈的特点先进后出，后进的在栈顶,先出
    // 实现关键点：保持新元素始终在队首
    void push(int x) {
        // 新元素放入队列
        q1.push(x);

        // 备用队列q2 如果不为空，内容重新入队，排在后面
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        // 主队列 和 备用队列交换数值，q2是元素全集，且新元素始终在队首，q1始终是空队列
        swap(q1, q2);
    }

    // 出栈函数
    int pop() {
        if(q2.empty()) {
            throw out_of_range("Stack is empty");
        }

        int topElement = q2.front();
        q2.pop();  // 已出栈，删除元素
        return topElement;
    }

    // 查询栈顶元素
    int top() {
        if(q2.empty()) {
            throw out_of_range("Stack is empty");
        }

        int topElement = q2.front();
        return topElement;
    }

    // 是否是空栈
    bool empty() {
        return q2.empty();
    }
};


/** ************************** **/
// 用例测试
// 测试用例 g++ -std=c++11 DoMyStack.cpp -o DoMyStack
int main() {
//    示例：
//
//    输入：
//    ["MyStack", "push", "push", "top", "pop", "empty"]
//    [[], [1], [2], [], [], []]
//    输出：
//    [null, null, null, 2, 2, false]

    // New一个Stack实例
    MyStack *stack = new MyStack();
    stack->push(1);
    stack->push(2);
    int top = stack->top(); // 2
    cout << top << endl;
    int pop1 = stack->pop(); // 2
    cout << pop1 << endl;

    bool pop2 = stack->empty(); // 0
    cout << pop2 << endl;
    return 0;
}

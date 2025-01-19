# 迭代器（Iterator）是一种用于访问容器中元素的对象。迭代器提供了一种统一的方式来遍历序列（如数组、向量、列表等），而不需要关心底层容器的具体实现。迭代器使得容器和算法之间解耦，提高了代码的可重用性和灵活性。
* 迭代器的基本概念
* 迭代器类型：
  * 输入迭代器（Input Iterator）：只能向前移动一次（单向），用于读取数据。
  * 输出迭代器（Output Iterator）：只能向前移动一次，用于写入数据。
  * 前向迭代器（Forward Iterator）：可以多次遍历序列，但不能后退。
  * 双向迭代器（Bidirectional Iterator）：可以向前和向后移动。
  * 随机访问迭代器（Random Access Iterator）：支持高效的跳跃和比较操作，如 iterator[n] 和 iterator1 < iterator2。


/**
* 21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]

提示：
两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
链接： https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=problem-list-v2&envId=linked-list
*/
#include <iostream>

// 单链表节点定义
struct ListNode {
    // 数据结构
    int val;
    ListNode *next;

    // 构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class DoMergeTwoListsSolution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 创建一个空节点
        ListNode empty_node(0);

        // 遍历两个链表，判断值大小，写入新链表节点
        ListNode* current_node = &empty_node;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                current_node->next = list1;
                list1 = list1->next;
            } else {
                current_node->next = list2;
                list2 = list2->next;
            }

            current_node = current_node->next;
        }

        // 追加比较超出的部分
        current_node->next = (list1 != nullptr) ? list1 : list2;
        // 返回merge后的链表
        return empty_node.next;
    }
};


/** ************************** **/
// 用例测试
ListNode* createList(std::initializer_list<int> elements);
void printList(ListNode* head);

// 测试用例 g++ -std=c++11 DoMergeTwoListsSolution.cpp -o DoMergeTwoListsSolution
int main()
{
    // 创建两个有序链表
    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});

    // 合并链表  1 1 2 3 4 4
//    printList(l1);
//    printList(l2);
    DoMergeTwoListsSolution solution;
    ListNode* head = solution.mergeTwoLists(l1, l2);
    printList(head);
    return 0;
}

// 打印合并后的链表
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode* createList(std::initializer_list<int> elements) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : elements) {
        current->next = new ListNode(val);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}
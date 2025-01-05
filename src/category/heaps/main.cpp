// 用例测试
#include <iostream>
#include <vector>
using namespace std;
#include "DoKthLargest.cpp"

// 测试用例 g++ -std=c++11 main.cpp -o DoKthLargest
int main() {
    int k = 3;
    vector<int> numVector = {4, 5, 8, 2};
    vector<int>& nums = numVector;
    KthLargest *kth = new KthLargest(k, nums);

    cout << "top3 num val is:" << kth->add(3) << endl; // 返回 4
    cout << "top3 num val is:" << kth->add(5) << endl; // 返回 5
    cout << "top3 num val is:" << kth->add(10) << endl; // 返回 5
    cout << "top3 num val is:" << kth->add(9) << endl; // 返回 8
    cout << "top3 num val is:" << kth->add(4) << endl; // 返回 8
    return 0;
}
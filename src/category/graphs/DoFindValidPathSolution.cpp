/**
* 1971. 寻找图中是否存在路径
有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。图中的边用一个二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 每个顶点对由 最多一条 边连接，并且没有顶点存在与自身相连的边。
请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径。
给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回 true，否则返回 false 。

示例 1：
       0
      / \
     1 -- 2
输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
输出：true
解释：存在由顶点 0 到顶点 2 的路径:
- 0 → 1 → 2
- 0 → 2

示例 2：
       0
      / \
     1  2
       3
      / \
     4 -- 5
输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
输出：false
解释：不存在由顶点 0 到顶点 5 的路径.

提示：
1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
不存在重复边
不存在指向顶点自身的边
链接： https://leetcode.cn/problems/find-if-path-exists-in-graph/?envType=problem-list-v2&envId=graph
*/

#include <vector>
#include <iostream>
using namespace std;

class DoFindValidPathSolution {
public:
    /**
     * 查找图是否存在指定的边
     * @param n 顶点个数
     * @param edges 图的所有边
     * @param source 指定起点
     * @param destination 指定终点
     * @return 回复是否存在
     */
    bool validPath(int n, vector<vector<int> > &edges, int source, int destination) {
        // 1、顶点和关系处理，方便递归遍历
        vector<vector<int> > edgeMapping(n);
        for (vector<int> edge : edges) {
            // 顶点 ui 和顶点 vi 之间的双向边
            int ui = edge[0];
            int vi = edge[1];
            edgeMapping[ui].push_back(vi);
            edgeMapping[vi].push_back(ui);
        }

        // 2、dfs递归遍历
        vector<bool> visited(n, false); // 初始化一个图的边数大小的访问记录结构
        if(dfs(edgeMapping, source, destination, visited)) {
            return true;
        }
        return false;
    }

private:
    bool dfs(vector<vector<int> > &edges, int current, int destination, vector<bool>& visited) {
        // 当前顶点等于目标顶点，则已查找到
        if(current == destination) {
            return true;
        }

        visited[current] = true; // 访问记录


        // 对当前顶点相邻的所有顶点进行递归操作
        for (int neighbor : edges[current]) {
            // 对没有访问过的顶点进行递归
            if(!visited[neighbor]) {
                // 开始查找，如果查到了结束，没有继续下一个顶点的递归查询
                if(dfs(edges, neighbor, destination, visited)){
                    return true;
                }
            }
        }

        return false;
    }
};


/** ************************** **/
// 测试用例 g++ -std=c++11 DoFindValidPathSolution.cpp -o DoFindValidPathSolution
int main() {
    // 测试数据
    //     0
    //    / \
    //    1  2
    //      3
    //     / \
    //    4 -- 5
//    int n = 6;
//    vector<vector<int> > edges = {
//        {0,1},
//        {0,2},
//        {3,5},
//        {5,4},
//        {4,3}
//    };
//    int start = 0;
//    int target = 5;


// 预期是 true
    int n = 10;
    vector<vector<int> > edges = {
        {4,3},
        {1,4},
        {4,8},
        {1,7},
        {6,4},
        {4,2},
        {7,4},
        {4,0},
        {0,9},
        {5,4}
    };
    int start = 0;
    int target = 5;

    // new 测试实例
    auto* st = new DoFindValidPathSolution();
    bool result = st->validPath(n, edges, start, target);
    cout << "Find Result:" << result << endl;
    return 0;
}

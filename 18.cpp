// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560929792044
// 地图问题，是游戏里回出现的逻辑
// 是很经典的搜索问题，可以用深度优先搜索（DFS）或广度优先搜索（BFS）解决

// 使用一个二维数组 visited 来记录每个位置是否已经被访问过。
// 使用一个二维数组 a 来存储地图的高度信息。

/*
DFS 搜索：
从每个未访问的位置开始，进行深度优先搜索。
在搜索过程中，记录当前路径的长度，并更新最大路径长度。
每次移动时，检查是否满足交替上坡和下坡的条件。
边界条件：
如果当前位置已经访问过，或者移动到的位置高度相同，则停止搜索。
如果移动到的位置不满足交替上坡和下坡的条件，则停止搜索。

使用了回溯（backtracking）来标记和取消标记访问过的位置
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int m, int n, vector<vector<int>> &a, vector<vector<bool>> &visited, int x, int y, bool isUp)
{
    // 标记当前位置为已访问
    visited[x][y] = true;
    int maxPath = 0;

    // 定义四个方向的移动
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // 遍历四个方向，nx,ny是新位置
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 检查新位置是否在地图范围内
        if (nx >= 0 && nx < m && ny >= 0 && ny < n)
        {
            // 检查新位置是否未访问过
            if (!visited[nx][ny])
            {
                // 检查是否满足交替上坡和下坡的条件
                if ((isUp && a[nx][ny] < a[x][y]) || (!isUp && a[nx][ny] > a[x][y]))
                {
                    // 递归调用DFS，并更新最大路径长度
                    maxPath = max(maxPath, dfs(m, n, a, visited, nx, ny, !isUp) + 1);
                }
            }
        }
    }

    // 回溯：标记当前位置为未访问
    visited[x][y] = false;

    // 返回当前路径长度
    return maxPath;
}

int solution(int m, int n, vector<vector<int>> &a)
{
    // 初始化visited数组
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int maxPath = 0;

    // 从每个位置开始进行DFS
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // 尝试从当前位置开始，分别以向上和向下两种方向进行DFS
            // （之前只有一种，默认一开始就是上坡了，其实有两种可能
            maxPath = max(maxPath, dfs(m, n, a, visited, i, j, true));
            maxPath = max(maxPath, dfs(m, n, a, visited, i, j, false));
        }
    }

    return maxPath;
}

int main()
{
    vector<vector<int>> a1 = {{1, 2}, {4, 3}};
    cout << (solution(2, 2, a1) == 3) << endl;

    vector<vector<int>> a2 = {{10, 1, 6}, {5, 9, 3}, {7, 2, 4}};
    cout << (solution(3, 3, a2) == 8) << endl;

    vector<vector<int>> a3 = {
        {8, 3, 2, 1}, {4, 7, 6, 5}, {12, 11, 10, 9}, {16, 15, 14, 13}};
    cout << (solution(4, 4, a3) == 11) << endl;
}
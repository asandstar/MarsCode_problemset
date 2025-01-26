// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855076929580
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 检查在给定位置 (x, y) 放置棋子后是否能形成五子连线
bool checkWin(int n, vector<vector<int>> &array, int x, int y, int dx, int dy)
{
    int count = 1; // 当前棋子已经算一个
    // 向正方向检查
    int i = x + dx, j = y + dy;
    while (i >= 0 && i < n && j >= 0 && j < n && array[i][j] == 1)
    {
        count++;
        i += dx;
        j += dy;
    }
    // 向反方向检查
    i = x - dx, j = y - dy;
    while (i >= 0 && i < n && j >= 0 && j < n && array[i][j] == 1)
    {
        count++;
        i -= dx;
        j -= dy;
    }
    return count >= 5;
}

vector<vector<int>> solution(int n, vector<vector<int>> &array)
{
    vector<vector<int>> result;

    // 遍历棋盘上的每一个位置
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (array[i][j] == 0)
            {
                // 检查在该位置放置棋子后是否能形成五子连线
                if (checkWin(n, array, i, j, 1, 0) || // 水平方向
                    checkWin(n, array, i, j, 0, 1) || // 垂直方向
                    checkWin(n, array, i, j, 1, 1) || // 对角线方向（左上到右下）
                    checkWin(n, array, i, j, 1, -1))
                {                                     // 对角线方向（右上到左下）
                    result.push_back({i + 1, j + 1}); // 转换为 1-based 坐标
                    // 0-based 坐标：在编程中，数组的索引通常从 0 开始。
                    // 1-based 坐标：在数学/生活中，坐标通常从 1 开始。
                }
            }
        }
    }

    // 对结果进行排序（默认按行数和列数从小到大排序）
    sort(result.begin(), result.end());

    return result;
}

int main()
{
    // 测试用例
    vector<vector<int>> array = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0}};
    vector<vector<int>> result = solution(6, array);
    for (const auto &pos : result)
    {
        cout << pos[0] << " " << pos[1] << endl;
    }
    return 0;
}
// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855075291180
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

int solution(std::vector<int> airports)
{
    // 初始化队列，起点入队
    std::queue<std::pair<int, int>> q; // 存储机场下标和起飞次数
    q.push({0, 0});                    // 起点下标为0，起飞次数为0

    // 初始化已访问集合
    std::unordered_set<int> visited;
    visited.insert(0); // 标记起点为已访问

    // BFS 主循环
    while (!q.empty())
    {
        auto [current, steps] = q.front();
        q.pop();

        // 如果当前机场是终点，返回起飞次数
        if (current == airports.size() - 1)
        {
            return steps;
        }

        // 将相邻机场入队
        if (current - 1 >= 0 && visited.find(current - 1) == visited.end())
        {
            // 确保有效性&判断是否访问过
            q.push({current - 1, steps + 1});
            visited.insert(current - 1);
        }
        if (current + 1 < airports.size() && visited.find(current + 1) == visited.end())
        {
            q.push({current + 1, steps + 1});
            visited.insert(current + 1);
        }

        // 将相同航空公司的机场入队
        for (int i = 0; i < airports.size(); ++i)
        {
            if (i != current && airports[i] == airports[current] && visited.find(i) == visited.end())
            {
                q.push({i, steps + 1});
                visited.insert(i);
            }
        }
    }

    return -1; // 如果无法到达终点，返回-1（理论上不会执行到这里）
}

int main()
{
    std::vector<int> airports1 = {10, 12, 13, 12, 14};
    std::vector<int> airports2 = {10, 11, 12, 13, 14};

    std::cout << (solution(airports1) == 3) << std::endl;
    std::cout << (solution(airports2) == 4) << std::endl;
    return 0;
}
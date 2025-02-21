// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7435955743769477164
#include <iostream>
#include <vector>
#include <algorithm> // for std::max
using namespace std;

int solution(std::vector<std::vector<int>> financials)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here

    int max_total = 0; // 用于存储最大的总资金

    // 遍历每个客户
    for (const auto &customer : financials)
    {
        int total = 0; // 当前客户的总资金

        // 计算当前客户的总资金
        for (int amount : customer)
        {
            total += amount;
        }

        // 更新最大总资金
        max_total = std::max(max_total, total);
    }

    return max_total;
}

int main()
{
    cout << (solution({{2, 4, 6}, {4, 3, 2}}) == 12) << endl;
    cout << (solution({{3, 9}, {8, 2}, {5, 6}}) == 12) << endl;
    cout << (solution({{5, 5, 9, 3}, {6, 2, 3, 1}, {3, 4, 10, 2}}) == 22) << endl;
    return 0;
}
// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855076012076
#include <iostream>
#include <vector>

// 要处理的是一个时间序列数据（即每天的股票价格）
// 并且需要考虑冷冻期
// 动态规划（Dynamic Programming, DP）是一个非常合适的选择
/*
问题的最优解可以通过子问题的最优解来构造
不同的决策路径可能会多次计算相同的子问题
问题的状态可以通过状态转移方程来描述
冷冻期为1天，贪心算法不再适用，
动态规划可以通过状态的定义和转移来处理这种限制
 */
int solution(std::vector<int> stocks)
{
    // Please write your code here
    int n = stocks.size();
    if (n == 0)
        return 0;
    // define
    //  dp[i][0]表示第i天结束时手中没有股票的最大利润
    //  dp[i][1]表示第i天结束时手中持有股票的最大利润
    //  dp[i][2]表示第i天结束时处于冷冻期的最大利润
    std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
    // 初始化
    dp[0][0] = 0;
    dp[0][1] = -stocks[0];
    dp[0][2] = 0;
    // transfer
    for (int i = 1; i < n; ++i)
    {
        // 第i天结束时手中没有股票的最大利润
        // dp[i][0] 可以从 dp[i-1][0]（前一天没有股票）或 dp[i-1][2]（前一天处于冷冻期）转移过来
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2]);
        // 第i天结束时手中持有股票的最大利润
        // dp[i][1] 可以从 dp[i-1][1]（前一天持有股票）或 dp[i-1][0]（前一天没有股票并且今天买入股票）转移过来
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - stocks[i]);
        // 第i天结束时处于冷冻期的最大利润
        // dp[i][2] 只能从 dp[i-1][1]（前一天持有股票并且今天卖出股票）转移过来
        dp[i][2] = dp[i - 1][1] + stocks[i];
    }
    return std::max(dp[n - 1][0], dp[n - 1][2]);
}

int main()
{
    // You can add more test cases here
    std::cout << (solution({1, 2}) == 1) << std::endl;
    std::cout << (solution({2, 1}) == 0) << std::endl;
    std::cout << (solution({1, 2, 3, 0, 2}) == 3) << std::endl;
    std::cout << (solution({2, 3, 4, 5, 6, 7}) == 5) << std::endl;
    std::cout << (solution({1, 6, 2, 7, 13, 2, 8}) == 12) << std::endl;
    return 0;
}

// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855074930732
#include <iostream>
#include <vector>
#include <string>
/*
转换数字为字符串：将输入的数字转换为字符串，方便逐位处理。
动态规划：我们可以使用动态规划来解决这个问题。定义一个数组 dp，其中 dp[i] 表示前 i 位数字可以翻译成字符串的总数。
状态转移：
如果当前位可以单独翻译成一个字符（即 s[i-1] 在 '0' 到 '9' 之间），则 dp[i] += dp[i-1]。
如果当前位和前一位可以组合翻译成一个字符（即 s[i-2:i] 在 '10' 到 '25' 之间），则 dp[i] += dp[i-2]。
初始条件：dp[0] = 1，表示空字符串有一种翻译方法。
假设输入的数字有 n 位，那么 dp 数组的长度通常是 n+1。
方便处理边界条件和初始条件，确保在计算过程中能够正确地利用之前的状态。
*/
int solution(int num)
{
    // Please write your code here
    std::string s = std::to_string(num);
    int n = s.size();
    // dynamic programming,dp[i] the sum of previous i numbers
    std::vector<int> dp(n + 1, 0);
    // init: the void string has only one translation
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] >= '0' && s[i - 1] <= '9')
        {
            dp[i] += dp[i - 1];
        }
        // 下面这里状态转移的时候需要跳位
        if (i > 1)
        {
            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigits >= 10 && twoDigits <= 25)
            {
                dp[i] += dp[i - 2];
            }
        }
    }
    return dp[n];
}

int main()
{
    // You can add more test cases here
    std::cout << (solution(12258) == 5) << std::endl;
    std::cout << (solution(1400112) == 6) << std::endl;
    std::cout << (solution(2110101) == 10) << std::endl;

    return 0;
}
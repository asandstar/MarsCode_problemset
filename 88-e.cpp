// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855076306988
#include <iostream>
#include <vector>
#include <unordered_map>
/*
先求出所有可能的子串，然后检查每个子串的和是否能被 b 整除。
这个思路在 n 较小的情况下是可行的，
但在 n 较大时（例如 n = 10^5），直接枚举所有子串的时间复杂度会非常高，
导致算法效率低下
*/
int solution(int n, int b, std::vector<int> sequence)
{
    // 前缀和数组
    std::vector<int> prefix_sum(n + 1, 0);
    // 哈希表，记录余数出现的次数
    std::unordered_map<int, int> remainder_count;
    // 初始化余数为0的情况
    remainder_count[0] = 1;
    // 计算前缀和，递推公式
    for (int i = 1; i <= n; ++i)
    {
        prefix_sum[i] = prefix_sum[i - 1] + sequence[i - 1];
    }
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        int remainder = prefix_sum[i] % b;
        // 如果之前有到达过相同的余数，说明两个位置之间的子串和可以被b整除
        if (remainder_count.find(remainder) != remainder_count.end())
        {
            count += remainder_count[remainder];
        }
        // 更新哈希表
        remainder_count[remainder]++;
    }
    return count;
}
// 如果之前出现过相同的余数，说明在这两个位置之间的子串和可以被 b 整除。
/*推导
定义一个前缀和数组 prefixSum，其中 prefixSum[i] 表示从序列的开始到第 i 个元素的和。具体来说：
prefixSum[0] = a[0]
prefixSum[1] = a[0] + a[1]
prefixSum[2] = a[0] + a[1] + a[2]
...
prefixSum[i] = a[0] + a[1] + ... + a[i]
模运算。对于一个数 x，x % b 表示 x 除以 b 的余数。
两个位置 i 和 j 的前缀和 prefixSum[i] 和 prefixSum[j] 对 b 取模的结果相同
prefixSum[i] % b == prefixSum[j] % b
prefixSum[i] - prefixSum[j] 是 b 的倍数
prefixSum[i] = k1 * b + r
prefixSum[j] = k2 * b + r
prefixSum[i] - prefixSum[j] = (k1 * b + r) - (k2 * b + r) = (k1 - k2) * b
从 j+1 到 i 的子串的和是 b 的倍数
两个位置的前缀和对 b 取模的结果相同，那么在这两个位置之间的子串的和就可以被 b 整除
*/
int main()
{
    // You can add more test cases here
    std::vector<int> sequence = {1, 2, 3};
    std::cout << (solution(3, 3, sequence) == 3) << std::endl;
    return 0;
}
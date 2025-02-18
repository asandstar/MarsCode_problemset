// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855076831276
#include <iostream>
#include <vector>
#include <algorithm>

int solution(int N, int M, std::vector<int> data)
{
    // 扩展数组
    std::vector<int> extended_data(N * M);
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            extended_data[i * N + j] = data[j];
        }
    }
    // 维护两个变量：
    // max_ending_here：表示以当前元素结尾的最大子数组和。
    // max_so_far：表示到目前为止找到的最大子数组和。
    // 算法通过遍历数组，不断更新这两个变量，最终得到最大子数组和。
    // Kadane算法用于找到数组中连续子数组的最大和

    // Kadane算法利用动态规划的思想
    int max_ending_here = extended_data[0];
    int max_so_far = extended_data[0];

    for (int i = 1; i < N * M; ++i)
    {
        max_ending_here = std::max(extended_data[i], max_ending_here + extended_data[i]);
        max_so_far = std::max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    // Add your test cases here
    std::cout << (solution(5, 1, {1, 3, -9, 2, 4}) == 6) << std::endl;
    std::cout << (solution(5, 3, {1, 3, -9, 2, 4}) == 11) << std::endl;
    return 0;
}
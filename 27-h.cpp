// 判断，最小的元素有几个，然后用n减去最小元素的个数就是有潜力的个数了
// 又是一道名不副实的hard题目，明明应该是简单，或者说是脑筋急转弯
#include <iostream>
#include <vector>
#include <algorithm>

int solution(int n, std::vector<int> u)
{
    // 找出最低等级
    int min_level = *std::min_element(u.begin(), u.end());

    // 统计最低等级的英雄数量
    int min_count = 0;
    for (int level : u)
    {
        if (level == min_level)
        {
            min_count++;
        }
    }

    // 计算有潜力的英雄数量
    return n - min_count;
}

int main()
{
    std::cout << (solution(5, {1, 2, 3, 1, 2}) == 3) << std::endl;
    std::cout << (solution(4, {100000, 100000, 100000, 100000}) == 0) << std::endl;
    std::cout << (solution(6, {1, 1, 1, 2, 2, 2}) == 3) << std::endl;
}
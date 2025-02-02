// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855075029036
#include <iostream>
#include <vector>

/*贪心算法：在每一步选择中都采取当前状态下最优选择，期望得到全局最优解
分析：
1.等级高的猫得到的鱼干>等级低的
2.满足上述要求，尽量减少每只猫的鱼干数
策略：
1.从左到右遍历，确保每只猫的鱼干数满足等级要求
2.从右到左遍历，确保每只猫的鱼干数满足等级要求
3.计算总的鱼干数
（两次遍历可以两个方向满足等级差异要求）
 */
int solution(int n, std::vector<int> cats_levels)
{
    // 初始化每只猫的鱼干数为1
    std::vector<int> fish_amounts(n, 1);

    // 从左到右遍历，确保每只猫的鱼干数满足等级要求
    for (int i = 1; i < n; ++i)
    {
        // 如果当前猫的等级高于前一只猫
        if (cats_levels[i] > cats_levels[i - 1])
        {
            // 增加当前猫的鱼干数，使其比前一只猫多
            fish_amounts[i] = fish_amounts[i - 1] + 1;
        }
    }

    // 从右到左遍历，确保每只猫的鱼干数满足等级要求
    for (int i = n - 2; i >= 0; --i)
    {
        // 如果当前猫的等级高于后一只猫
        if (cats_levels[i] > cats_levels[i + 1])
        {
            // 增加当前猫的鱼干数，使其比后一只猫多
            fish_amounts[i] = std::max(fish_amounts[i], fish_amounts[i + 1] + 1);
        }
    }

    // 计算总的鱼干数
    int total_fish = 0;
    for (int amount : fish_amounts)
    {
        total_fish += amount;
    }

    return total_fish;
}

int main()
{
    std::vector<int> catsLevels1 = {1, 2, 2};
    std::vector<int> catsLevels2 = {6, 5, 4, 3, 2, 16};
    std::vector<int> catsLevels3 = {1, 2, 2, 3, 3, 20, 1, 2, 3, 3,
                                    2, 1, 5, 6, 6, 5, 5, 7, 7, 4};
    std::cout << (solution(3, catsLevels1) == 4) << std::endl;
    std::cout << (solution(6, catsLevels2) == 17) << std::endl;
    std::cout << (solution(20, catsLevels3) == 35) << std::endl;
    return 0;
}
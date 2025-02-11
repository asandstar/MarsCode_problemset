// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855076962348
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>

std::string solution(int m, int n, std::string target,
                     std::vector<std::string> &array)
{
    // 不相容性格类型的检查
    std::unordered_map<char, std::unordered_set<char>> incompatible = {
        {'A', {'E'}},
        {'B', {'D', 'E'}},
        {'C', {'E'}},
        {'D', {'B'}},
        {'E', {'A', 'B', 'C'}}};

    int minDifference = INT_MAX;
    std::vector<std::string> bestMatches;
    // 注意有两层遍历噢！！！

    // 遍历每个特种兵的性格密码
    for (const auto &soldier : array)
    {
        bool isCompatible = true;
        int totalDifference = 0;

        // 遍历每个维度的性格类型
        for (int i = 0; i < m; ++i)
        {
            char targetChar = target[i];
            char soldierChar = soldier[i];

            // 检查是否存在不相容的性格类型
            if (incompatible[targetChar].count(soldierChar) > 0)
            {
                isCompatible = false;
                break;
            }

            // 计算性格差异
            int difference = abs(targetChar - soldierChar);
            totalDifference += difference;
        }

        // 如果完全匹配，返回该特种兵的性格密码
        if (isCompatible)
        {
            if (totalDifference < minDifference)
            {
                minDifference = totalDifference;
                bestMatches.clear();
                bestMatches.push_back(soldier);
            }
            else if (totalDifference == minDifference)
            {
                bestMatches.push_back(soldier);
            }
        }
    }

    // 如果没有合适人选，返回 "None"
    if (bestMatches.empty())
    {
        return "None";
    }

    // 返回最佳匹配的特种兵性格密码
    std::string result;
    for (const auto &match : bestMatches)
    {
        result += match + " ";
    }
    result.pop_back(); // 去掉最后一个空格
    return result;
}

int main()
{
    std::vector<std::string> matrix = {"AAAAAA", "BBBBBB", "ABDDEB"};
    std::string result = solution(6, 3, "ABCDEA", matrix);
    std::cout << result << std::endl;

    return 0;
}
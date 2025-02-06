// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855075946540
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
// the use of unordered_map is brilliant
std::string solution(std::vector<int> nums)
{
    // Please write your code here
    std::unordered_map<int, int> countMap;
    for (int num : nums)
    {
        countMap[num]++;
    }

    for (const auto &pair : countMap)
    {
        if (pair.second % 5 != 0)
        {
            return "False";
        }
    }
    return "True";
}

int main()
{
    // You can add more test cases here
    std::cout << (solution({1, 3, 4, 5, 6, 5, 4}) == "False") << std::endl;
    std::cout << (solution({1, 1, 1, 1, 2, 1, 2, 2, 2, 2}) == "True") << std::endl;
    std::cout << (solution({11, 45, 49, 37, 45, 38, 3, 47, 35, 49, 26, 16, 24, 4, 45, 39, 28, 26, 14, 22, 4, 49, 18, 4, 4, 26, 47, 14, 1, 21, 9, 26, 17, 12, 44, 28, 24, 24, 10, 31, 33, 32, 23, 41, 41, 19, 17, 24, 28, 46, 28, 4, 18, 23, 48, 45, 7, 21, 12, 40, 2, 19, 19, 28, 32, 6, 27, 43, 6, 18, 8, 27, 9, 6, 6, 31, 37, 15, 26, 20, 43, 3, 14, 40, 20}) == "False") << std::endl;
    return 0;
}
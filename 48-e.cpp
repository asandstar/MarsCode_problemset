// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424436653370146860
#include <iostream>
#include <string>

std::string solution(const std::string &s)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    std::string result;
    for (char c : s)
    {
        if (c == 'a')
        {
            result += "%100";
        }
        else
        {
            result += c;
        }
    }
    return result; // Placeholder
}
// 将一个字符 a 替换为 "%100" 时，字符串的长度会增加。
// 这意味着需要处理字符串的动态长度变化，而不是简单地替换单个字符。
// 涉及到字符串的插入操作，而不是简单的替换。
int main()
{
    std::cout << (solution("abcdwa") == "%100bcdw%100") << std::endl;
    std::cout << (solution("banana") == "b%100n%100n%100") << std::endl;
    std::cout << (solution("apple") == "%100pple") << std::endl;
    return 0;
}
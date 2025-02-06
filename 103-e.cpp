// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855076896812
#include <iostream>
#include <vector>
#include <string>
// 1-9都是完美整数，十之后就统计数字出现的个数，数字频率里只有一种数字的就是完美的【我的思路】
// 下面这个先遍历完美整数再看是否在区间内的反向思考好牛啊

int solution(int x, int y)
{
    int count = 0;

    // 遍历所有可能的数字（0-9）
    for (int digit = 1; digit <= 9; ++digit)
    {
        // 生成由该数字重复1次到9次构成的整数
        for (int length = 1; length <= 9; ++length)
        {
            // 将数字重复length次构成的字符串
            std::string perfectNumberStr(length, '0' + digit);
            // 将字符串转换为整数
            int perfectNumber = std::stoi(perfectNumberStr);

            // 检查生成的完美整数是否在区间[x, y]内
            if (perfectNumber >= x && perfectNumber <= y)
            {
                ++count;
            }
        }
    }

    return count;
}

int main()
{
    // Add your test cases here

    std::cout << (solution(1, 10) == 9) << std::endl;
    std::cout << (solution(2, 22) == 10) << std::endl;

    return 0;
}
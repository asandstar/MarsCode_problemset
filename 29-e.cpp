// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560666681388
#include <iostream>
#include <string>
using namespace std;
// 核心思路是统计字符串中字符 'k' 和 'u' 的数量（忽略大小写），然后取这两个数量的最小值
// 1 忽略大小写：将字符串中的所有字符转换为小写（或大写），以便统一处理。
// 2 统计字符数量：遍历字符串，统计字符 'k' 和 'u' 的出现次数。
// 3 计算结果：取 'k' 和 'u' 出现次数的最小值，即为最多能组成的 "ku" 的数量。
string solution(string s, int k)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    while (k != 0)
    {
        // 【interesting】
        string new_s = "";
        // 遍历字符串 s 中的每一个字符，并将当前字符赋值给变量 c
        for (char c : s)
        {
            if (c == 'a')
            {
                new_s += "bc";
            }
            else if (c == 'b')
            {
                new_s += "ca";
            }
            else if (c == 'c')
            {
                new_s += "ab";
            }
        }
        s = new_s;
        k--;
    }
    return s;
}

int main()
{
    cout << (solution("abc", 2) == "caababbcbcca") << endl;
    cout << (solution("abca", 3) == "abbcbccabccacaabcaababbcabbcbcca") << endl;
    cout << (solution("cba", 1) == "abcabc") << endl;
    return 0;
}
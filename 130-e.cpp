// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855077978156
#include <iostream>
#include <string>
// 通过从小到大遍历可能的子串长度 len
// 并检查整个字符串是否可以由该长度的子串重复构成
// 从而找到最小的循环子串
std::string solution(const std::string &inp)
{
    for (int len = 1; len <= inp.size() / 2; ++len)
    {
        if (inp.size() % len == 0)
        {
            std::string candidate = inp.substr(0, len);
            bool is_valid = true;
            for (int i = 0; i < inp.size(); i += len)
            {
                if (inp.substr(i, len) != candidate)
                {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid)
            {
                return candidate;
            }
        }
    }
    return "";
}

int main()
{
    // Add your test cases here

    std::cout << (solution("abcabcabcabc") == "abc") << std::endl;
    return 0;
}

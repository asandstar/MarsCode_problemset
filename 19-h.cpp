// https : // www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560665370668
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int n, int k, string s)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    for (int i = 0; i < n && k > 0; ++i)
    {
        // 找到当前最小的字符及其位置
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (s[j] < s[min_index])
            {
                min_index = j;
            }
        }

        // 计算将最小字符移动到当前位置所需的交换次数
        int swaps = min_index - i;

        // 如果交换次数不超过 k，则进行交换
        if (swaps <= k)
        {
            // 将最小字符移动到当前位置
            while (min_index > i)
            {
                swap(s[min_index], s[min_index - 1]);
                min_index--;
            }
            // 更新剩余的交换次数
            k -= swaps;
        }
    }

    return s;
}
// 遍历字符串：从字符串的第一个字符开始，逐步遍历到字符串的末尾。
// 寻找最小字符：在当前字符之后的部分中，找到字典序最小的字符及其位置。
// 交换字符：如果将这个最小字符移动到当前位置所需的交换次数不超过剩余的交换次数 k，则进行交换，并更新剩余的交换次数 k。
// 返回结果：最终返回经过最多 k 次交换后的字符串。
int main()
{
    cout << (solution(5, 2, "01010") == "00101") << endl;
    cout << (solution(7, 3, "1101001") == "0110101") << endl;
    cout << (solution(4, 1, "1001") == "0101") << endl;
    return 0;
}
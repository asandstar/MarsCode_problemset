// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7435955743768739884
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> solution(std::vector<int> a, int d0)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    std::vector<int> data;
    data.push_back(d0); // 初始化第一个元素

    for (int i = 0; i < a.size(); ++i)
    {
        // 根据异或的性质，data[i+1] = data[i] XOR a[i]
        int next_value = data[i] ^ a[i];
        data.push_back(next_value);
    }

    return data;
}

int main()
{
    cout << (solution({2, 5, 1}, 3) == std::vector<int>{3, 1, 4, 5}) << endl;
    cout << (solution({7, 4, 3}, 6) == std::vector<int>{6, 1, 5, 6}) << endl;
    cout << (solution({8, 1}, 9) == std::vector<int>{9, 1, 0}) << endl;
    cout << (solution({9, 2, 3}, 4) == std::vector<int>{4, 13, 15, 12}) << endl;
    cout << (solution({3, 6, 5}, 7) == std::vector<int>{7, 4, 2, 7}) << endl;
    return 0;
}
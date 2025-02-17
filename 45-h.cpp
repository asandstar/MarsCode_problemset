// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560931201068
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 检测数组里的数字有多少位，然后有多少非0的，非0的就是需要删除的个数
int solution(int n, vector<int> &a)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int totalSteps = 0;
    for (int num : a)
    {
        string numStr = to_string(num);
        // 统计非0位的数量
        for (char digit : numStr)
        {
            if (digit != '0')
            {
                totalSteps++;
            }
        }
    }
    return totalSteps;
}
// 这题目能算hard真有点幽默了

int main()
{
    vector<int> a1 = {10, 13, 22, 100, 30};
    cout << (solution(5, a1) == 7) << endl;

    vector<int> a2 = {5, 50, 505};
    cout << (solution(3, a2) == 4) << endl;

    vector<int> a3 = {1000, 1, 10, 100};
    cout << (solution(4, a3) == 4) << endl;
}
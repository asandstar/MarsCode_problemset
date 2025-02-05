// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560666845228
// 咳咳，一学期射箭课不是白上的呢（不过这好像和射箭课没什么关系吧
#include <iostream>
using namespace std;

int solution(int x, int y)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int result;
    for (int i = 1; i <= 10; i++)
    {
        if (x * x + y * y <= i * i)
        {
            result = 11 - i;
            break;
        }
        else
        {
            result = 0;
        }
    }

    return result;
}

int main()
{
    cout << (solution(1, 0) == 10) << endl;
    cout << (solution(1, 1) == 9) << endl;
    cout << (solution(0, 5) == 6) << endl;
    cout << (solution(3, 4) == 6) << endl;
    return 0;
}
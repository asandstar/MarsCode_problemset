// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424436653372506156
#include <iostream>
using namespace std;

int solution(int a, int b)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int day = 0;
    int sum = 0;
    while (sum < a)
    {
        sum += b;
        day++;
    }
    return day;
}

int main()
{
    cout << (solution(10, 1) == 10) << endl;
    cout << (solution(10, 2) == 5) << endl;
    cout << (solution(10, 3) == 4) << endl;
    return 0;
}
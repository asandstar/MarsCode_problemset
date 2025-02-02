// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7427688461827653676
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// match first, then change n
int solution(int n)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int match = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            match += n / 2;
            n /= 2;
        }
        else
        {
            match += (n - 1) / 2;
            n = (n - 1) / 2 + 1;
        }
    }
    return match;
}

int main()
{
    cout << (solution(7) == 6) << endl;
    cout << (solution(14) == 13) << endl;
    cout << (solution(1) == 0) << endl;

    return 0;
}
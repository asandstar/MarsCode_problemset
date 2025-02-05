// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560665534508
// 别多想
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n, int l, int r, vector<int> &a)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= l && a[i] <= r && a[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> a1 = {1, 2, 6, 8, 7};
    cout << (solution(5, 3, 8, a1) == 2) << endl;

    vector<int> a2 = {12, 15, 18, 9};
    cout << (solution(4, 10, 20, a2) == 2) << endl;

    vector<int> a3 = {2, 4, 6};
    cout << (solution(3, 1, 10, a3) == 3) << endl;
}
// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560668090412
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> &a, vector<int> &b)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int i = a.size() - 1;
    int j = b.size() - 1;
    vector<int> result;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == b[j])
        {
            result.push_back(a[i]);
            i--;
            j--;
        }
        else if (a[i] < b[j])
        {
            j--;
        }
        else if (a[i] > b[j])
        {
            i--;
        }
    }
    return result;
}
/*
数组索引从0开始：在C++中，数组的索引是从0开始的。因此，数组的最后一个元素的索引是 size - 1，而不是 size。
循环条件：
i >= 0 和 j >= 0 确保我们在遍历数组时，索引 i 和 j 不会变成负数。
i != 0 和 j != 0 只会在 i 和 j 等于0时停止循环，但这并不意味着我们已经遍历完了整个数组。
使用 i >= 0 && j >= 0 是正确的，而 i != 0 && j != 0 可能会导致循环过早停止。
*/

int main()
{
    vector<int> a1 = {1, 2, 3, 7};
    vector<int> b1 = {2, 5, 7};
    vector<int> res1 = solution(a1, b1);
    cout << (res1 == vector<int>{7, 2}) << endl;

    vector<int> a2 = {1, 4, 8, 10};
    vector<int> b2 = {2, 4, 8, 10};
    vector<int> res2 = solution(a2, b2);
    cout << (res2 == vector<int>{10, 8, 4}) << endl;

    vector<int> a3 = {3, 5, 9};
    vector<int> b3 = {1, 4, 6};
    vector<int> res3 = solution(a3, b3);
    cout << (res3 == vector<int>{}) << endl;

    vector<int> a4 = {1, 2, 3};
    vector<int> b4 = {1, 2, 3};
    vector<int> res4 = solution(a4, b4);
    cout << (res4 == vector<int>{3, 2, 1}) << endl;

    return 0;
}
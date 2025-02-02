// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855077847084
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array)
{
    // Edit your code here
    int len = array.size();
    unordered_map<int, int> countMap;
    for (int num : array)
    {
        countMap[num]++;
    }
    for (auto &pair : countMap)
    {
        if (pair.second > len / 2)
        {
            return pair.first;
        }
    }

    return 0;
}

int main()
{
    // Add your test cases here

    cout << (solution({1, 3, 8, 2, 3, 1, 3, 3, 3}) == 3) << endl;

    return 0;
}

// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855075618860
#include <iostream>
#include <vector>
#include <set>

int solution(std::vector<std::vector<int>> inputArray)
{
    // Please write your code here
    // the use of set is brilliant
    std::set<int> points;
    for (const auto &range : inputArray)
    {
        int start = range[0];
        int end = range[1];
        for (int i = start; i <= end; ++i)
        {
            points.insert(i);
        }
    }
    return points.size();
}

int main()
{
    //  You can add more test cases here
    std::vector<std::vector<int>> testArray1 = {{1, 4}, {7, 10}, {3, 5}};
    std::vector<std::vector<int>> testArray2 = {{1, 2}, {6, 10}, {11, 15}};

    std::cout << (solution(testArray1) == 9) << std::endl;
    std::cout << (solution(testArray2) == 12) << std::endl;

    return 0;
}
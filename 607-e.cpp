// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7435957508987273260
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> instructions)
{
    int concentration = 0;
    // 不要再for(int i = 0; i < instructions.size(); i++)了，直接for(auto instruction : instructions)
    for (const auto &instruction : instructions)
    {
        if (instruction == "++")
        {
            concentration++;
        }
        else if (instruction == "--")
        {
            concentration--;
        }
    }
    return concentration;
}

int main()
{
    cout << (solution({"++", "--", "++"}) == 1) << endl;
    cout << (solution({"++", "++", "--", "--"}) == 0) << endl;
    cout << (solution({"++", "++", "--"}) == 1) << endl;
    return 0;
}
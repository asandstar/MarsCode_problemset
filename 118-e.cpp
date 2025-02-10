// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855077421100
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int solution(std::string version1, std::string version2)
{
    // 分割版本号
    auto splitVersion = [](const std::string &version) -> std::vector<int>
    {
        std::vector<int> revisions;
        std::stringstream ss(version);
        std::string revision;
        while (std::getline(ss, revision, '.'))
        {
            revisions.push_back(std::stoi(revision));
        }
        return revisions;
    };

    std::vector<int> revisions1 = splitVersion(version1);
    std::vector<int> revisions2 = splitVersion(version2);

    // 补齐修订号
    while (revisions1.size() < revisions2.size())
        revisions1.push_back(0);
    while (revisions2.size() < revisions1.size())
        revisions2.push_back(0);

    // 逐个比较修订号
    for (size_t i = 0; i < revisions1.size(); ++i)
    {
        if (revisions1[i] > revisions2[i])
            return 1;
        if (revisions1[i] < revisions2[i])
            return -1;
    }

    return 0;
}

int main()
{
    // Add your test cases here
    std::cout << (solution("0.1", "1.1") == -1) << std::endl;
    std::cout << (solution("1.0.1", "1") == 1) << std::endl;
    std::cout << (solution("7.5.2.4", "7.5.3") == -1) << std::endl;
    std::cout << (solution("1.0", "1.0.0") == 0) << std::endl;

    return 0;
}
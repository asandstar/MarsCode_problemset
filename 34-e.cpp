// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560931495980
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int n, std::vector<int> nums)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    // sort and set data structures are important
    std::sort(nums.begin(), nums.end());
    std::set<int> unique_nums(nums.begin(), nums.end());
    std::vector<int> unique_vector(unique_nums.begin(), unique_nums.end());
    if (unique_vector.size() >= 3)
    {
        return unique_vector[unique_vector.size() - 3];
    }
    else
    {
        return unique_vector.back();
    }
}

int main()
{
    std::cout << (solution(3, {3, 2, 1}) == 1) << std::endl;
    std::cout << (solution(2, {1, 2}) == 2) << std::endl;
    std::cout << (solution(4, {2, 2, 3, 1}) == 1) << std::endl;
    return 0;
}
//https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855076765740
#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> A) {
    int N = A.size();
    std::vector<int> count(101, 0); // 初始化计数数组，大小为101（因为分数范围是0到100）

    // 统计每个分数出现的次数
    for (int score : A) {
        count[score]++;
    }

    int liarCount = 0;

    // 计算每个学生是否说谎
    for (int i = 0; i < N; i++) {
        int score = A[i];
        int lessOrEqualCount = 0;

        // 计算分数 <= score 的学生数量
        for (int j = 0; j <= score; j++) {
            lessOrEqualCount += count[j];
        }

        // 计算分数 > score 的学生数量
        int greaterCount = N - lessOrEqualCount;

        // 判断是否说谎
        if (lessOrEqualCount > greaterCount) {
            liarCount++;
        }
    }

    return liarCount;
}

int main() {
    // Add your test cases here
    std::cout << (solution({100, 100, 100}) == 3) << std::endl;
    std::cout << (solution({2, 1, 3}) == 2) << std::endl;
    std::cout << (solution({30, 1, 30, 30}) == 3) << std::endl;
    std::cout << (solution({19, 27, 73, 55, 88}) == 3) << std::endl;
    std::cout << (solution({19, 27, 73, 55, 88, 88, 2, 17, 22}) == 5) << std::endl;
    return 0;
}
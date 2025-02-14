// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855075258412
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int solution(std::string rgb)
{
    // 去掉 "rgb(" 和 ")"
    rgb = rgb.substr(4, rgb.size() - 5);

    // 使用 stringstream 分割字符串
    std::stringstream ss(rgb);
    std::string segment;
    int r, g, b;

    // 获取 R, G, B 的值
    std::getline(ss, segment, ',');
    r = std::stoi(segment);
    std::getline(ss, segment, ',');
    g = std::stoi(segment);
    std::getline(ss, segment, ',');
    b = std::stoi(segment);

    // 将 R, G, B 转换为十六进制并组合成一个整数
    int hexValue = (r << 16) | (g << 8) | b;

    return hexValue;
}

int main()
{
    // 测试用例
    std::cout << (solution("rgb(192, 192, 192)") == 12632256) << std::endl;
    std::cout << (solution("rgb(100, 0, 252)") == 6553852) << std::endl;
    std::cout << (solution("rgb(33, 44, 55)") == 2174007) << std::endl;
    return 0;
}
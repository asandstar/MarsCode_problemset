// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855074832428
#include <iostream>
#include <string>
#include <algorithm>

std::string solution(std::string dna_sequence)
{
    // Please write your code here
    std::string min_sequence = dna_sequence;
    for (int i = 0; i < dna_sequence.length(); ++i)
    {
        std::string current_sequence = dna_sequence.substr(i) + dna_sequence.substr(0, i);
        if (current_sequence < min_sequence)
        {
            // 字典序就是正常的字符串比大小
            min_sequence = current_sequence;
        }
    }
    return min_sequence;
}

int main()
{
    // You can add more test cases here
    std::cout << (solution("ATCA") == "AATC") << std::endl;
    std::cout << (solution("CGAGTC") == "AGTCCG") << std::endl;
    std::cout << (solution("TCATGGAGTGCTCCTGGAGGCTGAGTCCATCTCCAGTAG") == "AGGCTGAGTCCATCTCCAGTAGTCATGGAGTGCTCCTGG") << std::endl;
    return 0;
}
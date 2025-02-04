// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560932020268
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(const string &s)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int count_k = 0;
    int count_u = 0;
    for (char c : s)
    {
        char lower_c = tolower(c);
        if (lower_c == 'k')
        {
            count_k++;
        }
        else if (lower_c == 'u')
        {
            count_u++;
        }
    }
    return min(count_k, count_u);
}

int main()
{
    cout << (solution("AUBTMKAxfuu") == 1) << endl;
    cout << (solution("KKuuUuUuKKKKkkkkKK") == 6) << endl;
    cout << (solution("abcdefgh") == 0) << endl;
}
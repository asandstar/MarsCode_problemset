// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7424418560929628204
#include <iostream>
#include <string>
using namespace std;
// change "int" to "string" is very useful
int solution(int a, int b)
{
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    //[important]convert to string
    // easy manipulation
    string a_str = to_string(a);
    string b_str = to_string(b);
    string max_result = a_str;
    for (int i = 0; i <= a_str.length(); ++i)
    {
        string new_result = a_str.substr(0, i) + b_str + a_str.substr(i);
        if (new_result > max_result)
        {
            max_result = new_result;
        }
    }
    return stoi(max_result);
}

int main()
{
    cout << (solution(76543, 4) == 765443) << endl;
    cout << (solution(1, 0) == 10) << endl;
    cout << (solution(44, 5) == 544) << endl;
    cout << (solution(666, 6) == 6666) << endl;
    return 0;
}
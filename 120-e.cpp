// https://www.marscode.cn/practice/enno1xy36v12wk?problem_id=7414004855077486636
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string inp)
{
    // Step 1: Separate characters and keep track of their positions
    vector<char> numbers;
    vector<char> letters;
    string specialChars;
    vector<int> specialPositions;

    for (int i = 0; i < inp.size(); ++i)
    {
        if (inp[i] == '?')
        {
            specialChars += inp[i];
            specialPositions.push_back(i);
        }
        else if (isdigit(inp[i]))
        {
            numbers.push_back(inp[i]);
        }
        else if (isalpha(inp[i]))
        {
            letters.push_back(inp[i]);
        }
    }

    // Step 2: Sort the separated characters
    sort(numbers.begin(), numbers.end(), greater<char>());
    sort(letters.begin(), letters.end());

    // Step 3: Reconstruct the string
    string result = inp;
    int numIndex = 0, letterIndex = 0;

    for (int i = 0; i < inp.size(); ++i)
    {
        if (inp[i] == '?')
            continue; // Skip special characters
        if (isdigit(inp[i]))
        {
            result[i] = numbers[numIndex++];
        }
        else if (isalpha(inp[i]))
        {
            result[i] = letters[letterIndex++];
        }
    }

    // Insert special characters back into their original positions
    for (int i = 0; i < specialPositions.size(); ++i)
    {
        result[specialPositions[i]] = specialChars[i];
    }

    return result;
}

int main()
{
    // Add your test cases here
    cout << (solution("12A?zc") == "21A?cz") << endl;
    cout << (solution("1Ad?z?t24") == "4Ad?t?z21") << endl;
    cout << (solution("???123??zxy?") == "???321??xyz?") << endl;

    return 0;
}
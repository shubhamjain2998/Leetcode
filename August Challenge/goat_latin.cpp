#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkVowel(char a)
    {
        char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < 10; i++)
        {
            if (a == vowels[i])
                return true;
        }
        return false;
    }

    string appendA(string a, int index)
    {
        for (int i = 0; i < index; i++)
            a.append("a");
        return a;
    }

    vector<string> split(string a)
    {
        vector<string> result;
        int index = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == ' ')
            {
                result.push_back(a.substr(index, i - index));
                index = i + 1;
                continue;
            }
            if (i == a.size() - 1)
            {
                result.push_back(a.substr(index, i - index + 1));
            }
        }
        return result;
    }

    string toGoatLatin(string S)
    {
        vector<string> inputArray;
        string output;
        inputArray = split(S);
        string toAppend = "ma";
        for (int i = 0; i < inputArray.size(); i++)
        {
            if (checkVowel(inputArray[i][0]))
            {
                inputArray[i].append(toAppend);
            }
            else
            {
                char temp = inputArray[i][0];
                inputArray[i].erase(inputArray[i].begin());
                inputArray[i].push_back(temp);
                inputArray[i].append(toAppend);
            }
            inputArray[i] = appendA(inputArray[i], i + 1);
            output += " " + inputArray[i];
        }
        output.erase(output.begin());
        return output;
    }
};

int main()
{
    string inputString;
    string outputString;
    getline(cin, inputString);
    Solution *sol = new Solution();
    outputString = sol->toGoatLatin(inputString);
    cout << outputString << endl;
    delete sol;
    return 0;
}
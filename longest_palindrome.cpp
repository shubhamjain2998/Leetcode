#include <bits/stdc++.h>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<char> processed;
    vector<int> countedAlphabets;

    int countString(string inputString)
    {
        string temp = inputString;
        int frequency;
        int tempLength = temp.length();
        int total = 0;
        bool odd = false;
        bool flag;
        for (int i = 0; i < tempLength; i++)
        {
            flag = false;
            char currentAlphabet = temp[i];
            for (int k = 0; k < processed.size(); k++)
            {
                if (currentAlphabet == processed[k])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            frequency = 0;
            for (int j = i; j < tempLength; j++)
            {

                if (currentAlphabet == temp[j])
                    frequency += 1;
            }
            processed.push_back(currentAlphabet);
            countedAlphabets.push_back(frequency);
        }
        for (int i = 0; i < countedAlphabets.size(); i++)
        {
            int frequencyOfSingleAlphabet = countedAlphabets[i];

            if (frequencyOfSingleAlphabet % 2 != 0)
            {
                odd = true;
                total += 2 * (frequencyOfSingleAlphabet / 2);
            }
            else
                total += countedAlphabets[i];
        }
        if (odd)
            return total + 1;
        else
            return total;
    }
};

int main()
{
    string inputString;
    int longestPalindrome;
    cin >> inputString;
    cin.ignore();
    Solution *sol = new Solution();
    longestPalindrome = sol->countString(inputString);
    cout << longestPalindrome << endl;
    delete sol;
    return 0;
}
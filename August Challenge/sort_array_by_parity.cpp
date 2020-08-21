#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(int &a, int &b)
    {
        return a % 2 < b % 2;
    }
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int A_Size = A.size();
        if (A_Size == 1)
            return A;
        sort(A.begin(), A.end(), cmp);
        return A;
    }
};

int main()
{
    int numberOfInputs, input;
    vector<int> inputs;
    vector<int> outputs;
    cin >> numberOfInputs;
    for (int i = 0; i < numberOfInputs; i++)
    {
        cin >> input;
        inputs.push_back(input);
    }
    Solution *sol = new Solution();
    outputs = sol->sortArrayByParity(inputs);
    for (int i = 0; i < outputs.size(); i++)
        cout << outputs[i] << " ";
    cout << endl;
    return 0;
}
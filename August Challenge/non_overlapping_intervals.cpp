#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &arr)
    {
        int n = arr.size();
        if (!n)
            return 0;
        int cnt = 1;
        sort(arr.begin(), arr.end(), cmp);
        int end = arr[0][1];
        for (int i = 1; i < n; i++)
        {
            if (arr[i][0] >= end)
            {
                end = arr[i][1];
                cnt++;
            }
        }
        return n - cnt;
    }
};

int main()
{
    int numberOfIntervals;
    int begin;
    int end;
    int answer;
    vector<vector<int>> totalIntervals;
    cin >> numberOfIntervals;
    for (int i = 0; i < numberOfIntervals; i++)
    {
        vector<int> interval;
        cin >> begin >> end;
        interval.push_back(begin);
        interval.push_back(end);
        totalIntervals.push_back(interval);
    }
    Solution *sol = new Solution();
    answer = sol->eraseOverlapIntervals(totalIntervals);
    cout << answer << endl;
    return 0;
}
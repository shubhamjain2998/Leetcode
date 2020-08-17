#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> distribution(num_people, 0);
        int remainingCandies = candies;
        int current_person = 0;
        int factor = 0;
        int person_due;
        while (remainingCandies > 0)
        {
            person_due = distribution[current_person] + (factor * num_people) + current_person + 1;
            cout << person_due << " " << remainingCandies << endl;
            if (remainingCandies >= person_due - distribution[current_person])
            {
                remainingCandies -= (person_due - distribution[current_person]);
                distribution[current_person] = person_due;
            }
            else
            {
                distribution[current_person] += remainingCandies;
                remainingCandies = 0;
            }
            if (current_person < num_people - 1)
                current_person += 1;
            else
            {
                current_person = 0;
                factor += 1;
            }
        }
        return distribution;
    }
};

int main()
{
    int candies;
    int people;
    vector<int> answer;
    cin >> candies >> people;
    Solution *sol = new Solution();
    answer = sol->distributeCandies(candies, people);
    int answerSize = answer.size();
    cout << "[";
    for (int i = 0; i < answerSize - 1; i++)
    {
        cout << answer[i] << ",";
    }
    cout << answer[answerSize - 1] << "]" << endl;
    delete sol;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int temp = -1;

    while((temp = heights.back()) != 0)
    {
        int idx = heights.size()-1;
        int count = 0;

        for(int i = idx; heights.size() >= 0; --i)
        {
            int nextTower = heights[i];
            if(temp < nextTower)
            {
                if(i+1 == -1)
                {
                    answer.push_back(0);
                }
                else
                {
                    answer.push_back(i+1);
                }
                heights.erase(heights.end()-1);
                break;
            }
        }

    }

    reverse(answer.begin(),answer.end());

    return answer;
}

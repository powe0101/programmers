#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int temp = -1;

    while((temp = heights.back()) != 0) // heights의 제일 뒤를 꺼내옴.
    {
        int idx = heights.size()-1; // 사이즈 저장 temp

        for(int i = idx; heights.size() >= 0; --i) // 뒤에서부터 0까지 읽음.
        {
            int nextTower = heights[i]; // 다음 신호를 받는 타워의 높이
            if(temp < nextTower) // 순회하면서 다음 타워의 높이가 현재 타워보다 높으면
            {
                if(i+1 == -1) // 하지만 현재 타워 idx가 마지막이면
                {
                    answer.push_back(0);
                }
                else
                {
                    answer.push_back(i+1);
                }
                heights.erase(heights.end()-1); // 꺼내온 제일 뒤 타워 삭제.
                break;
            }
        }

    }

    reverse(answer.begin(),answer.end()); // 맨 왼쪽부터 출력해야 하므로 reverse

    return answer;
}

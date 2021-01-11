//https://programmers.co.kr/learn/courses/30/lessons/42885
include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) 
{
    sort(people.begin(), people.end());

    int answer = 0;
    int index = people.size()-1;
    for(int i = 0; i <= index; ++answer, ++i)
    {
        while(index > i && people[i] + people[index--] > limit)
            answer++;
    }

    return answer;
}

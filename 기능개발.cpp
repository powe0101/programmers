//https://programmers.co.kr/learn/courses/30/lessons/42586
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    int maximum = 0, count = 0; 
    
    while(progresses.empty() == false)
    {
        int progress = progresses.front(); progresses.erase(progresses.begin());
        int speed = speeds.front(); speeds.erase(speeds.begin());
        
        int day = (((100 - progress) / speed));
        
        if((100-progress) % speed != 0)
            day += 1;
        
        if(maximum >= day) // 기존 진행 중인 작업보다 더 적게 걸리면
            count += 1;
        else
        {
            maximum = day; // 더 오래걸리면 최대값 변경
            if(count > 0)
                answer.push_back(count); 
            count = 1; //초기화
        }
    }
    
    answer.push_back(count);
    return answer;
}

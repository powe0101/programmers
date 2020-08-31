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
        
        if(maximum >= day)
            count += 1;
        else
        {
            maximum = day;
            answer.push_back(count);
            count = 1;
        }
    }
    
    answer.erase(answer.begin());
    answer.push_back(count);
    return answer;
}

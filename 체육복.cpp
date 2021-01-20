//https://programmers.co.kr/learn/courses/30/lessons/42862
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> list(n,1);
    
    for(int i = 0; i < lost.size(); ++i)
        list[lost[i] - 1] -= 1;
    
    for(int i = 0; i < reserve.size(); ++i)
        list[reserve[i] - 1] += 1;
    
    for(int i = 0; i < list.size(); ++i)
    {
        if(list[i] == 0) // 체육복이 없는 경우
        {
            if( i != 0 && list[i-1] > 1) // 
            {
                list[i-1] -= 1;
                list[i] += 1;
            }
            else if( i != list.size()-1 && list[i+1] == 2)
            {
                list[i+1] -= 1;
                list[i] += 1;
            }
        }
    }
    
    for(int i = 0;i < list.size(); ++i)
    {
        if(list[i] != 0)
            answer += 1;
    }
    
    
    return answer;
}

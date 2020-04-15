//https://programmers.co.kr/learn/courses/30/lessons/42578

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> list;
    int itemCount = 0;
    for(int i = 0; i < clothes.size(); ++i)
    {
        for(int j = 0; j < 1; ++j)
        {
            list[clothes[i][1]] += 1;
            itemCount += 1;
        }
    }
    
    if(list.size() <= 1)
        return itemCount;
  
    map<string,int>::iterator seek = list.begin();
    map<string,int>::iterator end = list.end();
    
    for(; seek != end; ++seek)
    {
        answer *= seek->second + 1;
        cout << seek->second << " " << answer << endl;
    }
    
    return answer - 1;
}

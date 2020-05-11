#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>, greater<int>> list(scoville.begin(),scoville.end());
    
    for(;list.top() < K && list.size() > 1;)
    {
        int temp1 = list.top(); list.pop();
        int temp2 = list.top(); list.pop();
        list.push(temp1 + temp2 * 2);
        
        answer += 1;
    }
    
    if(list.size() == 1 && list.top() < K)
        return -1;
    
    return answer;
}

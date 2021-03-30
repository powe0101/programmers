#include <bits/stdc++.h>
using namespace std;

void dfs(int n, const vector<vector<int>> & computers, int index, vector<bool>& visit)
{
    visit[index] = true;
    
    for(int i = 0; i < n; ++i)
    {
        const bool isConnected = computers[index][i] == 1;
        
        if(isConnected && i != index && visit[i] == false)
            dfs(n, computers, i, visit);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visit(n);
    for(int i = 0; i < n; ++i)
    {
        if(visit[i] == true)
            continue;
        dfs(n, computers, i, visit);
        answer += 1;
    }
    
    return answer;
}

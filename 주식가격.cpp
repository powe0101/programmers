//https://programmers.co.kr/learn/courses/30/lessons/42584

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); ++i)
    {
        const int price = prices[i];
        int j = i + 1;
        for(; j < prices.size(); ++j) 
        {
            int temp = prices[j];
            if(temp < price)
                break;
        }
        if(j == prices.size())
            answer.push_back(prices.size()-i-1);
        else
            answer.push_back(j-i);
    }
    
    return answer;
}

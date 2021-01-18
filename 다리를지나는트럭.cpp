//https://programmers.co.kr/learn/courses/30/lessons/42583
#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int currentWeight = 0;
    queue<int> list, on;
    
    while((truck_weights.empty() && list.empty()) == false)
    {
        const int size = on.size();
        int truck = truck_weights.front();
        
        for(int i = 0; i < size; ++i)
        {
            int weight = on.front(); on.pop();
            if(weight <= 1)
            {
                currentWeight -= list.front(); list.pop();
                continue;
            }
            on.push(weight - 1);
        }

        if(truck_weights.size() > 0 && currentWeight + truck <= weight)
        {
            truck_weights.erase(truck_weights.begin());
            list.push(truck);
            currentWeight += truck;
            on.push(bridge_length);
        }
        
        time += 1;

    }
    return time;
}

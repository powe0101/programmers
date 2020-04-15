//https://programmers.co.kr/learn/courses/30/lessons/42576
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(),participant.end());
    sort(completion.begin(), completion.end());
    
      vector<string> difference;
    set_difference(
    participant.begin(), participant.end(),
    completion.begin(), completion.end(),
    std::back_inserter( difference )
);
    
    return difference[0];
}

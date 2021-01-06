// H-index
// https://programmers.co.kr/learn/courses/30/lessons/42747
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int index = 0;
    sort(citations.begin(), citations.end(), greater<int>()) ;
    while(index < citations.size()){
        if(citations[index] <= index) break;
        index++;
    }
    return index;
}

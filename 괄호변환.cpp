//https://programmers.co.kr/learn/courses/30/lessons/60058
#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";

    bool isFlag = false;

    if(isalpha(s[0]))
        s[0] = toupper(s[0]);

    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] == ' '){
            isFlag = true;

        }
        else if(isFlag == true)
        {
            isFlag = false;
            if(isalpha(s[i]))
                s[i] = toupper(s[i]);
        }
        else
        {
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
        }
    }
    answer = s;
    return answer;
}

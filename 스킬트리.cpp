//https://programmers.co.kr/learn/courses/30/lessons/49993
#include <bits/stdc++.h>
using namespace std;

char pop_front(string & str)
{
    char result = str.front();
    str.erase(str.begin());
    return result;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    
    for(int i = 0; i < skill_trees.size(); ++i)
    {
        string str = skill_trees[i];
        string temp = "";
        
        //skill에 있는 문자열 찾기 
        while(str.empty() == false)
        {
            const char ch = pop_front(str);
            const int pos = skill.find(ch);
            if(pos != string::npos)
                temp += ch;
        }
        
        if(temp.size() == 0) //일치하는 문자열이 없는 경우
            continue;
        
        int pos = skill.find(temp[0]);
        auto result = skill.substr(pos, temp.size());
        
        //첫번째 문자를 찾아서 현재 유효한 스킬의 size 만큼 substr
        //시작 스킬이 없거나, 스킬트리가 일치하지 않으면 불가능.
        if((result != temp) || (result.front() != skill.front()))
        {
            answer -= 1;
            continue;
        }
    }
    
    return answer;
}

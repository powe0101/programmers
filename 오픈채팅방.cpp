//https://programmers.co.kr/learn/courses/30/lessons/42888

#include <bits/stdc++.h>
using namespace std;
//https://m.blog.naver.com/PostView.nhn?blogId=elkiss&logNo=221439493940
std::vector<std::string> split(std::string str, char delimiter)
{
    uint64_t start_pos = 0;
    uint64_t search_pos = 0;
    std::vector<std::string> result;

    while (start_pos < str.size())
    {
        search_pos = str.find_first_of(delimiter, start_pos);
        std::string tmp_str;

        if (search_pos == std::string::npos)
        {
            // for last token
            search_pos = str.size();
            tmp_str = str.substr(start_pos, search_pos - start_pos);
            result.push_back(tmp_str);
            break;
        }
        tmp_str = str.substr(start_pos, search_pos - start_pos);
        result.push_back(tmp_str);
        start_pos = search_pos + 1;
    }

    return result;
}

int GetStatus(string str)
{
    if(str == "Enter")
        return 1;
    if(str == "Leave")
        return 2;
    if(str == "Change")
        return 3;
    return 0;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map <string, string> users;
    for(int i = 0; i < record.size(); ++i)
    {
        string temp = record[i];
        vector<string> spliter = split(temp, ' ');
        {
            string status = spliter[0];
            string uid = spliter[1];
            switch(GetStatus(status))
            {
                case 1:
                case 3:
                    string name = spliter[2];
                    users[uid] = name;
                    break;
            }
        }
    }
    
    for(int i = 0; i < record.size(); ++i)
    {
        string temp = record[i];
        auto spliter = split(temp, ' ');
        {
            auto status = spliter[0];
            auto uid = spliter[1];
            string result = "";
            switch(GetStatus(status))
            {
                case 1:
                    result = users[uid];
                    result += "님이 들어왔습니다.";
                    break;
                case 2:
                    result = users[uid];
                    result += "님이 나갔습니다.";
                    break;
                default:
                    continue;
            }
            answer.push_back(result);
        }
    }
    
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/42579
#include <bits/stdc++.h>
#include <functional>
using namespace std;

typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;

Comparator compFunctor =
    [](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
    {
        return elem1.second > elem2.second;
    };

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    multimap<int, pair<string,int>, greater<int>> m; //오름차순, genre 와 playtime 페어화. 중복 허용 위해 multimap
    map<string, int> u; // 장르별 총 플레이타임 정렬용.
    for (int i = 0; i < genres.size(); ++i)
    {
        m.insert(pair<int,pair<string,int>>(plays[i],pair<string,int>(genres[i],i)));

        u[genres[i]] += plays[i];
    }

    set<pair<string, int>, Comparator> setOfWords(u.begin(), u.end(), compFunctor);

    for (auto element : setOfWords)
    {
        multimap<int,pair<string,int>>::iterator seek = m.begin();
        multimap<int,pair<string,int>>::iterator end = m.end();
        //재생회수, 장르, 고유번호
        for (int count = 0 ; (seek != end) ; ++seek)
        {
            int playCount = seek->first;
            auto genre = seek->second.first;
            int id = INT_MAX;
            if(genre == element.first) // 장르 비교 
            {
                for(auto iter = m.begin(); iter != m.end(); ++iter)
                {
                    if(playCount == iter->first &&
                       id > iter->second.second)
                    {
                        if(find(answer.begin(),answer.end(), iter->second.second) != answer.end())
                            continue;
                        id = iter->second.second; //제일 작은 고유번호 가져오기.
                    }
                }
                answer.push_back(id);
                if(++count > 1) //큰거 2
                    break;
            }
        }
    }

    return answer;
}

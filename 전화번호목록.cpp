//https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0; i < phone_book.size(); ++i)
    {
        string target = phone_book[i];
        
        vector<string>::iterator seek = phone_book.begin();
        vector<string>::iterator end = phone_book.end();

        for(; seek != end; ++seek)
        {
            string temp = (*seek);
            
            if(temp == target)
                continue;
            
            if( (temp.find(target)) == 0)
            {
                return false;
            }
        }
    }
           
    return true;
}

#include <string>
#include <vector>
#include <list>
using namespace std;

list<char> lis;
string solution(string number, int k) {
    string answer = "";
    for(int i =0; i < number.size(); i++)
    {
        lis.push_back(number[i]);
    }
    int cnt = 0;
    list<char> :: iterator front = lis.begin();
    list<char> :: iterator back = ++lis.begin();
    while(cnt < k)
    {
        if(back == lis.end())
        {
            lis.erase(front);
            front = --lis.end();
            cnt++;
        } else 
        {
            if(*front < *back)
            {
                if(front == lis.begin())
                {
                    lis.pop_front();
                    front = lis.begin();
                    back = ++lis.begin();
                } else 
                {
                    front = lis.erase(front);
                    front--;
                }
                cnt++;
            } else 
            {
                front++;
                back++;
            }
        }
    }
    list<char> :: iterator it;
    for(it = lis.begin(); it != lis.end(); it++)
    {
        answer += *it;
    }
    return answer;
}
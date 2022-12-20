#include <string>
using namespace std;

class Solution {
public:
    string fun(int n) {
        if(n % 15 == 0) return {"FizzBuzz"};
        else if (n % 3 == 0) return {"Fizz"};
        else if(n % 5 == 0) return {"Buzz"};
        return {to_string(n)};
    }
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 1; i <= n; i++)
        {
            answer.push_back(fun(i));
        }
        return answer;
    }
};
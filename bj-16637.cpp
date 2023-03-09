#include <iostream>
#include <vector>
using namespace std;

char arr[30];
int ans = -2147483648;

int calculate(int a, int b, char oper)
{
    if(oper == '+') return a + b;
    if(oper == '-') return a - b;
    return a * b;
}

void ho(int idx, vector<bool> & isPrior, vector<int> &numbers, vector<char> &operations)
{
    if(idx >= isPrior.size())
    {
        vector<int> tmpNumbers;
        vector<char> tmpOperations;
        tmpNumbers.push_back(numbers[0]);
        for(int j = 0; j < isPrior.size(); j++)
        {
            if(isPrior[j])
            {
                int a = tmpNumbers.back();
                tmpNumbers.pop_back();
                int c = calculate(a, numbers[j + 1], operations[j]);
                tmpNumbers.push_back(c);
            } else 
            {
                tmpNumbers.push_back(numbers[j + 1]);
                tmpOperations.push_back(operations[j]);
            }
        }

        for(int j = 0; j < tmpOperations.size(); j++)
        {
            tmpNumbers[j + 1] = calculate(tmpNumbers[j], tmpNumbers[j + 1], tmpOperations[j]);
        }
        ans = max(ans, tmpNumbers.back());    
    } else 
    {
        ho(idx + 1, isPrior, numbers, operations);
        isPrior[idx] = true;
        ho(idx + 2, isPrior, numbers, operations);
        isPrior[idx] = false;
    }
}
int main()
{
    int n;
    cin >> n;
    // n 최대 19. 즉 최대 숫자 10개, 문자 9개가 들어올 수 있음.
    vector<int> numbers;
    vector<char> operations;
    cin >> arr;
    for(int i = 0; i < n; i++)
    {
        switch (arr[i])
        {
            case '+':
            case '-':
            case '*':
                operations.push_back(arr[i]);
                break;
            default:
                numbers.push_back(arr[i] - '0');
        }
    }

    vector<bool> isPrior(n / 2, false);
    ho(0, isPrior, numbers, operations);
    
    printf("%d\n", ans);
    return 0;
}
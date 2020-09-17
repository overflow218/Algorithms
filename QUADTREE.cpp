#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverseQT(char * arr);

int idx = 0;
int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    char arr[1010] = {0};
    cin >> arr;
    idx = 0;
    string ans = reverseQT(arr);
    cout << ans << '\n';

  }

  return 0;
}

string reverseQT(char * arr)
{
  if(arr[idx] == 0)
  {
    return "";
  }else if(arr[idx] == 'w')
  {
    idx++;
    return "w";
  }else if(arr[idx] == 'b')
  {
    idx++;
    return "b";
  } else  // x인 경우
  {
    idx++;
    string s1 = reverseQT(arr);
    string s2 = reverseQT(arr);
    string s3 = reverseQT(arr);
    string s4 = reverseQT(arr);
    return "x" + s3 + s4 + s1 + s2;
  }
}

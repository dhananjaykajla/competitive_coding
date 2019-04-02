//DHANANJAY KAJLA #BEGIN
#include<bits/stdc++.h>
using namespace std;
int main()
{
  std::string s;
  std::set<string> S;
  long long int answer = 0;
  while(getline(cin,s))
  {
    int n = s.size();
    string str;
    if(s[0]=='+')
    {
      for(int i=1;i<n;i++)
      {
        str += s[i];
      }
      S.insert(str);
    }
    else if(s[0]=='-')
    {
      for(int i=1;i<n;i++)
      {
        str += s[i];
      }
      S.erase(str);
    }
    else
    {
      int i=1;
      for(;i<n;i++)
      {
        if(s[i]==':')
        {
          break;
        }
      }
      answer += (S.size()) * (n - 1 - i) ;
    }
  }
  std::cout << answer << '\n';
}

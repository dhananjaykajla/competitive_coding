#include<bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  std::cin >> T;
  while(T--)
  {
    int n;
    std::cin >> n;
    std::vector<string> teams(n);
    for (size_t i = 0; i < (unsigned)n; i++)
    {
      std::cin >> teams[i];
    }
    string a,b;
    string team1="",team2="";//,team1s="",team2s="";
    int team1s = 0, team2s = 0;
    std::cin >> a >> b;
    size_t i = 0;
    touple <string,int,int> teamscore;
    for (; i < a.size() && a[i]!= '-'; i++)
    {
      team1 += a[i];
    }
    for(;i<a.size();i++)
    {
      team2 += a[i];
    }
    for (i=0; i < b.size() && a[i]!= ':'; i++)
    {
      team1s *= 10;
      team1s += b[i]-'0';
    }
    for(;i<b.size();i++)
    {
      team2s *= 10;
      team2s += b[i]-'0';
    }
  }
}

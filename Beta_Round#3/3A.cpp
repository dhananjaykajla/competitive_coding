//DHANANJAY KAJLA #BEGIN
#include<bits/stdc++.h>
using namespace std;
string Direction(string s, string t)
{
  string dir;
  if(t[1]>s[1])
  {
    dir.push_back('U');
  }
  else if(t[1]==s[1])
  {
    dir.push_back('-');
  }
  else
  {
    dir.push_back('D');
  }
  if(t[0]>s[0])
  {
    dir.push_back('R');
  }
  else if(t[0]==s[0])
  {
    dir.push_back('-');
  }
  else
  {
    dir.push_back('L');
  }
  return dir;
}
void Move(string &s, string &t)
{
  while(s != t)
  {
    string str = Direction(s,t);
    if(str == "UL")
    {
      std::cout << "LU" << '\n';
      s[0]--;
      s[1]++;
    }
    else if(str == "DL")
    {
      std::cout << "LD" << '\n';
      s[0]--;
      s[1]--;
    }
    else if(str == "UR")
    {
      std::cout << "RU" << '\n';
      s[0]++;
      s[1]++;
    }
    else if(str == "DR")
    {
      std::cout << "RD" << '\n';
      s[0]++;
      s[1]--;
    }
    else if(str == "U-")
    {
      std::cout << "U" << '\n';
      s[1]++;
    }
    else if(str == "D-")
    {
      std::cout << "D" << '\n';
      s[1]--;
    }
    else if(str == "-L")
    {
      std::cout << "L" << '\n';
      s[0]--;
    }
    else if(str == "-R")
    {
      std::cout << "R" << '\n';
      s[0]++;
    }
    else
    {
      break;
    }
  }
}
int main()
{
  string s,t;
  std::cin >> s >> t;
  int n = max(abs(s[0]-t[0]),abs(s[1]-t[1]));
  std::cout << n << '\n';
  Move(s,t);
  return 0;
}
//DHANANJAY KAJLA #END

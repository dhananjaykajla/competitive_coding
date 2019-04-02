#include<bits/stdc++.h>
using namespace std;
bool Format(string s)
{
  int n=s.size();
  if(s[0]!='R')
  {
    return true;
  }
  if(s[1]>='A')
  {
    return true;
  }
  for(int i=2;i<n;i++)
  {
    if(s[i]>='A')
    {
      return false;
    }
  }
  return true;
}
//eg BC23
void TrueFormat(string s, int n)
{
  int z=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]>='A')
    {
      z++;
      continue;
    }
    break;
  }
  int col=0;
  for(int i=0;i<z;i++)
  {
    col*=26;
    col+=(s[i]-'A'+1);
  }
  //std::cout << col;
  std::cout << "R";
  for(int i=z;i<n;i++)
  {
    std::cout << s[i];
  }
  std::cout << "C" << col << '\n';
}
void FalseFormat(string s, int n)
{
  int row=0;
  int i=1 ;
  for(;s[i]<='9' && s[i]>='0';i++)
  {
    row *= 10;
    row += s[i]-'0';
  }
  i++;
  int col=0 ;
  for(; i<s.size() ; i++)
  {
    col *= 10 ;
    col += s[i] - '0' ;
  }
  int row_clone=col;
  int z=26;
  int counter=0;
  while(row_clone>z)
  {
    row_clone -= z;
    z *= 26 ;
    counter++;
  }
  //std::cout << row_clone << '\n';
  std::string str="";
  bool k = false;
  int acs = row_clone % 26 ;
  if(acs == 0)
  {
    acs = 26;
    row_clone--;
  }
  str.push_back((char)(64+(acs)));
  row_clone /= 26;
  for(int i=1;i<=counter;i++)
  {
    int temp = row_clone%26;
    row_clone /= 26;
    str.push_back((char)(65+temp)) ;
  }
  std::reverse(str.begin(),str.end()) ;
  std::cout << str << row << '\n' ;
}
int main()
{
  int T;
  std::cin >> T;
  while(T--)
  {
    string s;
    std::cin >>s;
    int n=s.size();
    //std::cout << Format(s) << '\n';
    if(Format(s))
    {
      TrueFormat(s,n);
    }
    else
    {
      FalseFormat(s,n);
    }
  }
}

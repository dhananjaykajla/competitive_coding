#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,a;
  std::cin >> n >> m >> a;
  long long int answer,answer1;
  answer=m+a-1;
  answer=answer/a;
  answer1=n+a-1;
  answer1=answer1/a;
  answer=answer*answer1;
  std::cout << answer;
}

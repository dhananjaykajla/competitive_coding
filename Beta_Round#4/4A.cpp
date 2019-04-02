#include<bits/stdc++.h>
using namespace std;
int main()
{
  int w;
  std::cin >> w;
  (!(w&1) && (w!=2)) ? std::cout << "YES" : std::cout << "NO";
  return 0;
}

//DHANANJAY KAJLA #BEGIN
#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int n,v;
  std::cin >> n >> v;
  std::vector<pair<long long int, long long int> > k,c;
  long long int type, vol;
  for(long long int i=0; i<n;i++)
  {
     //std::cout << "YOY\n";
    std::cin >> type >> vol;
    if(type==1)
    {
      k.push_back(make_pair(vol,i));
    }
    else
    {
      c.push_back(make_pair(vol,i));
    }
  }
  std::sort(k.begin(),k.end());
  std::sort(c.begin(),c.end());
  long long int capacity = 0 ;
  long long int ks = k.size();
  long long int cs = c.size();
  std::vector<long long int> ans;
  //std::cout << "UOU\n";
  while(v > 1)
  {
      if(cs == 0 && ks == 0)
      {
          break;
      }
      else if(cs == 0)
      {
          ans.push_back(k[ks-1].second+1);
          capacity += k[ks-1].first;
          v--;
          ks--;
      }
      else if(ks == 0)
      {
          ans.push_back(c[cs-1].second+1);
          capacity += c[cs-1].first;
          v--;
          v--;
          cs--;
      }
      else if(ks == 1)
      {
          if(v & 1)
          {
              ans.push_back(k[ks-1].second+1);
              capacity += k[ks-1].first;
              v--;
              ks--;
          }
          else
          {
              if(k[ks-1].first > c[cs-1].first)
              {
                  ans.push_back(k[ks-1].second+1);
                  capacity += k[ks-1].first;
                  v--;
                  ks--;
              }
              else
              {
                  ans.push_back(c[cs-1].second+1);
                  capacity += c[cs-1].first;
                  v--;
                  v--;
                  cs--;
              }
          }
      }
      else if(c[cs-1].first > k[ks-1].first + k[ks-2].first)
      {
          ans.push_back(c[cs-1].second+1);
          capacity += c[cs-1].first;
          v--;
          v--;
          cs--;
      }
      else
      {
          ans.push_back(k[ks-1].second +1);
          capacity += k[ks-1].first;
          v--;
          ks--;
      }
  }
  if(v && ks)
  {
      ans.push_back(k[ks-1].second + 1);
      capacity += k[ks-1].first;
      v--;
      ks--;
  }
  std::cout << capacity << '\n';
  for (size_t i = 0; i < ans.size(); i++)
  {
      std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
}
//DHANANJAY KAJLA #END

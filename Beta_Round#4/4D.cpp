//DHANANJAY KAJLA #BEGIN
#include<bits/stdc++.h>
#pragma GCC optimize ("-O2")
//#pragma GCC optimize("-Ofast")
using namespace std;
#define incontainer(A) for(int i=0;i<A.size();i++){std::cin>>A[i];}
#define outcontainer(A) for(int i=0;i<A.size();i++){std::cout<<A[i]<<' ';}std::cout << '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define forstl(i,v) for(auto &i:v)
#define forn(i,n) for(int i=0;i<n;++i)
#define forsn(i,s,n) for(int i=s;i<n;++i)
#define rforn(i,e) for(int i=e;i>=0;--i)
#define rforsn(i,s,e) for(int i=e;i>=s;--i)
#define bitcount(i) __builtin_popcount(i) //(add ll)
#define ln '\n'
#define dbg(x) cerr<<#x<<" "<<x<<ln;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef vector<int> v32;
typedef vector<p32> vp32;
typedef vector<v32> vv32;
typedef pair<ll,ll> p64;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef vector<ll> v64;
typedef complex<double> cd;
const ld PI = acos(-1);
const int MOD = 998244353, LIM= 2e5+5;
const ld EPS = 1e-9;
const int mod = 1000000007;
//using namespace std;
//vector<bool> sieve(1000001,true);
/*
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
    {
        number = number *10 + c - 48;
    }
    if (negative)
    {
        number *= -1;
    }
}
void siever()
{
    double z = sqrt(1000001);
    sieve[0] = false;
    sieve[1] = false;
    for(int i=2; i<z ; i++)
    {
        if(sieve[i])
        {
            for(int k = 2 * i ; k < 1000001 ; k += i)
            {
                sieve[k] = false;
            }
        }
    }
}
*/
bool comp(tuple<int, int, int> a, tuple<int, int, int> b)
{
    if(get<0>(a) < get<0>(b))
    {
        return true;
   }
    if(get<0>(a) == get<0>(b))
    {
        return (get<1>(a) < get<1>(b));
    }
    return false;
}
int main()
{
    int T = 1;
    fastio;
    //std::cin >> T;
    while(T--)
    {
        int n,w,h;
        std::cin >> n >> h >> w;
        std::vector<std::tuple<int,int,int> > v;
        forn(i,n)
        {
            int w1,h1;
            std::cin >> h1 >> w1;
            if(w1 > w && h1 > h)
            {
               //std::cout << w1 << ' ' << h1 << '\n';
               v.push_back(make_tuple(h1,w1,i+1));
            }
        }
        std::sort(v.begin(),v.end(),comp);
        /*forn(i,3)
        {
            std::cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << '\n';
        }*/
        n = v.size();
        if(v.size()==0)
        {
            std::cout << 0 << '\n';
            return 0;
        }
        std::vector<int> m(n,1);
        int final_max = 1;
        int index = 0;
        for(int i=1;i<n;i++)
        {
            int maxe = 1;
            for(int j=i-1;j>=0;j--)
            {
                if(get<1>(v[j]) < get<1>(v[i]) && get<0>(v[j]) < get<0>(v[i]))
                {
                    //std::cout << i << ' ' << j << '\n';
                    maxe = max(m[j]+1,maxe);
                }
            }
            m[i] = maxe;
            if(maxe > final_max)
            {
                final_max = maxe;
                index = i;
            }
        }
        /*for(int i=0;i<n;i++)
        {
            std::cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << ' '<< m[i] << '\n';
        }*/
        std::cout << m[index] << '\n';
        //std::cout << get<0>(v[index]) << ' ' << get<1>(v[index]) << ' ' << get<2>(v[index]) << '\n';
        int answer = m[index];
        std::vector<int> anss;
        anss.push_back(get<2>(v[index]));
        int l = index;
        for (int k = index-1;k>=0;k--)
        {
           //std::cout << k << ' ' << get<0>(v[k]) << ' ' << get<0>(v[l]) << ' ' << get<1>(v[k]) << ' ' << get<1>(v[l]) << ' ' << m[k] << ' ' << answer << '\n';
           if((get<1>(v[k]) < get<1>(v[l])) && (get<0>(v[k]) < get<0>(v[l])) && (m[k]==answer-1))
           {
             //std::cout << anss.size() << '\n';
             anss.push_back(get<2>(v[k]));
             l=k;
             answer = m[k];
           }
        }
        std::reverse(anss.begin(),anss.end());
        forn(i,(int)anss.size())
        {
           std::cout << anss[i] << ' ' ;
        }
    }
	return 0;
}
//DHANANJAY KAJLA #END

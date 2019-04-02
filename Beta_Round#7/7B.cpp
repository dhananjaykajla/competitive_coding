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
int main()
{
    int T=1;
    fastio;
    while(T--)
    {
        int t,m;
        std::cin >> t >> m;
        v32 v(m,-1);
        int min_free = 0;
        std::string str;
        int x;
        int id = 1;
        while(t--)
        {
            std::cin >> str;
            if(str == "alloc")
            {
                std::cin >> x;
                int i=min_free;
                for(;i<m;i++)
                {
                    int j=i;
                    for(;j<m && j <i+x;j++)
                    {
                        if(v[j]!=-1)
                        {
                            break;
                        }
                    }
                    if(j==i+x)
                    {
                        //std::cout << i << ' ' << j << '\n';
                        for(int k=i;k <i+x;k++)
                        {
                            //std::cout << j << ' ' << v[j] << '\n';
                            v[k] = id;
                        }
                        std::cout << id << '\n';
                        id++;
                        break;
                    }
                }
                if(i==m)
                {
                    std::cout << "NULL\n";
                    continue;
                }
                if(i==min_free)
                {
                    min_free = i + x ;
                }
                /*std::cout << min_free << '\n';
                forn(i,m)
                {
                    std::cout << v[i] << '\n';
                }*/
            }
            else if(str == "erase")
            {
                std::cin >> x;
                bool ir = true;
                forn(i,m)
                {
                    if(v[i]==x)
                    {
                        ir = false;
                        min_free = min(i,min_free);
                        v[i]=-1;
                    }
                }
                if(ir)
                {
                    std::cout << "ILLEGAL_ERASE_ARGUMENT\n";
                }
                /*std::cout << min_free << '\n';
                forn(i,m)
                {
                    std::cout << v[i] << '\n';
                }*/
            }
            else
            {
                forn(i,m)
                {
                    if(v[i]!=-1)
                    {
                        if(i<min_free)
                        {
                            continue;
                        }
                        v[min_free] = v[i];
                        v[i] = -1;
                        min_free++;
                    }
                }
            }
            /*
            std::cout << "------\n";
            std::cout << min_free << '\n';
            forn(i,m)
            {
                std::cout << v[i] << '\n';
            }
            std::cout << "------\n";
            */
        }
    }
	return 0;
}
//DHANANJAY KAJLA #END

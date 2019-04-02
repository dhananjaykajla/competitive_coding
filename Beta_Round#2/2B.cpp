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
typedef vector<vp32> vvp32;
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
/*
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
//#define debg 0
int factors_2(int x)
{
    int count = 0;
    while(x%2 == 0)
    {
        x /= 2;
        count++;
    }
    return count;
}
int factors_5(int x)
{
    int count = 0;
    while(x%5 == 0)
    {
        x /= 5;
        count++;
    }
    return count;
}
int main()
{
    #ifdef debg
        double tt = clock();
    #endif
    int n;
    std::cin >> n;
    bool is_special = false;
    vv32 v(n,v32(n,0));
    vvp32 ans(n,vp32(n,make_pair(0,0)));
    int zx=-1,zy=-1;
    forn(i,n)
    {
        forn(j,n)
        {
            std::cin >> v[i][j];
            if(v[i][j]==0)
            {
                is_special = true;
                zx = i;
                zy = j;
                v[i][j] = 10;
            }
            ans[i][j].first = factors_2(v[i][j]);
            ans[i][j].second = factors_5(v[i][j]);
        }
    }
    forn(i,n)
    {
        if(i==0)
        {
            forn(j,n)
            {
                if(j==0)
                {
                    continue;
                }
                ans[i][j].first += ans[i][j-1].first;
                ans[i][j].second += ans[i][j-1].second;
            }
            continue;
        }
        forn(j,n)
        {
            if(j==0)
            {
                ans[i][j].first += ans[i-1][j].first;
                ans[i][j].second += ans[i-1][j].second;
                continue;
            }
            ans[i][j].first += min(ans[i][j-1].first, ans[i-1][j].first);
            ans[i][j].second += min(ans[i][j-1].second, ans[i-1][j].second);
        }
    }
    int twos = ans[n-1][n-1].first;
    int fives = ans[n-1][n-1].second;
    if(is_special && min(twos, fives) > 0)
    {
        std::cout << 1 << '\n';
        forn(i,zx)
        {
            std::cout << "D";
        }
        forn(j,zy)
        {
            std::cout << "R";
        }
        forn(i,n-1-zx)
        {
            std::cout << "D";
        }
        forn(j,n-1-zy)
        {
            std::cout << "R";
        }
        std::cout << '\n';
    }
    else
    {
        if(twos <= fives)
        {
            std::cout << twos << '\n';
            int i=n-1, j=n-1;
            std::string str = "";
            while(i!=0 || j!=0)
            {
                if(i==0)
                {
                    str = "R" + str;
                    j--;
                }
                else if(j==0)
                {
                    str = "D" + str;
                    i--;
                }
                else if(ans[i-1][j].first <= ans[i][j-1].first)
                {
                    str = "D" + str;
                    i--;
                }
                else
                {
                    str = "R" + str;
                    j--;
                }
            }
            std::cout << str << '\n';
        }
        else
        {
            std::cout << fives << '\n';
            int i=n-1, j=n-1;
            std::string str = "";
            while(i!=0 || j!=0)
            {
                if(i==0)
                {
                    str = "R" + str;
                    j--;
                }
                else if(j==0)
                {
                    str = "D" + str;
                    i--;
                }
                else if(ans[i-1][j].second <= ans[i][j-1].second)
                {
                    str = "D" + str;
                    i--;
                }
                else
                {
                    str = "R" + str;
                    j--;
                }
            }
            std::cout << str << '\n';
        }
    }
    #ifdef debg
        //std::cout << tt << '\n';
        std::cout << "Execution Time : " << clock()-tt << '\n';
        tt = clock();
    #endif
}
//DHANANJAY KAJLA #END

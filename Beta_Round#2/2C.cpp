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
class Point
{
public:
    double x;
    double y;
    bool is_Valid;
    void print_Point()
    {
        if(is_Valid)
        {
            std::cout << std::fixed << std::setprecision(5) << x << ' ' << y << '\n';
        }
        else
        {

        }
    }
    double distance(Point p)
    {
        double z = p.x - x;
        double zy = p.y - y;
        double ans = (z)*(z) + (zy)*(zy);
        ans = sqrt(ans);
        return ans;
    }
};
class Circle
{
public:
    double x_centre;
    double y_centre;
    double radius;
    Point return_centre()
    {
        Point p;
        p.x = x_centre;
        p.y = y_centre;
        p.is_Valid = true;
        return p;
    }
};
class Line
{
public:
    double a;
    double b;
    double c;
    double distance(Point p)
    {
        double z = a*(p.x) + b*(p.y) + c;
        z /= sqrt((a)*(a) + (b)*(b)) ;
        return abs(z);
    }
};
std::pair<double,double> quadratic_solver(double a, double b, double c)
{
    std::pair<double,double> x;
    double k = ((b)*(b)) - ((4)*(a)*(c));
    k = sqrt(k);
    //std::cout << k << '\n';
    double z = -1*(b);
    double z1 = z - k;
    z += k ;
    z /= (2)*(a);
    z1 /= (2)*(a);
    x.first = z;
    x.second = z1;
    return x;
}
std::vector<Point> Circle_Line_Intersection(Circle c, Line l)
{
    std::vector<Point> pt;
    if(l.distance(c.return_centre()) > c.radius)
    {
        return pt;
    }
    else
    {
        auto p0 = c.return_centre();
        Point p1,p2;
        p1.is_Valid = true;
        p2.is_Valid = true;
        if(l.b == 0)
        {
            double z = l.c;
            z /= l.a;
            z += p0.x;
            z = (z)*(z);
            z = (c.radius)*(c.radius) - z;
            z = sqrt(z);
            p1.x = ((-1) * (l.c)) / l.a;
            p2.x = p1.x;
            p1.y = p0.y - z;
            p2.y = p0.y + z;
            pt.push_back(p1);
            pt.push_back(p2);
            return pt;
        }
        double a_dash = (l.a)/(l.b);
        a_dash = a_dash * a_dash;
        a_dash += 1;
        double b_dash = (2*(l.a)*((l.c)+((l.b)*(p0.y)))) / ((l.b)*(l.b));
        b_dash -= (2)*(p0.x);
        double c_dash = ((p0.x)*(p0.x));
        //std::cout << c_dash << '\n';
        c_dash -= ((c.radius)*(c.radius));
        //std::cout << std::fixed << std::setprecision(3)<< c_dash << '\n';
        c_dash += (((l.c)+((l.b)*(p0.y))) * ((l.c)+((l.b)*(p0.y)))) / ((l.b)*(l.b));
        //std::cout << a_dash << ' ' << b_dash << ' ' << c_dash << '\n';
        auto answ = quadratic_solver(a_dash,b_dash,c_dash);
        p1.x = answ.first;
        p2.x = answ.second;
        p1.y = l.a * (p1.x) + l.c;
        p1.y *= -1;
        p1.y /= l.b;
        p2.y = l.a * (p2.x) + l.c;
        p2.y *= -1;
        p2.y /= l.b;
        pt.push_back(p1);
        pt.push_back(p2);
        //std::cout << p1.x << ' ' << p1.y << ' ' << '\n';
        //std::cout << p2.x << ' ' << p2.y << ' ' << '\n';
        return pt;
    }
}
std::vector<Point> Circle_Circle_Intersection(Circle c1, Circle c2)
{
    std::vector<Point> answer;
    Point cc1 = c1.return_centre();
    Point cc2 = c2.return_centre();
    if(cc1.x == cc2.x && cc1.y == cc2.y)
    {
        return answer;
    }
    double dist = cc1.distance(cc2);
    if(dist > c1.radius + c2.radius)
    {
        return answer;
    }
    else
    {
        Line l1;
        l1.a = 2*(cc2.x - cc1.x);
        l1.b = 2*(cc2.y - cc1.y);
        l1.c = (cc1.x)*(cc1.x) - (cc2.x)*(cc2.x);
        l1.c += (cc1.y)*(cc1.y) - (cc2.y)*(cc2.y);
        l1.c -= (c1.radius)*(c1.radius) - (c2.radius)*(c2.radius);
        //std::cout << l1.a << ' ' << l1.b  << ' ' << l1.c << '\n';
        return Circle_Line_Intersection(c1,l1);
    }
}
Point Line_Line_Intersection(Line l1, Line l2)
{
    Point ans;
    ans.is_Valid = true;
    ans.x = (l2.b * l1.c) - (l2.c * l1.b);
    ans.x /= (l1.b * l2.a) - (l2.b * l1.a);
    ans.y = (l2.a * l1.c) - (l2.c * l1.a);
    ans.y /= (l1.b * l2.a) - (l2.b * l1.a);
    return ans;
}
Circle Appolonian_Circle(Point p1, Point p2, double ratio)
{
   // ratio = 1 / ratio;
    Circle c;
    double ax = (ratio * (p2.x)) + p1.x;
    ax /= ratio + 1;
    double ay = (ratio * (p2.y)) + p1.y;
    ay /= ratio + 1;
    double bx = (ratio * (p2.x)) - p1.x;
    bx /= ratio - 1;
    double by = (ratio * (p2.y)) - p1.y;
    by /= ratio - 1;
    c.x_centre = ( ax + bx ) / 2;
    c.y_centre = ( ay + by ) / 2;
    //std::cout << p1.x << ' ' << p2.x << ' ' << ratio << '\n' ;
    //std::cout << c.x_centre << ' ' << c.y_centre<< ' ';// << bx << ' ' << by << '\n' ;
    double xd = bx - ax;
    double yd = by - ay;
    c.radius = sqrt((xd*xd) + (yd*yd)) / 2 ;
    //std::cout << c.radius << '\n' ;
    return c;
}
Line Appolonian_Line(Point p1, Point p2)
{
    Line l;
    if(p2.y == p1.y)
    {
        l.a = 1;
        l.b = 0;
        l.c = p1.x + p2.x;
        l.c *= -1;
        l.c /= 2;
        return l;
    }
    l.a = 2 * (p2.x - p1.x);
    l.b = 2 * (p2.y - p1.y);
    l.c = (p1.x)*(p1.x) + (p1.y)*(p1.y) - ((p2.x)*(p2.x) + (p2.y)*(p2.y));
    return l;
}
Point Optimal_Point(std::vector<Point> v, Circle c)
{
    if(v.empty())
    {
        Point p;
        p.is_Valid = false;
        p.x = 0;
        p.y = 0;
        return p;
    }
    Point answer = v[0];
    double dist = v[0].distance(c.return_centre());
    //std::cout << v.size() << ' ' << dist << '\n';
    //std::cout << v[0].x << ' ' << v[0].y << '\n';
    //std::cout << v[1].x << ' ' << v[1].y << '\n';
    forn(i,v.size())
    {
        double k = v[i].distance(c.return_centre());
        if(k<dist)
        {
            dist = k;
            answer = v[i];
        }
        //std::cout << i << ' ' << v[i].x << ' ' << v[i].y << ' ' << k << '\n';
    }
    return answer;
}
int main()
{
    #ifdef debg
        double tt = clock();
    #endif
    std::vector<Circle> Circle_vector(3);
    forn(i,3)
    {
        std::cin >> Circle_vector[i].x_centre;
        std::cin >> Circle_vector[i].y_centre;
        std::cin >> Circle_vector[i].radius;
    }
    Point answer;
    if(Circle_vector[0].radius != Circle_vector[1].radius)
    {
        Circle ac = Appolonian_Circle(Circle_vector[0].return_centre(), Circle_vector[1].return_centre(), (Circle_vector[0].radius)/(Circle_vector[1].radius));
        if(Circle_vector[0].radius != Circle_vector[2].radius)
        {
            Circle bc = Appolonian_Circle(Circle_vector[0].return_centre(), Circle_vector[2].return_centre(), (Circle_vector[0].radius)/(Circle_vector[2].radius));
            //std::cout << ac.x_centre << ' ' << ac.y_centre << ' ' << ac.radius << '\n';
            //std::cout << bc.x_centre << ' ' << bc.y_centre << ' ' << bc.radius << '\n';
            auto it = Circle_Circle_Intersection(ac,bc);
            answer = Optimal_Point(it,Circle_vector[0]);
        }
        else
        {
   //std::cout << "Yoyo" << '\n' ;
            Line bc = Appolonian_Line(Circle_vector[0].return_centre(), Circle_vector[2].return_centre());
            auto it = Circle_Line_Intersection(ac,bc);
            answer = Optimal_Point(it,Circle_vector[0]);
        }
    }
    else
    {
   //std::cout << "Yoyo" << '\n' ;
 Line ac = Appolonian_Line(Circle_vector[0].return_centre(), Circle_vector[1].return_centre());
        if(Circle_vector[0].radius != Circle_vector[2].radius)
        {
   //std::cout << "Yoyo" << '\n' ;
   Circle bc = Appolonian_Circle(Circle_vector[0].return_centre(), Circle_vector[2].return_centre(), (Circle_vector[0].radius)/(Circle_vector[2].radius));
            auto it = Circle_Line_Intersection(bc,ac);
            answer = Optimal_Point(it,Circle_vector[0]);
        }
        else
        {
            //std::cout << "YO\n";
            Line bc = Appolonian_Line(Circle_vector[0].return_centre(), Circle_vector[2].return_centre());
            //std::cout<<ac.a <<' ' << ac.b << ' ' << ac.c << '\n' ;
            //std::cout<<bc.a <<' ' << bc.b << ' ' << bc.c << '\n' ;
            Point it = Line_Line_Intersection(ac,bc);
            answer = it;
        }
    }
    answer.print_Point();
    #ifdef debg
        //std::cout << tt << '\n';
        std::cout << "Execution Time : " << clock()-tt << '\n';
        tt = clock();
    #endif
}
//DHANANJAY KAJLA #END

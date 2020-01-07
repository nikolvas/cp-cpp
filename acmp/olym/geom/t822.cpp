#include <bits/stdc++.h>

using namespace std;

using ll=long long;

struct p{
  ll x;
  ll y;
};

ll square(struct p &p1, struct p &p2, struct p &p3)
{
  return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

int main()
{
    struct p a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    ll s2 = square(a, b, c);
    double s = (s2 >=0 ? s2:(-s2))/2.0;
    cout.precision(10000);
    cout << s << '\n';
    return 0;
}

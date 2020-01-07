#include <bits/stdc++.h>

using namespace std;

struct p{
  int x;
  int y;
};

bool inters(struct p &p1, struct p &p2, struct p &p3)
{
  return min(p2.x, p3.x)<=p1.x && p1.x<=max(p2.x, p3.x)
         &&
         min(p2.y, p3.y)<=p1.y && p1.y<=max(p2.y, p3.y);
}

int sq2(struct p &p1, struct p &p2, struct p &p3)
{
  return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

int main()
{
    struct p a1, a2, b1, b2;
    cin >> a1.x >> a1.y;
    cin >> a2.x >> a2.y;
    cin >> b1.x >> b1.y;
    cin >> b2.x >> b2.y;


    int d1 = sq2(a1, b1, b2);
    int d2 = sq2(a2, b1, b2);
    int d3 = sq2(b1, a1, a2);
    int d4 = sq2(b2, a1, a2);

    if( ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
        &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))){
            cout << "Yes" << '\n';
            return 0;
    }

    bool res = false;
    if(d1 == 0 && inters(a1, b1, b2)){
       res = true;
    }else if(d2 == 0 && inters(a2, b1, b2)){
       res = true;
    }else if(d3 == 0 && inters(b1, a1, a2)){
       res = true;
    }else if(d4 == 0 && inters(b2, a1, a2)){
       res = true;
    }

    cout << (res ? "Yes":"No") << '\n';
    return 0;
}

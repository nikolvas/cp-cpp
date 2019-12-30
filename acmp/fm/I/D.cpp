#include <bits/stdc++.h>

using namespace std;

int pseudoScalarProd(int x1, int y1, int x2, int y2)
{
  return x1*y2 - x2*y1;
}

int square(const vector< pair<int,int> > &t, int i, int j, const pair<int,int> &p)
{

  int edgeX = t[i].first - t[j].first;
  int edgeY = t[i].second - t[j].second;

  int pEdgeX = t[i].first - p.first;
  int pEdgeY = t[i].second - p.second;
  return abs(pseudoScalarProd(edgeX, edgeY, pEdgeX, pEdgeY));
}

int main()
{
    vector< pair<int, int> > t(3);

    for(int i = 0; i < 3; i++){
       cin >> t[i].first >> t[i].second;
    }

    pair<int, int> p;
    cin >> p.first >> p.second;

    int s1 = square(t, 0, 1, p) + square(t, 0, 2, p) + square(t, 1, 2, p);
    int s2 = abs(pseudoScalarProd(t[0].first - t[1].first, t[0].second - t[1].second,
                                  t[0].first - t[2].first, t[0].second - t[2].second));
    if(s1 > s2){
         cout << "Out" << endl;
    }else{
         cout << "In" << endl;
    }

    return 0;
}



#include <bits/stdc++.h>

using namespace std;

struct D{
  int max;
  int prevNum;
};

vector<int> res(const vector<int>& n)
{
  D d[n.size()];
  int maxIdx = 0;
  d[0] = D{1, -1};
  for(size_t i = 1; i < n.size(); i++){
       d[i] = D{1, -1};
       for(size_t j = 0; j < i; j++){
         if(n[j] < n[i] && d[i].max < d[j].max+1){
            d[i] = D{d[j].max+1, int(j)};
         }
       }
    if(d[maxIdx].max < d[i].max){
       maxIdx = i;
    }
  }

  vector<int> res;
  int idx = maxIdx;
  for(int i = 0; i < d[maxIdx].max; i++){
     res.push_back(n[idx]);
     idx = d[idx].prevNum;
  }

  reverse(res.begin(), res.end());
  return res;
}

int main()
{

    vector<int> ns;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
       int t;
       cin >> t;
       ns.push_back(t);
    }

    vector<int> r = res(ns);
    cout << r.size() << endl;
    for(size_t i = 0; i < r.size(); i++){
      if( i != r.size()-1)
        cout << r[i] << " ";
      else
        cout << r[i];
    }

    return 0;
}

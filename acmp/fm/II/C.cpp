#include <bits/stdc++.h>

using namespace std;

void solve(int n, int* costs, bool* res)
{
  int c[n*n] = {0};
  c[0] = costs[0];
  for(int i = 1; i < n; i++){
     c[i] = costs[i]+c[i-1];
  }
  for(int i = 1; i < n; i++){
     c[n*i] = costs[n*i]+c[n*(i-1)];
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      c[i*n+j] = costs[i*n+j] + min(c[i*n+j-1], c[(i-1)*n+j]);
    }
  }

  int i = n*n-1;
  res[i] = true;
  while(i > 0){
    int cMin = c[i]-costs[i];
    if(i % n != 0 && cMin == c[i-1]){
      i = i-1;
    }else{
      i = i-n;
    }
    res[i] = true;
  }
}

int main()
{
    int n;
    cin >> n;
    int m[n*n];
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
          char tmp;
          cin >> tmp;
          m[i*n+j] = int(tmp - '0');
      }
    }

    bool res[n*n] = {false};
    solve(n, m, res);
    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
          cout << (res[i*n+j] ? '#' : '-');
       }

       if(i != n-1) cout << endl;
    }

    return 0;
}

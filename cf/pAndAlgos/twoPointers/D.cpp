#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  int res = n;

  vector<int> dx(n);
  vector<int> dy(n);
  for(int i = 0; i < n; i++){
    if(s[i] == 'U') dy[i] = 1;
    if(s[i] == 'D') dy[i] = -1;
    if(s[i] == 'R') dx[i] = 1;
    if(s[i] == 'L') dx[i] = -1;

  }

  int xx = 0, yy = 0;
  for(int i = 0; i < n; i++){
    xx += dx[i];
    yy += dy[i];
  }

  if((x + y + n) % 2 != 0 || abs(x) + abs(y) > n ){
    cout << -1 << endl;
    return 0;
  }

  if(xx == x && yy == y){
    cout << 0 << endl;
    return 0;
  }

  int l = 0;
  for(int r = 0; r < n; r++){
     yy -= dy[r];
     xx -= dx[r];
     while(abs(x - xx) + abs(y - yy) <= r - l + 1){
       yy += dy[l];
       xx += dx[l];
       l++;
     }

     if(l > 0){
        res = min(res, r - l + 2);
     }
  }

  cout << res << endl;

  return 0;
}

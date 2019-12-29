#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  ll res = 0, s1 = 0, s3 = 0;
  int l = 0;
  for(int r = n-1; r >= l; r--){
    s3 += a[r];
    while(s3 > s1 && r > l){
      s1 += a[l];
      l++;
    }

    if(s1 == s3) res = s1;
  }

  cout << res << endl;
  return 0;
}

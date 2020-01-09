#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int gcd(int a, int b)
{
  int tmp;
  while(b){
    tmp = a%b;
    a = b;
    b = tmp;
  }
  return a;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << (ll(a)*b)/gcd(a, b);
    return 0;
}

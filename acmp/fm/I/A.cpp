#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
   for(int i = 2; i <= sqrt(n); i++){
      if(n % i == 0) return false;
   }
   return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n, pCount = 0;
    cin >> m >> n;

    for(int i = m ; i <=n; i++){
        if(isPrime(i)){
          pCount++;
          cout << i << endl;
        }
    }

    if(pCount == 0)
        cout << "Absent" << endl;

    return 0;

}

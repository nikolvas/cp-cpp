#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<char> p(n+1, true);
    for(int i = 2; i*i <= n; i++){
      if(p[i])
        for(int j=2*i; j <= n; j+=i)
          p[j] = false;
    }

    int primeExist = 0;
    for(int i = m; i <=n; i++){
       if(p[i]){
        primeExist = 1;
        cout << i << '\n';
       }
    }

    if(!primeExist) cout << "Absent" << '\n';

    return 0;
}

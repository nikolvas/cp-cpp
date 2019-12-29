#include <bits/stdc++.h>

using namespace std;

int maxBooks(int n, int t, int* a)
{
   int l=0, maxBookCount=0, curSum=0;
   for(int r = 0; r < n; r++){
      curSum += *(a+r);
      while(curSum > t){
         curSum -= *(a+l);
         l++;
      }
      maxBookCount = max(maxBookCount, r-l+1);
   }

   return maxBookCount;
}

int main()
{
  int n, t;
  cin >> n >> t;
  int a[n];
  for(int i = 0; i < n; i++){
     cin >> a[i];
  }

  cout << maxBooks(n, t, a) << endl;

  return 0;
}

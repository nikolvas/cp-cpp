#include <bits/stdc++.h>

using namespace std;

int maxBooks(int n, int t, int* a)
{
   int l=0, r=0, maxBookCount=0, curCount=0, curSum=0;
   for(r = 0; r < n; r++){
      curSum += *(a+r);
      curCount++;
      while(curSum > t && l <= r){
         curSum -= *(a+l);
         l++;
         curCount--;
      }

      maxBookCount = max(maxBookCount, curCount);
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

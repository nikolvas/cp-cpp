#include <bits/stdc++.h>

using namespace std;

bool rec(int* xs, unsigned int* signs, int n, int s, int cur, long curS)
{
   if(cur == n){
      return curS == s;
   }

   unsigned int curBit = (1 << cur-1);
   (*signs) |= curBit;
   if(rec(xs, signs, n, s, cur+1, curS + *(xs + cur))){
      return true;
   }

   (*signs) ^= curBit;
   if(rec(xs, signs, n, s, cur+1, curS - *(xs + cur))){
      return true;
   }

   return false;

}

bool solution(int* xs, unsigned int* signs, int n, int s)
{
   return rec(xs, signs, n, s, 1, *xs);
}

int main()
{
   string noMsg = "No solution";

   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   //2 ≤ n ≤ 24, 0 ≤ xs[i] ≤ 5*10^7, -10^9 ≤ s ≤ 10^9.
   int n, s;
   cin >> n >> s;

   int xs[n];
   for(int i = 0; i < n; i++){
     cin >> xs[i];
   }

   unsigned int signs = 0;

   if (!solution(xs, &signs, n, s)){
      cout << noMsg << endl;
      return 0;
   }

   for(int i = 0; i < n-1; i++){
      cout << xs[i]<< ((signs & (1<<i)) == 0 ? '-' : '+');
   }
   cout << xs[n-1] << "=" << s << endl;

   return 0;
}

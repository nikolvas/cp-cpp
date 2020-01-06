#include <bits/stdc++.h>

using namespace std;

enum MOVE {R, D, L, U, NO};

MOVE nextMove(MOVE d, int* m, int n, int i, int j, int curNum){
  if(curNum == n*n) return NO;

  switch(d){
      case R:
         if(j < n-1 && !*(m + i*n + j+1))
           return R;
         return nextMove(D, m, n, i, j, curNum);
      case D:
         if(i < n-1 && !*(m + (i+1)*n+j)){
           return D;
         }
         return nextMove(L, m, n, i, j, curNum);
      case L:
         if(j > 0 && !*(m + i*n+j-1)){
           return L;
         }
         return nextMove(U, m, n, i, j, curNum);
      case U:
         if(i > 0 && !*(m + (i-1)*n+j)){
           return U;
         }
         return nextMove(R, m, n, i, j, curNum);
      case NO:
         return NO;
   }
   return NO;
}

int main()
{
    int n;
    cin >> n;
    int m[n*n] = {};

    int num = 1;
    int i = 0, j = 0;
    MOVE nextM = R;
    while(nextM != NO){
      m[i*n+j] = num;
      nextM = nextMove(nextM, m, n, i, j, num);
      switch(nextM){
          case R:
           j++;
           break;
          case D:
           i++;
           break;
          case L:
           j--;
           break;
          case U:
           i--;
           break;
          default:
           break;

      }
      num++;
    };


    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
          cout << m[i*n+j] << " ";
       }

       if(i != n-1) cout << endl;
    }

    return 0;
}

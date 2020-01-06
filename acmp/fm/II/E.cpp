#include <bits/stdc++.h>

using namespace std;

const int maxLength = 8000+1;
const int base = 10000;

vector<int> fromStr(const string& s)
{
  vector<int> res(maxLength);
  res[0] = 1;
  for(string::size_type i = 0; i < s.size(); ++i){

    for(int j = res[0]; j > 0; j--){
       int res10 = res[j]*10;
       res[j+1] = res[j+1] + res10/base;
       res[j] = res10%base;
    }

    if(res[res[0]+1] > 0) res[0]++;
    res[1] = res[1] + (int)(s[i] - '0');
 }

  return res;
}

string toStr(const vector<int>& n)
{
  vector<char> chars;
  for(auto c : to_string(n[n[0]])){
    chars.push_back(c);
  }

  for(int i = n[0]-1; i > 0; i--){
     int curRadix = n[i];
     int curOrder = base/10;
     do{
        chars.push_back('0' + curRadix/curOrder);
        curRadix %= curOrder;
        curOrder /= 10;
     }while(curOrder > 0);
  }

  return string(chars.begin(), chars.end());
}

void sumLong(const vector<int> &a, const vector<int> &b, vector<int> &c)
{
  int carry = 0;
  c[0] = max(a[0], b[0]);
  for(int i = 1; i <= c[0]; i++){
     int r = a[i] + b[i] + carry;
     c[i] = r%base;
     carry = r/base;
  }
  if(carry > 0){
     c[0]++;
     c[c[0]] = carry;
  }
}

int compare(const vector<int> &a, const vector<int> &b)
{
   if(a[0] != b[0]){
     return a[0] - b[0];
   }

   for(int i = a[0]; i > 0; i++){
       if(a[i] != b[i]){
         return a[i] - b[i];
       }
   }

   return 0;
}

void mul(vector<int> &a, int m, vector<int> &c)
{
  if(m >= base) throw invalid_argument("m must be less than base");
  int carry = 0;
  for(int i = 1; i <= a[0]; i++){
     int r = a[i]*m + carry;
     c[i] = r%base;
     carry = r/base;
  }
  c[0] = a[0];
  if(carry > 0){
     c[0]++;
     c[c[0]] = carry;
  }
}

void mul(const vector<int> &a, const vector<int> &b, vector<int> &c)
{
  int carry = 0;
  for(int i = 1; i <= a[0]; i++){
     for(int j = 1; j <= b[0]; j++){
       long r = c[i+j-1] + a[i] * b[j] + carry;
       c[j+i-1] = r%base;
       c[i+j] += r/base;
     }
  }
  c[0] = a[0] + b[0];
  while(c[0] > 1 && c[c[0]] == 0){
    c[0]--;
  }

}

void pow(vector<int> a, int p, vector<int> &c)
{
  c[0] = 1; c[1] = 1;
  if(p == 0){
    return;
  }

  while(p){
    if(p & 1){
      vector<int> tmp(maxLength);
      mul(a, c, tmp);
      c = tmp;
    }
    p >>= 1;

    vector<int> tmp(maxLength);
    mul(a, a, tmp);
    a = tmp;
  }

}

int main()
{
    string aS;
    cin >> aS;
    string bS;
    cin >> bS;
    vector<int> a = fromStr(aS);
    vector<int> b = fromStr(bS);
    vector<int> c(maxLength);
    sumLong(a, b, c);
    cout << toStr(c) << endl;
    return 0;
}

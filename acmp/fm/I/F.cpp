#include <bits/stdc++.h>

using namespace std;
const int maxNum = 13;

string res(const vector<int>& n)
{
  int count[maxNum+1]={};

  for(size_t i = 0; i < n.size(); i++){
     count[n[i]]++;
  }

  if(find(begin(count), end(count), 5) != end(count)) {
    return "Impossible";
  }
  if(find(begin(count), end(count), 4) != end(count)) {
    return "Four of a Kind";
  }

  int* f3 = find(begin(count), end(count), 3);
  int* f2 = find(begin(count), end(count), 2);
  if(f3 != end(count) && f2 != end(count)) {
    return "Full House";
  }

  if(f3 != end(count)) {
    return "Three of a Kind";
  }

  if(f2 != end(count) && find(f2+1, end(count), 2) != end(count)) {
    return "Two Pairs";
  }

  if(f2 != end(count)) {
    return "One Pair";
  }

  int c=0;
  for(size_t i = 0; i < maxNum+1; i++){
     if(count[i] != 0){
        c++;
     }
     if(count[i] == 0 && c!=0){
        break;
     }
  }

  return c == 5 ? "Straight" : "Nothing";
}

int main()
{

    vector<int> ns;
    for(size_t i = 0; i < 5; i++){
       int t;
       cin >> t;
       ns.push_back(t);
    }

    //vector<int> ns = {1, 3, 9, 3, 2};
    //vector<int> ns = {1, 5, 5, 4, 4};
    //vector<int> ns = {1, 5, 2, 4, 3};
    //vector<int> ns = {10, 11, 12, 13, 1};

    cout << res(ns) << endl;
    return 0;
}

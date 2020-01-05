#include <bits/stdc++.h>

using namespace std;

void vcout(const vector<char>& cur)
{
  for(size_t j = 0; j < cur.size(); j++){
     cout << cur[j];
  }
  cout << endl;
}

void permRec(const vector<char>& chs, vector<char>& cur, int used, int i)
{
  if(i == (int)chs.size()){
      vcout(cur);
      return;
  }

  for(size_t j = 0; j < chs.size(); j++){
     if(used & (1 << j))
       continue;
     cur.push_back(chs[j]);
     permRec(chs, cur, used|(1<<j), i+1);
     cur.pop_back();
  }
}

void perm(const vector<char>& chs)
{
  vector<char> cur;
  permRec(chs, cur, 0, 0);
}

int main()
{

    vector<char> chs;
    string s;
    cin >> s;
    for(size_t i = 0; i < s.size(); i++){
       chs.push_back(s[i]);
    }

    perm(chs);
    return 0;
}

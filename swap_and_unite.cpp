#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-9;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t;
   cin >> t;
   while (t--) {
      string str;
      cin >> str;
      
      unordered_map<int,int> mp;
      for(auto i : str) {
         mp[i-'a']++;
      }

      int min_opr = INT_MAX;

      for(auto i : mp) {
         char ch = i.first + 'a';
         int freq = i.second;
         int s = 0;
         int e = s + freq -1;

         int count = 0;
         for(int j = s; j <= e; j++) {
            if(str[j] == ch) {
               count++;
            }
         }

         min_opr = min(min_opr, (freq-count));

         while(e < str.length()) {
            if(str[s] == ch) {
               count--;
            }
            s++;

            if(e+1 < str.length() && str[e+1] == ch) {
               count++;
            }
            e++;
            min_opr = min(min_opr, (freq-count));
         }
      }

      cout << min_opr << endl;
   }

   return 0;
}
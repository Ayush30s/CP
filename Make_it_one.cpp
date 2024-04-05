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
      int l, r;
      cin >> l >> r;

      int n = r - l + 1;

      if(n%2 == 0) {
         for(int i = l; i <= r; i += 2) {
            cout << i+1 << " " << i << " ";
         }
      } else {
         if(r%2 == 0) {
            cout << -1 << endl;
         } else {
            
            for(int i = l; i <= r-3; i+= 2) {
               cout << i+1 << " " << i << " ";
            } 
            cout << r-1 << " " << r << " " << r-2 << endl;
         }
      }
   }

   return 0;
}
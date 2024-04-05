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


/* mex is the smallest non-ve number absent in the array
   the number of element i.e., n shold be the mex of the array if we mex to be maximum and also that should be the smallest +ve number absent
   ex - 0 0 3 3
        0 1 2 3 so, mex = 4(maximized) operation = 2
        as we need elements starting from 0 so max MEX possible is n = 4
        so array found using min operation 2 is correct
        so we need to convert in an array such that the MEX of that array is N so we need to cal operations sum to convert the array
        
        a1 a2 a3 . . . a(n-2) a(n-1) (sorted array)
        0  1  2  . . . . . . . . . .

        which can be found by subtracting the elemnt by its index which is the operation to get the desired element
        ex => 4 4 0 1 => sort => 0   1   4   4
                               - 0   1   2   3
                                 0 + 0 + 2 + 1 = 3

*/

int main() {
   int t;
   cin >> t;
   while(t--) {
      int n;
      cin >> n;
      int arr[n];
      for(int i = 0; i < n; i++) {
         cin >> arr[i];
      }

      long long opr =0;
      sort(arr,arr+n);
      for(int i =0; i < n; i++) {
         opr += abs(arr[i]-i);
      }

      cout << opr << endl;
   }
}
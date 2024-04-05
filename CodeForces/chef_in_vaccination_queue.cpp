#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin >> t;
   while(t--) {

      int n,p,x,y;
      cin >> n >> p >> x >> y;
      int arr[n];
      int ans = 0;
      int count = 0;

      for(int i = 0; i < n; i++) {
         cin >> arr[i];
      }

       for(int i = 0; i < n; i++) {
         
         if(count >= p) {
            break;
         }

         if(arr[i] == 0) {
            ans += x;
         } else {
            ans += y;
         }
      }

      cout << ans << endl;
   }
}
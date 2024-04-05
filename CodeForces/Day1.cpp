#include <iostream>
#include <limits.h>
#include <math.h>
#include <vector>
using namespace std;


/*Problem :  B. Swap and Delete*/
void solve1() {
   string s;
   cin >> s;

   int n = s.size();
   int arr[2] = {0,0};

   for(int i = 0; i < n; i++) {
      arr[s[i]-'0']++;
   }

   int idx = 0;

   for(int i = 0; i < n; i++) {
      if(arr[1 - (s[i]-'0')] > 0) {
         arr[1 - (s[i]-'0')]--;
      } else {
         idx = n - i;
         break;
      }
   }
   cout << idx << endl;
}

/*C. Raspberries*/
void solve2() {
   int n, k;
   cin >> n >> k;
   int sum = 0;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) {
      cin >> arr[i];
      if(arr[i] >= k && arr[i] % k == 0) {
         cout << 0 << endl;
         return;
      }
   }

   int minval = 11;
   for(int i = 0; i < n; i++) {
      int ans = -1;
      if(arr[i] > k) {
         int val = (ceil)(arr[i] / k);
         ans = arr[i] * val;
         ans = ans % k;
         ans = ans - arr[i];
      }

      if(arr[i] < k) {
         ans = k % arr[i];
      }

      minval = min(minval, ans);
   }

   cout << minval << endl;
}

int main() {
   int t;
   cin >> t;
   while (t--) {
      // solve1();
      solve2();
   }

   return 0;
}
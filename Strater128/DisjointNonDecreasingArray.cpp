#include <bits/stdc++.h>
using namespace std;


/*

INPUT:

5
4
1 1 3 1
4
4 1 3 2
3
1 1 3
5
3 1 3 2 4
6
4 1 3 5 6 5

OUTPUT:

Yes
No
Yes
Yes
No
      0  1  2  3
ex->  4  1  3  2

   we look for the first break point which makes the array not non-decreasing
   in the above example , 
   at i = 0 we get, (arr[i] > arr[i+1]) (4 > 1) so we need to incresae 1 i.e., arr[i+1] such that arr[i] <= arr[i+1]
   but not so much that it become greater than arr[i+2] thus creating a new break point
   means ,  arr[i] > arr[i+1] arr[i+2]
            lower limit is the least value added to arr[i+1] such that arr[i] <= arr[i+1] = arr[i] - arr[i+1]
            upper limit is the atmost value  added to arr[i+1] such that arr[i] <= arr[i+2] = arr[i+2] - arr[i+1]

            and we increament our index i to i+2 to skip the consecutive element and we keep calculating the UL and LL at all break points if i+2 exists 
            and we keep updating the ul = min(ul, arr[i]-arr[i+1]);
                                 and ll = max(ll, arr[i+2]-arr[i+1]); 

            and atlast we check if ll > ull it means there is no possible number to add in the conescutive break points element to make the array non-decreasing  thus ans is "NO"
            else ans is "YES"

   ex - 5      3     6     3
      
      at i = 0;
         arr[i] > arr[i+1] (break point)
         5   >   3
         UL = min(UL,arr[i]-arr[i+1]) = min(UL,2) = 2
         LL = max(LL,arr[i+2]-arr[i+1]) = max(LL,3) = 3
         i+=2

      at i = 2;
         arr[i] > arr[i+1] (break point)
         6   >   3
         UL = min(2,arr[i]-arr[i+1]) = min(UL,3) = 2
         i+2 not exits so LL remains same = 3
         i+=2

      know LL <= UL => (2 <= 3)
      =>  ans is "YES"


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

      bool flag = false;
      for(int i = 0; i < n-1; i++) {
         if(arr[i] > arr[i+1]) {
            flag = true;
            break;
         }
      }

      if(!flag) {
         cout << "YES" << endl;
      } else {
         int maxi = INT_MIN;
         int diff = 0;
         int ul = INT_MAX;
         int ll = INT_MIN;

         for(int i = 0; i < n-1;) {
            if(arr[i] > arr[i+1]) {
               if(i+2 < n)
               ul = min(ul,arr[i+2]-arr[i+1]);

               ll = max(ll,arr[i]-arr[i+1]);
               i+=2;
            } else {
               i++;
            }
         }

         if(ll > ul) {
            cout << "NO" << endl;
         } else {
            cout << "YES" << endl;
         }
      }
   }
}
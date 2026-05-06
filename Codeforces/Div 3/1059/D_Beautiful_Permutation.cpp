#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sum = n*(n+1)/2;
        int modiSum;
        cout << "2 1 " << n << "\n";
        cout << flush;
        cin >> modiSum;
        int len = modiSum - sum;

        int l = 1;
        int r = n;
        int ansr = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int x, y;
            cout << "1 1 " << mid << "\n";
            cout << flush;
            cin >> x;
            cout << "2 1 " << mid << "\n";
            cout << flush;
            cin >> y;
            int diff = y - x;
            if(diff == len){
                ansr = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        int ansl = ansr - len + 1;
        cout << "! " << ansl << " " << ansr << "\n";
        cout << flush; 
    }
    return 0;
}
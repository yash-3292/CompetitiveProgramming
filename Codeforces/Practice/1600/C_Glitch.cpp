#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int i = 1;
        int j = n;
        while(j-i+1 > 3){
            int mid = i + (j-i)/2;
            if(mid%2 == 0) mid--;
            int a, b;
            cout << "1 " << mid-1 << "\n";
            cout << flush;
            cin >> a;
            cout << "2 " << mid << "\n";
            cout << flush;
            cin >> b;
            if(a == b){
                j = mid;
            } else{
                i = mid; 
            }
        }
        cout << "3 " << i << " " << j << "\n";
        cout << flush;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++){
            int a = 0;
            int b = 0;
            for(int j=i+1; j<n; j++){
                if(arr[i] > arr[j]) a++;
                else if(arr[i] < arr[j]) b++;
            }
            int ans = max(a, b);
            cout << ans << " "; 
        }
        cout << endl;
    }
    return 0;
}
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
        int number = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] == 1) number++;
        }
        number = number/2;
        int ans = n - number;
        cout << ans << endl;
    }
    return 0;
}

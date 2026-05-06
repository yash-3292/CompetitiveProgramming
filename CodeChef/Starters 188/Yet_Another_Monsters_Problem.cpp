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
        sort(arr.begin(), arr.end());
        int mini = n;
        for(int i=0; i<n; i++){
            if(arr[i] <= i+1){
                int cost = arr[i] + n - i - 1;
                mini = min(mini, cost);
            }
        }
        cout << mini << endl;
    }
    return 0;
}
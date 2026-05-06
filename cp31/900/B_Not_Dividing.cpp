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
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        if(arr[0] == 1) arr[0]++;
        cout << arr[0] << " ";
        for(int i=1; i<n; i++){
            if(arr[i] == 1){
                arr[i]++;
            }
            if(arr[i] % arr[i-1] == 0){
                arr[i]++;
            }
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

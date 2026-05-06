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
        int mini = 0;
        int maxi = 0;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=1; i<n; i++){
            if(arr[i] < arr[mini]) mini = i;
            if(arr[i] > arr[maxi]) maxi = i;
        }
        if(arr[mini] == arr[maxi]){
            cout << "NO" << endl;
            continue;
        } 
        cout << "YES" << endl;
        for(int i=0; i<n; i++){
            if(i == mini) continue;
            if(arr[i] != arr[mini]){
                cout << mini+1 << " " << i+1 << endl;
            } else{
                cout << maxi+1 << " " << i+1 << endl;
            }
        }
    }
    return 0;
}
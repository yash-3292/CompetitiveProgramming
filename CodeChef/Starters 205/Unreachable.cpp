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
        int flag = 1;
        for(int i=0; i<n; i+=2) if(arr[i] == 1) flag = 0;
        if(flag){
            cout << "Yes" << endl;
            continue;
        }
        flag = 1;
        for(int i=1; i<n; i+=2) if(arr[i] == 1) flag = 0;
        if(flag){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}
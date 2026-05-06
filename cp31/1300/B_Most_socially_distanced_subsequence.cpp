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
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1; i<n-1; i++){
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) ans.push_back(arr[i]);
            if(arr[i-1] > arr[i] && arr[i] < arr[i+1]) ans.push_back(arr[i]);
        }
        ans.push_back(arr[n-1]);
        int size = ans.size();
        cout << size << endl;
        for(int val : ans){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
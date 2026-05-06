#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int flag = 0;
    if(n&1){
        if((arr[0]&1) && (arr[n-1]&1)){
            flag = 1;
        } 
    }
    if(flag){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}
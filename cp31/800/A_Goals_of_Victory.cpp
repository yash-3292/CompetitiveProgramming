#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr(n-1);
        for(int i=0; i<n-1; i++){
            cin >> arr[i];
        }
        int sum = 0;
        for(int i=0; i<n-1; i++){
            sum += arr[i];
        }
        cout << -1*sum << endl;
    }
    return 0;
}
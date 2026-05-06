#include<bits/stdc++.h>
using namespace std;

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
        int threshold = (int)ceil(((float)n)/2.0) - 1;
        int bigNo = 0;
        int smallNo = 0;
        for(int i=1; i<n; i++){
            if(abs(arr[0]) < abs(arr[i])){
                bigNo++;
            } else{
                smallNo++;
            }
        }
        if(bigNo >= threshold) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
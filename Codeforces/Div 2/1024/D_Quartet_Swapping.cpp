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
        vector<int> a;
        vector<int> b;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                a.push_back(arr[i]);
            } else{
                b.push_back(arr[i]);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(), b.end());
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                arr[i] = a[(int)(i/2)];
            } else{
                arr[i] = b[(int)((i-1)/2)];
            }
        }
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
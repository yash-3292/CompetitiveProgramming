#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int size = n *(n-1) / 2;
        vector<int> b(size);
        for(int i=0; i<size; i++) cin >> b[i];
        sort(b.begin(), b.end());
        int j = 0;
        for(int i=0; i<n-1; i++){
            cout << b[j] << " ";
            j += n - i - 1;
        }
        cout << b[size-1] << " ";
        cout << endl;
    }
    return 0;
}
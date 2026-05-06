#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int alice = 0;
    int bob = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) alice++;
        else if(arr[i] == 1) bob++;
    }
    if(alice > bob){
        cout << "ALICE" << endl;
    } else if(alice < bob){
        cout << "BOB" << endl;
    } else {
        cout << "TIE";
    }
    return 0;
}
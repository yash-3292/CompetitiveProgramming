#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(7, 1e8);
    for(int i=0; i<n; i++){
        int c;
        string s;
        cin >> c >> s;
        sort(s.begin(), s.end());
        int k;
        if(s == "A") k = 0;
        else if(s == "B") k = 1;
        else if(s == "C") k = 2;
        else if(s == "AB") k = 3;
        else if(s == "BC") k = 4;
        else if(s == "AC") k = 5;
        else k = 6;
        arr[k] = min(arr[k], c);
    }
    int mini = arr[6];
    mini = min(mini, arr[0]+arr[1]+arr[2]);
    mini = min(mini, arr[0]+arr[4]);
    mini = min(mini, arr[1]+arr[5]);
    mini = min(mini, arr[2]+arr[3]);
    mini = min(mini, arr[3]+arr[4]);
    mini = min(mini, arr[4]+arr[5]);
    mini = min(mini, arr[3]+arr[5]);
    if(mini == 1e8){
        cout << -1 << endl;
    } else{
        cout << mini << endl;
    }
}
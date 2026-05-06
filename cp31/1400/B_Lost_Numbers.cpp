#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    vector<int> arr = {4,8,15,16,23,42};
    map<int,pair<int,int>> mpp;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<6; j++){
            mpp[arr[i]*arr[j]] = {arr[i], arr[j]};
        }
    }
    int v12, v23, v45, v56;
    cout << "? 1 2\n" << flush;
    cin >> v12;
    cout << "? 2 3\n" << flush;
    cin >> v23;
    cout << "? 4 5\n" << flush;
    cin >> v45;
    cout << "? 5 6\n" << flush;
    cin >> v56;
    pair<int,int> p12 = mpp[v12];
    pair<int,int> p23 = mpp[v23];
    pair<int,int> p45 = mpp[v45];
    pair<int,int> p56 = mpp[v56];
    vector<int> ans(6);
    int x;
    if(p12.first == p23.first || p12.first == p23.second) x = p12.first;
    if(p12.second == p23.first || p12.second == p23.second) x = p12.second;
    ans[1] = x;
    ans[0] = v12/x;
    ans[2] = v23/x;

    if(p45.first == p56.first || p45.first == p56.second) x = p45.first;
    if(p45.second == p56.first || p45.second == p56.second) x = p45.second;
    ans[4] = x;
    ans[3] = v45/x;
    ans[5] = v56/x;
    cout << "!";
    for(int i=0; i<6; i++){
        cout << " " << ans[i];
    }
    cout << "\n";
    cout << flush;
    return 0;
}
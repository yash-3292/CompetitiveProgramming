#include<bits/stdc++.h>
using namespace std;

typedef double db;

int main(){
    db n, vb, vs;
    cin >> n >> vb >> vs;
    vector<db> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    db x, y;
    cin >> x >> y;

    double mini = INT_MAX;
    int ans = -1;
    for(int i=1; i<n; i++){
        db time = arr[i]/vb;
        time += sqrt(y*y + abs(x-arr[i])*abs(x-arr[i]))/vs;
        if(time < mini){
            mini = time;
            ans = i+1;
        } else if(time == mini){
            if(abs(arr[ans-1]-x) > abs(arr[i]-x)){
                ans = i+1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
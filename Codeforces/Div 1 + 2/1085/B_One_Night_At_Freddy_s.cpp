#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> anim(m, 0);
        vector<int> isFlash(l, 0);
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            x--;
            isFlash[x] = 1;
        }
        int flagRem = n;
        for(int i=0; i<l; i++){
            sort(anim.begin(), anim.end());
            if(flagRem >= m) anim[0]++;
            else anim[m-(flagRem+1)]++;
            if(isFlash[i]){
                sort(anim.begin(), anim.end());
                anim[m-1] = 0;
                flagRem--;
            }
        }
        sort(anim.begin(), anim.end());
        cout << anim[m-1] << endl;
    }
    return 0;
}
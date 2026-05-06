#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MaxR = 1e5 + 5;
vector<int> prime(MaxR, 1);
void pre(){
    prime[0] = 0;
    prime[1] = 0;
    for(int i=2; i<MaxR; i++){
        if(prime[i] == 1){
            for(int j=2*i; j<MaxR; j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    pre();
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int x = 1 + d;
        while(!prime[x]) x++;
        int y = x + d;
        while(!prime[y]) y++;
        int a = x*y;
        cout << a << endl;
    }
    return 0;
}

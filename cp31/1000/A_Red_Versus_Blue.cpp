#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, r, b;
        cin >> n >> r >> b;
        int rowMax = (int)ceil((double)r/(double)(b+1)); 
        int group = (int)ceil((double)r / (double)rowMax);
        int extra = b - group + 1;
        while(r != 0 || b != 0){
            if(r > rowMax){
                for(int i=0; i<rowMax; i++){
                    cout << "R";
                }
                r -= rowMax;
            } else{
                for(int i=0; i<r; i++){
                    cout << "R";
                }
                r = 0;
            }
            if(b != 0){
                cout << "B";
                b--;
                if(extra != 0){
                    if(extra > rowMax-1){
                        for(int i=0; i<rowMax-1; i++){
                            cout << "B";
                        }
                        b -= rowMax-1;
                        extra -= rowMax-1;
                    } else{
                        for(int i=0; i<extra; i++){
                            cout << "B";
                        }
                        b -= extra;
                        extra = 0;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}

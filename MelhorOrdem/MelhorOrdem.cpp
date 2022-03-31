#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 500001

using namespace std;

int S[MAX];
int T[MAX];

int low_bound(int T[MAX], int low, int high, int e){
	if ( low < 0) return 0;
    if (low >= high ){
        if ( e <= T[low] ) return low;
        return low+1;
    }
    int mid=(low+high)/2;
    if ( e > T[mid])
        return low_bound(T,mid+1,high,e);
    return low_bound(T,low,mid,e);
}


int SCM(int S[MAX], int N) {

    int k = 1; T[1] = S[1];

    for(int i=2; i<=N; ++i) {

        if(S[i] > T[k])
            k += 1, T[k] = S[i];
        else {
            int j = low_bound(T, 1, k, S[i]);
            // cout << "j de "<<S[i]<<": "<<j<<endl;
            T[j] = S[i];
        }

        // cout << "T: ";
        // for(int i=1; i<=N; ++i) cout << T[i] << ' ';
        // cout<<endl;
    }

    return k;
}

int main() {

    int N;
    while(cin >> N) {

        for(int i=1; i<=N; ++i) cin >> S[i];

        // for(int i=1; i<=N; ++i) cout << S[i] << ' ';
        // cout<<endl;

        cout << SCM(S, N) << endl;
    }

    return 0;
}
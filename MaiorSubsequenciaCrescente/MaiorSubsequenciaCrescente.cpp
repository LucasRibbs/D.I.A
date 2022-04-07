#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int> > matriz;

int low_bound(vector<int> &T, int low, int high, int e){
	if ( low < 0) return 0;
    if (low >= high ){
        if ( e == T[low] ) return low-1;
        if ( e < T[low] ) return low;
        return low+1;
    }
    int mid=(low+high)/2;
    if ( e > T[mid])
        return low_bound(T,mid+1,high,e);
    return low_bound(T,low,mid,e);
}

void ConfigurarMatrizH(matriz &H, int n, int m, matriz &M) {

    for(int i=0; i<n; ++i) {
        H[i][m-1] = 1;
        for(int j=m-2; j>=0; --j) {
            if(M[i][j]<M[i][j+1]) H[i][j] = H[i][j+1] + 1;
            else H[i][j] = 1;
        }
    }
}

void ConfigurarMatrizV(matriz &V, int n, int m, matriz &M) {

    for(int j=0; j<m; ++j) {
        V[n-1][j] = 1;
        for(int i=n-2; i>=0; --i) {
            if(M[i][j]<M[i+1][j]) V[i][j] = V[i+1][j] + 1;
            else V[i][j] = 1;
        }
    }
}

int SubMatrizMaxima(int i, int j, matriz &M, matriz &H, matriz &V) {

    int h = H[i][j], v = V[i][j];
    int result = h;

    for(int k=1; k<v; ++k) {

        int _h = low_bound(M[k+i-1], j, j+h-1, M[k+i][j]) - j;
        // cout<<h<<' '<< H[k+i][j] <<' ' << _h <<endl;
        h = min(H[k+i][j], _h);

        // cout<<"compare "<<M[k+i][j]<<' '<<M[k+i-1][j+h-1]<<endl;
        // if(M[k+i][j]<=M[k+i-1][j+h-1]) break;//{h-=1; k-=1;};
        if(h==0) break;
        result = max(result, h*(k+1));
    }

    // cout<<"M["<<i<<"]["<<j<<"] = "<<M[i][j]<<" SubMatrizMaxima = "<<result<<endl;

    return result;
}

int Resolver(matriz &M, matriz &H, matriz &V, int n, int m) {

    int result = 0;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            result = max(result, SubMatrizMaxima(i, j, M, H, V));
        }
    }

    return result;
}

int main() {

    matriz M(600,vector<int>(600,0));
    matriz H(600,vector<int>(600,0));
    matriz V(600,vector<int>(600,0));

    while(true) {
        int n, m;
        cin >> n >> m;
        if(n==0 and m==0) break;

        // M.clear(); H.clear(); V.clear();

        for(int i=0; i<n; ++i) {
            // M.push_back(vector<int>(m,0));
            // H.push_back(vector<int>(m,0));
            // V.push_back(vector<int>(m,0));
            for(int j=0; j<m; ++j) cin >> M[i][j];
        }

        ConfigurarMatrizH(H, n, m, M);
        ConfigurarMatrizV(V, n, m, M);

        // cout<<endl;
        // for(int i=0; i<n; ++i) {
        //     for(int j=0; j<m; ++j) cout<<M[i][j]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(int i=0; i<n; ++i) {
        //     for(int j=0; j<m; ++j) cout<<H[i][j]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(int i=0; i<n; ++i) {
        //     for(int j=0; j<m; ++j) cout<<V[i][j]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;

        cout << Resolver(M, H, V, n, m) <<endl;
    }

    return 0;
}
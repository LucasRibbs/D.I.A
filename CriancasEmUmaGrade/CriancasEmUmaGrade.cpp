#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char M[21][21];
vector<char> D;
vector<char> C1, C2;

void PreencherTrajetoCrianca(vector<char> &D, vector<char> &C, int x, int y) {

    C.clear();
    C.push_back(M[x][y]);

    for(int i=0; i<D.size(); ++i) {

        switch(D[i]) {
            case 'N':
                x -= 1;
                C.push_back(M[x][y]);
                break;
            case 'E':
                y += 1;
                C.push_back(M[x][y]);
                break;
            case 'S':
                x += 1;
                C.push_back(M[x][y]);
                break;
            case 'W':
                y -= 1;
                C.push_back(M[x][y]);
                break;
        }
    }
}

int SMC(vector<char> &C1, vector<char> &C2, int i, int j) {

    int T[i+1][j+1];
    memset(T,0,sizeof(T));
    // for(int n=0; n<=i; ++n) T[n][0] = 0;
    // for(int m=0; m<=j; ++m) T[0][m] = 0;

    for(int n=1; n<=i; ++n) for(int m=1; m<=j; ++m) {

        if(C1[n-1]==C2[m-1]) T[n][m] = T[n-1][m-1] + 1;
        else T[n][m] = max(T[n-1][m], T[n][m-1]);
    }

    return T[i][j];
}

int main() {

    int t;
    cin >> t;

    for(int i=0; i<t; ++i) {

        int n, m;
        cin >> n >> m;
        for(int j=1; j<=n; ++j) for(int k=1; k<=m; ++k)
            cin >> M[j][k];
        
        // for(int j=1; j<=n; ++j) for(int k=1; k<=m; ++k)
        //     cout << M[j][k] << ' ';
        // cout<<endl;

        int N, x, y; char c;

        cin >> N >> x >> y;
        D.clear();
        for(int j=0; j<N; ++j) {
            cin >> c;
            D.push_back(c);
        }
        PreencherTrajetoCrianca(D,C1,x,y);

        // for(int j=0; j<=N; ++j) cout<<C1[j]<<' ';
        // cout<<endl;

        cin >> N >> x >> y;
        D.clear();
        for(int j=0; j<N; ++j) {
            cin >> c;
            D.push_back(c);
        }
        PreencherTrajetoCrianca(D,C2,x,y);

        // for(int j=0; j<=N; ++j) cout<<C2[j]<<' ';
        // cout<<endl;

        int smc = SMC(C1,C2, C1.size(), C2.size());
        cout<<"Case "<<i+1<<": "<< C1.size()-smc <<' '<< C2.size()-smc <<endl;
    }

    return 0;
}
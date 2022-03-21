#include <iostream>
#include <iomanip>

#define MOD 1000000

using namespace std;

long long int A[2][2];
long long int B[2][1];

void MultiplicarMatrizes(long long int A[2][2], long long int B[2][2]) {

    long long int R[2][2];

    for (int i=0; i<2; ++i) for (int j=0; j<2; ++j) {

        R[i][j] = 0;
        for (int k=0; k<2; ++k)
            R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % MOD;
    }

    // for(int i = 0; i<2; ++i) {
    //     for(int j = 0; j<2; ++j) {
    //         cout << A[i][j] << ' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<'x'<<endl;
    // for(int i = 0; i<2; ++i) {
    //     for(int j = 0; j<2; ++j) {
    //         cout << B[i][j] << ' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<"="<<endl;
    // for(int i = 0; i<2; ++i) {
    //     for(int j = 0; j<2; ++j) {
    //         cout << R[i][j] << ' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<"------"<<endl;
    
    for(int i = 0; i<2; ++i) for(int j = 0; j<2; ++j) {
        A[i][j] = R[i][j];
    }
    
}

void ExponenciacaoDeMatriz(long long int A[2][2], long long int p) {

    long long int I[2][2];
    
    for(int i = 0; i<2; ++i) for(int j = 0; j<2; ++j) {
        I[i][j] = A[i][j];
    }

    --p;
    while (p > 0) {

        // cout << "p: " << p << endl;

        if(p%2==1) MultiplicarMatrizes(A,I);

        if(p>1) MultiplicarMatrizes(I,I);

        p = p / 2;
    }
}

int NumeroDeFilas(long long int N, long long int K, long long int L) {

    if(N<=1) return B[1-N][0];

    ExponenciacaoDeMatriz(A,N-1);

    long long int result = 0;
    for(int i=0; i<2; ++i)
        result = (result + A[0][i] * B[i][0]) % MOD;
    
    return result;

    // if(N==0) return 1;
    // if(N==1) return K;

    // return K*NumeroDeFilas(N-1,K,L) + L*NumeroDeFilas(N-2,K,L);
}

int main() {

    long long int N, K, L;

    while(cin >> N >> K >> L) {

        A[0][0] = K%MOD; A[0][1] = L%MOD;
        A[1][0] = 1;     A[1][1] = 0;

        B[0][0] = K % MOD;
        B[1][0] = 1;

        cout << setfill('0') << setw(6) << NumeroDeFilas(N/5,K,L) << endl;
    }

    return 0;
}
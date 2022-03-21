#include <iostream>

#define MOD 1000000007

using namespace std;

long long int A[3][3];
long long int B[3][1];

void MultiplicarMatrizes(long long int A[3][3], long long int B[3][3]) {

    long long int R[3][3];

    for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) {

        R[i][j] = 0;
        for (int k=0; k<3; ++k)
            R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % MOD;
    }

    // for(int i = 0; i<3; ++i) {
    //     for(int j = 0; j<3; ++j) {
    //         cout << A[i][j] << ' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<'x'<<endl;
    // for(int i = 0; i<3; ++i) {
    //     for(int j = 0; j<3; ++j) {
    //         cout << B[i][j] << ' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<"="<<endl;
    // for(int i = 0; i<3; ++i) {
    //     for(int j = 0; j<3; ++j) {
    //         cout << R[i][j] << ' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<"------"<<endl;
    
    for(int i = 0; i<3; ++i) for(int j = 0; j<3; ++j) {
        A[i][j] = R[i][j];
    }
    
}

void ExponenciacaoDeMatriz(long long int A[3][3], long long int p) {

    long long int I[3][3];
    
    for(int i = 0; i<3; ++i) for(int j = 0; j<3; ++j) {
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

int NumeroDeSubsets(long long int N) {

    if(N <= 3) return B[3-N][0];

    ExponenciacaoDeMatriz(A,N-3);

    long long int result = 0;
    for(int i=0; i<3; ++i)
        result = (result + A[0][i] * B[i][0]) % MOD;
    
    return result;
}

int main() {

    long long int N;

    while(cin >> N) {

        A[0][0] = 0; A[0][1] = 1; A[0][2] = 1;
        A[1][0] = 1; A[1][1] = 0; A[1][2] = 0;
        A[2][0] = 0; A[2][1] = 1; A[2][2] = 0;

        B[0][0] = 2; B[0][1] = 2; B[0][2] = 1;

        cout << NumeroDeSubsets(N) << endl;
    }

    return 0;
}
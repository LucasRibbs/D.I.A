#include <iostream>

using namespace std;

int N, A, B;

int MDC(int A, int B) {

    int r;
    while(B!=0) {
        r = A%B;
        A = B;
        B = r;
    }

    return A;
}

int MMC(int A, int B) {
    
    B = B / MDC(A,B);
    return A * B;
}

int AzulejosPintados(int N, int A, int B) {

    int mult_A = N/A;
    int mult_B = N/B;
    int mult_AB = N/MMC(A,B);

    return mult_A - mult_AB + mult_B;
}

int main() {

    while(true) {
        cin >> N >> A >> B;
        if(N==0 and A==0 and B==0) return 0;

        cout << AzulejosPintados(N,A,B) << endl;
    }

    return 0;
}
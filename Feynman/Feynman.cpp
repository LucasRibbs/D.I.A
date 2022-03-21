#include <iostream>

using namespace std;

int Quadrados(int N) {

    if(N==1) return 1;
    else return Quadrados(N-1)+(N*N);
}

int main() {

    int N;

    while(true) {
        cin >> N;
        if(N==0) return 0;

        cout << Quadrados(N) << endl;
    }

    return 0;
}
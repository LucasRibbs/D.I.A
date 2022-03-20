#include <iostream>

using namespace std;

int calls;

int Fibonacci(int X) {

    if(X <= 1) {
        ++calls;
        return X;
    }
    else {
        ++calls;
        return Fibonacci(X-1)+Fibonacci(X-2);
    }
}

int main() {

    int N, X;
    cin >> N;

    while(N>0) {
        
        cin >> X;

        calls = -1;
        int fib = Fibonacci(X);
        cout << "fib(" << X <<") = " << calls << " calls = " << fib << endl;

        --N;
    }

    return 0;
}
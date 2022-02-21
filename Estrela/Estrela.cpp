#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <cmath>

using namespace std;

bitset<46342> C;
int np = 46342;

int Raiz(long int N) {

    return (int)ceil(sqrt(N));
}

void GerarPrimos() {

    C.set();
    C.reset(0); C.reset(1);
    
    for(int i=4; i<np; i+=2) C.reset(i);

    int t, d;
    for(int i=3; i<np; i+=2) {
        if(C[i]) {
            t = i*i;
            d = i+i;

            while(t<np) {
                C.reset(t);
                t += d;
            }
        }
    }
}

long int EulerPhiFormula(long int N) {

    long int phi = N;

    if(N%2==0) {
        
        phi = phi/2;

        while(N%2==0) N = N/2;
    }

    int raizN = Raiz(N);
    for(int i=3; i<=raizN; i+=2) {
        if(C[i] and N%i==0) {
                
            phi = phi/i*(i-1);

            while(N%i==0) N = N/i;
        }
    }

    if(N>1) phi = phi/N*(N-1);

    return phi;
}

long int numTriangulosCompletos(long int N) {

    return EulerPhiFormula(N)/2;
}

int main() {

    long int N;

    GerarPrimos();

    while(cin>>N) {

        cout<<numTriangulosCompletos(N)<<endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

bitset<30000001> C;
vector<long int> P;
long int np=0, nc=30000001;

long int Raiz(long long int N) {

    return (long int)ceil(sqrt(N));
}

void GeraPrimos() {

    C.set();
    C.reset(0); C.reset(1);

    P.push_back(2); ++np;
    for(long int i=4; i<=nc; i+=2) C.reset(i);

    long int t;
    for(long int i=3; i<=nc; i+=2) {

        t = i + i;

        if(C[i]) {
            
            P.push_back(i); ++np;

            for(long int j=t+i; j<=nc; j+=t)
                C.reset(j);
        }
    }

    // for(long long int i=0; i<P.size(); ++i) cout<<P[i]<<' ';
    // cout<<endl;
}

int numDivisores(long long int N) {

    long int nd = 1;
    int count, i = 0;

    while(N>1 and i<np) {

        count = 0;
        while(N%P[i]==0) {

            N = N/P[i];
            ++count;
        }
        ++i;
        nd = nd * count + nd;
    }

    if(N>1) nd += nd;

    return nd;
}

int main() {

    long long int N;
    
    GeraPrimos();
    
    while(cin>>N) {

        if(N<1/* or N>900000000000000*/) return 1;

        while(N%2==0) N = N/2;
        cout<<numDivisores(N)<<endl;
    }

    return 0;
}
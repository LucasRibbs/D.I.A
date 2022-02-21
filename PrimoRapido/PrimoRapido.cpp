#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
 
using namespace std;

bitset<46342> C;
vector<long int> P;
unsigned int np=0, nc=46342;

unsigned int Raiz(long int p) {

    return (unsigned int)ceil(sqrt(p));
}

void GeraPrimos() {

    C.set();
    C.reset(0); C.reset(1);

    P.push_back(2); ++np;
    for(long int i=4; i<nc; i+=2) C.reset(i);

    long int t;
    for(long int i=3; i<nc; i+=2) {

        t = i + i;

        if(C[i]) {
            
            P.push_back(i); ++np;

            for(long int j=t+i; j<nc; j+=t)
                C.reset(j);
        }
    }

    // for(long long int i=0; i<P.size(); ++i) cout<<P[i]<<' ';
    // cout<<endl;
}

bool EhPrimo(long int N) {

    unsigned int raizN = Raiz(N);
    for(int i=0; P[i]<=raizN; ++i) {

        if(N%P[i]==0) {
            if(N!=P[i]) return false;
            return true;
        }
    }

    return true;
}

int main() {
 
    int count;
    long int N;

    GeraPrimos();

    cin>>count;
    for(int i=0; i<count; ++i) {

        cin>>N;

        if(EhPrimo(N)) cout<<"Prime"<<endl;
        else cout<<"Not Prime"<<endl;
    }
 
    return 0;
}
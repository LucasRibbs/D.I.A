#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <cmath>
 
using namespace std;

vector<int> F, D;
int nf = 0, nd = 1;

int Raiz(long int N) {

    return (int)ceil(sqrt(N));
}

void GerarFatores(long int N) {
    F.clear(); F.push_back(1);
    nf = 0;

    bitset<1001> C;
    C.set();
    C.reset(0); C.reset(1);
    
    int raizN = Raiz(N);
    for(int i=4; i<=raizN; i+=2) C.reset(i);

    while(N%2==0) {
        F.push_back(2); ++nf;
        N = N/2;
    }

    int t, d;
    for(int i=3; i<=raizN; i+=2) {
        if(C[i]) {
            t = i*i;
            d = i+i;

            while(t<=raizN) {
                C.reset(t);
                t += d;
            }

            while(N%i==0) {
                F.push_back(i); ++nf;
                N = N/i;
            }
        }
    }

    if(N>1) {
        F.push_back(N);
        ++nf;
    }

    // for(int i=0; i<F.size(); ++i) cout<<F[i]<<' ';
    // cout<<endl;
}

void GerarDivisores(long int N) {
    GerarFatores(N);

    D.clear(); nd = 1;
    D.push_back(1);

    int k, nda;
    for(int i=1; i<=nf; ++i) {
        if(F[i]==F[i-1])
            k = k * F[i];
        else {
            k = F[i];
            nda = nd;
        }

        for(int j=0; j<nda; ++j) {
            D.push_back(k*D[j]);
            ++nd;
        }
    }

    // for(int i=0; i<D.size(); ++i) cout<<D[i]<<' ';
    // cout<<endl;
}

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

int main() {

    long int T;
    int A, B, C;

    while(true) {

        cin>>T>>A>>B;
        if(T==0 or A==0 or B==0) break;

        GerarDivisores(T);

        set<int> sortD (D.begin(), D.end());

        int mmcAB = MMC(A,B);
        // for(set<int>::iterator it=sortD.begin(); it!=sortD.end(); ++it)
        //     cout<<MMC(mmcAB,*it)<<' ';
        // cout<<endl;

        bool espaco = false;
        for(set<int>::iterator it=sortD.begin(); it!=sortD.end(); ++it) {
            if(MMC(mmcAB,*it)==T) {
                if(espaco) cout<<' '<<*it;
                else {cout<<*it; espaco=true;}
            }
        }
        cout<<endl;
    }
 
    return 0;
}
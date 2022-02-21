#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

bitset<2500> P;
int np = 2500;
int N, M, K;

int Raiz(int N) {
    return (int)ceil(sqrt(N));
}

void GerarPrimos() {

    P.set();
    P.reset(0); P.reset(1);

    for(int i=4; i<np; i+=2) P.reset(i);

    int t, d;
    for(int i=3; i<=Raiz(np); i+=2) {
        if(P[i]) {

            t = i*i;
            d = i+i;
            while(t<np) {
                if(P[t]) P.reset(t);
                t += d;
            }
        }
    }

    // for(int i=0; i<np; ++i) if(P[i]) cout<<i<<' ';
    // cout<<endl;
}

unsigned long long int Combinacao(int n, int p) {

    if(n==p) return 1;

    p = (p<n-p) ? n-p : p;

    vector<int> v; int k;
    for(int i=2; i<=n-p; ++i) {
        k = i;

        while(k%2==0 and k>2) {
            k = k/2;
            v.push_back(2);
        }

        for(int j=3; j<=Raiz(i); j+=2) {
            while(k%j==0) {
                k = k/j;
                v.push_back(j);
            }
        }

        if(k>1) v.push_back(k);
    }

    unsigned long long int c = 1;
    for(int i=p+1; i<=n; ++i) {
        k = i;
        for(int j=0; j<v.size(); ++j)
            if(k%v[j]==0) {
                k = k/v[j];
                v.erase(v.begin()+j);
                --j;
            }
        
        c *= k;
    }
    
    // cout<<"C("<<n<<","<<p<<") = "<<c<<endl;
    return c;
}

int numPrimosNaLinha(int r) {

    int count = 0; --r;
    for(int c=0; c<M; ++c)
        if(P[r*M+c]) ++count;

    return count;
}

int numPrimosNaColuna(int c) {

    int count = 0; --c;
    for(int r=0; r<N; ++r)
        if(P[r*M+c]) ++count;

    return count;
}

unsigned long long int numDeApostasNaLinha(int r) {

    if(K>M) return 0;

    int numValidos = M - numPrimosNaLinha(r);
    if(K>numValidos) return 0;

    return Combinacao(numValidos,K);
}

unsigned long long int numDeApostasNaColuna(int c) {

    if(K>N) return 0;

    int numValidos = N - numPrimosNaColuna(c);
    if(K>numValidos) return 0;

    return Combinacao(numValidos,K);
}

unsigned long long int numTotalDeApostas(int N, int M) {

    unsigned long long int count = 0;
    for(int r=1; r<=N; ++r) count += numDeApostasNaLinha(r);
    if(K!=1) for(int c=1; c<=M; ++c) count += numDeApostasNaColuna(c);

    return count;
}

int main() {

    GerarPrimos();

    while(true) {

        cin>>N>>M>>K;
        if(N==0 or M==0 or K==0) break;

        cout<<numTotalDeApostas(N,M)<<endl;
    }
 
    return 0;
}

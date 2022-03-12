#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>

using namespace std;

int N, e, C;
int p, q;
int t, d, M;

void FatorarN() {

    bitset<31624> C;
    int sqrtN = (int)ceil(sqrt(N));

    C.set();

    for(long int i=3; i<=sqrtN; i+=2) {

        if(C[i]) {

            if(N%i==0) {
                p = i;
                q = N/i;
                return;
            }

            int t = i * i;
            int d = i + i;
            for(int j=t; j<=sqrtN; j+=d) {
                C.reset(j);
            }
        }
    }
}

int MDCE(int a, int b) {
    
    vector<int> Pa, Pb;
    Pa.push_back(0); Pb.push_back(0);

    int f;
    int t = 0, x = 1, y = 0;
    int A = a, B = b;

    while(B!=0) {
        ++t;
        Pa.push_back(A); Pb.push_back(B);
        f = A%B; A = B; B = f;
    }
    for(int i=t; i>0; --i) {

        f = y;
        y = x - (Pa[i]/Pb[i])*y;
        x = f;
    }

    x = (x<0) ? x+b : x;
    return x%b;
}

int MultMod(int a, int b, int n) {

	long long int la, lb;

	la = a; lb = b;
    int multMod = (la*lb)%n;

	return multMod;
}

int Exp(int a, int b, int n) {

    if(b==0) return 1;

    else if(b%2==1) return MultMod(a,Exp(a,b-1,n),n);

    else {
        int x = Exp(a,b/2,n);
        return MultMod(x,x,n);
    }
}

int main() {

    cin >> N >> e >> C;

    FatorarN();

    t = (p-1)*(q-1);

    d = MDCE(e,t);

    M = Exp(C,d,N);

    cout<<M<<endl;

    return 0;
}
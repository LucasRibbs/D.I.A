#include <iostream>

using namespace std;

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

    const int N = 2147483647;

    int R; cin>>R;
    
    cout<<Exp(3,R,N)<<endl;

    return 0;
}
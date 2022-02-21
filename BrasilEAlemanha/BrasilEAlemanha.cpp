#include <iostream>
 
using namespace std;

long long int N;

void CalcularPlacar() {

    long int golsBrasil, golsAlemanha;
    golsBrasil = N/90;
    golsAlemanha = (N%90)?(N*7/90 + 1):(N*7/90);

    cout<<"Brasil "<<golsBrasil<<" x Alemanha "<<golsAlemanha<<endl;
}

int main() {
    
    while(true) {

        cin>>N;
        if(N==0) break;
        if(N<90 or N>1000000000) return 1;

        CalcularPlacar();

    }

    return 0;
}

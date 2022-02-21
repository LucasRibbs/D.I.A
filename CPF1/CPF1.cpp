#include <iostream>
#include <string>
 
using namespace std;

void ValidarCPF(string cpf) {

    char c;
    int s1,s2,p,b1,b2;

    p = 0;
    s1 = 0; s2 = 0; 
    for(int i=1; i<=9; ++i) {

        c = cpf.at(i+p-1);
        s1 += ((int)(c - '0')) * (i);
        s2 += ((int)(c - '0')) * (10 - i);

        if(i%3==0) p+=1;
    }

    b1 = cpf.at(12) - '0';
    b2 = cpf.at(13) - '0';
    s1 = s1 % 11 % 10;
    s2 = s2 % 11 % 10;

    if(s1==b1 and s2==b2) cout<<"CPF valido"<<endl;
    else cout<<"CPF invalido"<<endl;
}

int main() {

    string cpf;
 
    while(cin>>cpf) {

        ValidarCPF(cpf);
    }
 
    return 0;
}

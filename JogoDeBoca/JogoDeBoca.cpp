#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    string entrada;
    char c;
    int soma = 0;
    
    while(cin>>entrada) {
        
        for(int i=0; i<entrada.size(); ++i) {
            c = entrada.at(i);
            soma += c - '0';
        }

        cout<<soma%3<<endl;

        soma = 0;
    }
 
    return 0;
}
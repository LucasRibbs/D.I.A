#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

char vogaisArray[] = {'a','e','i','o','u'};
set<char> vogais (vogaisArray,vogaisArray+5);

int N;
string chave, frase;
vector<string> palavras;

bool ehVogal(char c) {
    return (vogais.find(c)!=vogais.end());
}

void pegarPalavras(string frase) {

    palavras.clear();

    string str;
    stringstream ss (frase);

    while(getline(ss, str, ' ')){
        palavras.push_back(str);
    }
}

char LetraCriptografada(char c, char chave) {

    const char max = 'z' - 'a';
    c = c - 'a';
    chave = chave - 'a';

    char criptografado = (c+chave>max) ? c+chave-max-1 : c+chave;

    return criptografado + 'a';
}

string Criptografar(string frase) {

    pegarPalavras(frase);

    // for(int i=0; i<palavras.size(); ++i) cout<<palavras[i]<<'-';
    // cout<<endl;

    int iChave = 0;
    string criptografado = "";

    for(int i=0; i<palavras.size(); ++i) {

        if(!(palavras[i].size())) continue;

        if(ehVogal(palavras[i].at(0))) {

            criptografado += palavras[i];
            if(i!=palavras.size()-1) criptografado.push_back(' ');

            continue;
        }

        for(int j=0; j<palavras[i].size(); ++j) {

            char c = palavras[i].at(j);
            c = LetraCriptografada(c, chave.at(iChave));
            criptografado.push_back(c);

            ++iChave;
            iChave %= chave.size();
        }

        if(i!=palavras.size()-1) criptografado.push_back(' ');
    }

    return criptografado;
}

int main() {

    cin>>chave;
    cin>>N;
    cin.ignore();

    for(int i=0; i<N; ++i) {
        getline(cin,frase);

        cout<<Criptografar(frase)<<endl;
    }

    return 0;
}
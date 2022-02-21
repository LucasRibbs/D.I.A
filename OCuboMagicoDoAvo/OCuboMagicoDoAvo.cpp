#include <iostream>
#include <string>
#include <queue>
 
using namespace std;

struct Face {
    char cor[3][3];
    string interfere[4];
};

Face faces[7];
queue<string> rotacoes;

void InicializarFaces() {

    for(int i=0; i<3; ++i)
        cin>>faces[5].cor[i][0]>>faces[5].cor[i][1]>>faces[5].cor[i][2];

    for(int i=0; i<3; ++i)
        cin>>faces[1].cor[i][0]>>faces[1].cor[i][1]>>faces[1].cor[i][2]
           >>faces[2].cor[i][0]>>faces[2].cor[i][1]>>faces[2].cor[i][2]
           >>faces[3].cor[i][0]>>faces[3].cor[i][1]>>faces[3].cor[i][2]
           >>faces[4].cor[i][0]>>faces[4].cor[i][1]>>faces[4].cor[i][2];

    for(int i=0; i<3; ++i)
        cin>>faces[6].cor[i][0]>>faces[6].cor[i][1]>>faces[6].cor[i][2];
}

void InicializarRotacoes() {
	
	string rotacao;
	while(true) {
		
		cin>>rotacao;
		if(rotacao.at(0) == '0') break;

		rotacoes.push(rotacao);
	}
}

void CoresEm(string local, char cores[3]) {

    int face = local.at(1)-'0';

    switch(local.at(0)) {
        case 'E':
            for(int i=0; i<3; ++i) cores[i] = faces[face].cor[i][0];
            break;
        case 'C':
            for(int i=0; i<3; ++i) cores[i] = faces[face].cor[0][i];
            break;
        case 'D':
            for(int i=0; i<3; ++i) cores[i] = faces[face].cor[i][2];
            break;
        case 'B':
            for(int i=0; i<3; ++i) cores[i] = faces[face].cor[2][i];
            break;
    }
}

void Atribui(char cores[3], string local, bool inverte) {

    int face = local.at(1)-'0';

    switch(local.at(0)) {
        case 'E':
            for(int i=0; i<3; ++i) {
                if(!inverte) faces[face].cor[i][0] = cores[i];
                else faces[face].cor[2-i][0] = cores[i];
            }
            break;
        case 'C':
            for(int i=0; i<3; ++i) {
                if(!inverte) faces[face].cor[0][i] = cores[i];
                else faces[face].cor[0][2-i] = cores[i];
            }
            break;
        case 'D':
            for(int i=0; i<3; ++i) {
                if(!inverte) faces[face].cor[i][2] = cores[i];
                else faces[face].cor[2-i][2] = cores[i];
            }
            break;
        case 'B':
            for(int i=0; i<3; ++i) {
                if(!inverte) faces[face].cor[2][i] = cores[i];
                else faces[face].cor[2][2-i] = cores[i];
            }
    }
}

void GirarFace(int face, bool horario) {

    char aux[4][3];
    for(int i=0; i<3; ++i) aux[0][i]=faces[face].cor[0][i];
    for(int i=0; i<3; ++i) aux[1][i]=faces[face].cor[i][2];
    for(int i=0; i<3; ++i) aux[2][i]=faces[face].cor[2][i];
    for(int i=0; i<3; ++i) aux[3][i]=faces[face].cor[i][0];

    for(int i=0; i<3; ++i) {
        if(horario) faces[face].cor[i][2]=aux[0][i];
        else faces[face].cor[2-i][0]=aux[0][i];
    }
    for(int i=0; i<3; ++i) {
        if(horario) faces[face].cor[2][2-i]=aux[1][i];
        else faces[face].cor[0][i]=aux[1][i];
    }
    for(int i=0; i<3; ++i) {
        if(horario) faces[face].cor[i][0]=aux[2][i];
        else faces[face].cor[2-i][2]=aux[2][i];
    }
    for(int i=0; i<3; ++i) {
        if(horario) faces[face].cor[0][2-i]=aux[3][i];
        else faces[face].cor[2][i]=aux[3][i];
    }

}

void FazerRotacao(int face, bool horario) {

    char aux[4][3];

    CoresEm(faces[face].interfere[0], aux[0]);
    CoresEm(faces[face].interfere[1], aux[1]);
    CoresEm(faces[face].interfere[2], aux[2]);
    CoresEm(faces[face].interfere[3], aux[3]);

    bool inverte = !(face==1 or face==2 or face==5 or face==6);
    if(horario) Atribui(aux[0], faces[face].interfere[1], inverte);
    else Atribui(aux[1], faces[face].interfere[0], inverte);
    
    inverte = !(face==1 or face==4 or face==5 or face==6);
    if(horario) Atribui(aux[1], faces[face].interfere[2], inverte);
    else Atribui(aux[2], faces[face].interfere[1], inverte);

    inverte = !(face==2 or face==3 or face==5 or face==6);
    if(horario) Atribui(aux[2], faces[face].interfere[3], inverte);
    else Atribui(aux[3], faces[face].interfere[2], inverte);
    
    inverte = !(face==3 or face==4 or face==5 or face==6);
    if(horario) Atribui(aux[3], faces[face].interfere[0], inverte);
    else Atribui(aux[0], faces[face].interfere[3], inverte);

    GirarFace(face, horario);
    
}

void Iniciar() {

    while(!rotacoes.empty()) {

        string rotacao = rotacoes.front();
        FazerRotacao(rotacao.at(1)-'0', rotacao.at(0)=='+');
        rotacoes.pop();
    }
}

bool Verificar() {

    for(int i=1; i<=6; ++i) {
        
        for(int j=0; j<3; ++j) for(int k=0; k<3; ++k) {

            for(int l=j; l<3; ++l) for(int m=k; m<3; ++m)
                if(faces[i].cor[j][k]!=faces[i].cor[l][m]) return false;
        }

    }

    return true;
}

void Print() {

    for(int i=0; i<3; ++i)
        cout<<"      "<<faces[5].cor[i][0]<<' '<<faces[5].cor[i][1]<<' '<<faces[5].cor[i][2]<<endl;
    for(int i=0; i<3; ++i)
        cout<<faces[1].cor[i][0]<<' '<<faces[1].cor[i][1]<<' '<<faces[1].cor[i][2]<<' '<<faces[2].cor[i][0]<<' '<<faces[2].cor[i][1]<<' '<<faces[2].cor[i][2]<<' '<<faces[3].cor[i][0]<<' '<<faces[3].cor[i][1]<<' '<<faces[3].cor[i][2]<<' '<<faces[4].cor[i][0]<<' '<<faces[4].cor[i][1]<<' '<<faces[4].cor[i][2]<<endl;
    for(int i=0; i<3; ++i)
        cout<<"      "<<faces[6].cor[i][0]<<' '<<faces[6].cor[i][1]<<' '<<faces[6].cor[i][2]<<endl;
}

int main() {

    int N; cin>>N;
    if(N<0) return 1;

    faces[1].interfere[0] = "E5"; faces[1].interfere[1] = "E2"; faces[1].interfere[2] = "E6"; faces[1].interfere[3] = "D4";
    faces[2].interfere[0] = "B5"; faces[2].interfere[1] = "E3"; faces[2].interfere[2] = "C6"; faces[2].interfere[3] = "D1";
    faces[3].interfere[0] = "D5"; faces[3].interfere[1] = "E4"; faces[3].interfere[2] = "D6"; faces[3].interfere[3] = "D2";
    faces[4].interfere[0] = "C5"; faces[4].interfere[1] = "E1"; faces[4].interfere[2] = "B6"; faces[4].interfere[3] = "D3";
    faces[5].interfere[0] = "C4"; faces[5].interfere[1] = "C3"; faces[5].interfere[2] = "C2"; faces[5].interfere[3] = "C1";
    faces[6].interfere[0] = "B2"; faces[6].interfere[1] = "B3"; faces[6].interfere[2] = "B4"; faces[6].interfere[3] = "B1";

    for(int i=0; i<N; ++i) {

        InicializarFaces();
        InicializarRotacoes();
        Iniciar();

        if(Verificar()) cout<<"Yes, grandpa!"<<endl;
        else cout<<"No, you are wrong!"<<endl;
    
    }
 
    return 0;
}

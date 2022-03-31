#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct ponto {
    int x, y;
    ponto(){ x = y = 0;}
    ponto(int _x, int _y){ x=_x; y=_y; }
};

struct triangulo {
    ponto vertice;
    double arc_A, arc_B;
    triangulo(){ arc_A = arc_B = 0.0; vertice=ponto(); }
    triangulo(ponto _vertice, double _A, double _B) { vertice=_vertice; arc_A=_A; arc_B=_B; }
};

int N, A, B;

bool TrianguloMaisAlto(triangulo t1, triangulo t2) {
    return (t1.vertice.y > t2.vertice.y);
}

void InserirTriangulo(vector<triangulo> &t, int x, int y, int i) {

    double hypot_A = sqrt((x-A)*(x-A) + (y-0)*(y-0));
    double hypot_B = sqrt((x-B)*(x-B) + (y-0)*(y-0));

    t[i].arc_A = acos( (x-A)/hypot_A );
    t[i].arc_B = acos( (B-x)/hypot_B );
    t[i].vertice.x = x; t[i].vertice.y = y;
}

bool EhInterior(triangulo t1, triangulo t2) {

    return (t1.arc_A<t2.arc_A and t1.arc_B<t2.arc_B);
}

void ContarSequencias(vector<int> &k, int idx, vector<vector<int> > &M) {

    for(int i=0; i<M[idx].size(); ++i) {
        if(k[idx]+1 > k[M[idx][i]]) {
            k[M[idx][i]] = k[idx]+1;
            ContarSequencias(k, M[idx][i], M);
        }
    }
}

int SCM(vector<triangulo> &t) {

    vector<vector<int> > M (N, vector<int>());
    vector<int> cont (N,0);

    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            if(EhInterior(t[j],t[i])) {
                M[i].push_back(j);
                ++cont[j];
    }}}

    // for(int i=0; i<N; ++i) {
    //     for(int j=0; j<M[i].size(); ++j) cout<<M[i][j]<<' ';
    //     cout<<endl;
    // }

    // for(int i=0; i<N; ++i) cout<<cont[i]<<' ';
    // cout<<endl;

    vector<int> k (N,0);
    for(int i=0; i<N; i++) {
        if(cont[i]==0) {
            k[i] = 1;
            ContarSequencias(k, i, M);
        }
    }
    
    return *max_element(k.begin(),k.end());
}

int main() {

    cin >> N >> A >> B;

    vector<triangulo> t (N,triangulo());

    for(int i=0; i<N; ++i) {
        int x, y;
        cin >> x >> y;
        InserirTriangulo(t, x, y, i);
    }

    sort(t.begin(), t.end(), TrianguloMaisAlto);

    // cout<<"P = {";
    // for(int i=0; i<N; ++i) cout<<"("<<t[i].vertice.x<<','<<t[i].vertice.y<<"),";
	// cout<<"\b}"<<endl;

    cout << SCM(t) << endl;

    return 0;
}
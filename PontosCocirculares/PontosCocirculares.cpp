#include <iostream>
#include <cmath>

#define QZERO 0.00000001

using namespace std;

struct ponto {
    double x, y;
};

struct reta {
    double a, b, c;
};

ponto P[101];

ponto PontoMedio(ponto p1, ponto p2) {

    ponto p;
    p.x = (p1.x+p2.x)/2;
    p.y = (p1.y+p2.y)/2;

    return p;
}

double DistanciaEntrePontos(ponto p1, ponto p2) {

    return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

reta PontosParaReta(ponto p1, ponto p2) {

    reta r;

    if(p1.x == p2.x) {
        r.a = 1; r.b = 0; r.c = -p1.x;
    } else {
        r.b = 1;
        r.a = (p2.y-p1.y)/(p1.x-p2.x);
        r.c = -(r.a*p1.x) - (r.b*p1.y);
    }

    return r;
}

reta PontoTangenteParaReta(ponto p, double m) {

    reta r;
    r.a = -m;
    r.b = 1;
    r.c = -(r.a*p.x + r.b*p.y);

    return r;
}

reta Perpendicular(reta r, ponto p) {

    reta rp;

    if(fabs(r.b) <= QZERO) {
        rp.a = 0; rp.b = 1; rp.c = -p.y;
    } else if(fabs(r.a) <= QZERO) {
        rp.a = 1;  rp.b = 1;  rp.c = -p.x;
    } else {
        rp = PontoTangenteParaReta(p, r.b/r.a);
    }

    return rp;
}

ponto PontoInterseccao(reta r1, reta r2) {

    ponto p;

    p.x = (r2.b*r1.c-r1.b*r2.c)/(r2.a*r1.b-r1.a*r2.b);
    if(fabs(r1.b)>QZERO) {
        p.y = -(r1.a*p.x+r1.c)/r1.b;
    } else {
        p.y = -(r2.a*p.x+r2.c)/r2.b;
    }

    return p;
}

bool Concorrentes(reta r1, reta r2) {

    return !(fabs(r1.a-r2.a)<=QZERO && fabs(r1.b-r2.b)<=QZERO);
}

ponto CentroCircunferencia(ponto p1, ponto p2, ponto p3) {

    reta r1 = PontosParaReta(p1,p2);
    reta r2 = PontosParaReta(p2,p3);

    if(Concorrentes(r1,r2)) {

        ponto m1 = PontoMedio(p1,p2);
        ponto m2 = PontoMedio(p2,p3);

        reta rp1 = Perpendicular(r1,m1);
        reta rp2 = Perpendicular(r2,m2);

        ponto intersec = PontoInterseccao(rp1,rp2);

        return intersec;
    }

    return p2;
}

int main() {

    int N;

    while(true) {

        cin >> N;
        if(N == 0) break;

        for(int i=1; i<=N; ++i)
            cin >> P[i].x >> P[i].y;

        if(N<=3) cout << N << endl;

        else {

            int max = 0;

            for(int i=1; i<=N; ++i) {
                for(int j=i+1; j<=N; ++j) {
                    for(int k=j+1; k<=N; ++k) {

                        ponto c = CentroCircunferencia(P[i],P[j],P[k]);
                        double r = DistanciaEntrePontos(c,P[j]);
                        int qtd = 0;

                        if(r<=QZERO) qtd = 2;
                        else for(int l=1; l<=N; ++l) {
                            double d = DistanciaEntrePontos(P[l],c);
                            if(fabs(r-d)<=QZERO) ++qtd;
                        }

                        max = (qtd>max)?qtd:max;
                    }
                }
            }

            cout << max << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define QZERO 0.00000001

using namespace std;

struct ponto {
    double x, y;
};

struct aleta {
    ponto i, f;
};

aleta A[1001];

double DistanciaEntrePontos(ponto p1, ponto p2) {

    return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

double DistanciaPontoAleta(ponto p, aleta a) {

    double A = p.x - a.i.x;
    double B = p.y - a.i.y;
    double C = a.f.x - a.i.x;
    double D = a.f.y - a.i.y;

    double dot = A*C + B*D;
    double len_sq = C*C + D*D;
    double param = -1;
    if(len_sq != 0) param = dot/len_sq;

    double xx, yy;
    if(param < 0) {
        xx = a.i.x;
        yy = a.i.y;
    } else if(param > 1) {
        xx = a.f.x;
        yy = a.f.y;
    } else {
        xx = a.i.x + param * C;
        yy = a.i.y + param * D;
    }

    double dx = p.x - xx;
    double dy = p.y - yy;
    return sqrt(dx*dx + dy*dy);
}

int main() {

    int N;
    double L, H;

    while(cin >> N) {

        cin >> L >> H;

        for(int i=1; i<=N; ++i) {

            if(i%2) A[i].i.x = 0;
            else A[i].i.x = L;

            cin >> A[i].i.y >> A[i].f.x >> A[i].f.y;
        }

        double res = L - A[1].f.x;

        for(int i=2; i<=N; ++i) {

            double d = DistanciaPontoAleta(A[i-1].f, A[i]);
            res = min(res, d);

            if(i%2) res = min(res, L - A[i].f.x);
            else res = min(res, A[i].f.x);
        }

        cout << fixed << setprecision(2) << res << endl;
    }

    return 0;
}
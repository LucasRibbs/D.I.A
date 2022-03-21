#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

double PorcentagemMelhorPremio(int S) {

    vector<double> porcentagens (3,0.0);
    porcentagens[1] = 100.0;

    for(int i=2; i<S; ++i) {

        vector<double> aux (1,0.0);

        for(int j=0; j<i; ++j) {

            aux.push_back( (porcentagens[j]+porcentagens[j+1]) / 2.0);
        }
        aux.push_back(0.0);

        porcentagens.clear();
        porcentagens.insert(porcentagens.begin(), aux.begin(), aux.end());
    }

    int idx = porcentagens.size()/2;
    return (porcentagens[idx-1]+porcentagens[idx])/2.0;
}

int main() {

    int S;
    cin >> S;

    printf("%.2f\n", PorcentagemMelhorPremio(S));

    return 0;
}
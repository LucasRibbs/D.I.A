#include <iostream>

using namespace std;

int N;
struct paralelepipedo {
	int h, w, d;
} a, b;

bool PodeEmpilhar(paralelepipedo a, paralelepipedo b) {
	
	int dimensoes[2][3] = { {b.h,b.w,b.d} , {a.h,a.w,a.d} };
	
	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			
			if(i==j) continue;
			
			if((dimensoes[0][i]>dimensoes[1][0] and dimensoes[0][j]>dimensoes[1][1]) or (dimensoes[0][i]>dimensoes[1][0] and dimensoes[0][j]>dimensoes[1][2]) or (dimensoes[0][i]>dimensoes[1][1] and dimensoes[0][j]>dimensoes[1][2]))
				return true;
		}
	}
	
	return false;
}

int CompararParalelepidedos() {
	
	if(PodeEmpilhar(a,b)) {
		if(PodeEmpilhar(b,a)) return 3;
		else return 1;
	}
	
	if(PodeEmpilhar(b,a)) return 2;
	
	return 0;
}

int main() {

	cin>>N;
	if(N>20 and N<1) return 1;
	
	for(int i=0; i<N; ++i) {
		
		cin>>a.h>>a.w>>a.d>>b.h>>b.w>>b.d;
		
		cout<<CompararParalelepidedos()<<endl;
	}
	

	return 0;
}

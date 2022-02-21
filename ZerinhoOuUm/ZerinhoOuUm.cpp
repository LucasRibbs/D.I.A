#include <iostream>

using namespace std;

int main() {

    int A, B, C;

    while(cin>>A>>B>>C) {
			
			if(A!=B) {
				if(A!=C)
					cout<<'A'<<endl;
				else if(B!=C)
					cout<<'B'<<endl;
				else
					cout<<'*'<<endl;
			}
			else if(C!=A)
				cout<<'C'<<endl;
			else
				cout<<'*'<<endl;
	}
	
    return 0;
}

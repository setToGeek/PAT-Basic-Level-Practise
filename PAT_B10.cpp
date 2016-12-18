#include <iostream>
using namespace std;

#define MAXSIZE 10000
int main(){
        int Nums = 0;
        int Tag = 0;
        int Poly[MAXSIZE];
        do{
                cin >> Poly[Nums++];
        }
        while(cin.get() != '\n');
        if(Nums == 2 && Poly[1] == 0)
        for(int i = 0; i < Nums; i++){
                if(i % 2 == 0)
                        Poly[i] *= Poly[i + 1];
                else
                        Poly[i]--;
        }
        for(int i = 0; i < Nums - 2; i++){
                if(Tag)
                        cout << " ";
                cout << Poly[i];
                Tag = 1;
        }
        if(Poly[Nums - 1] != -1)
                cout << " " << Poly[Nums - 2] << " " << Poly[Nums - 1];
        if(Nums == 2 && Poly[Nums - 1] == -1)
                cout << "0 0";
        return 0;
}

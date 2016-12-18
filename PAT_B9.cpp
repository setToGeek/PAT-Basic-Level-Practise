#include <iostream>
using namespace std;

typedef char WORD[80];
 int main(){
        WORD Word[80];
        int Tag = 0;
        int Ptr = 0;
        do{
                cin >> Word[Ptr++];
        }
        while(cin.get() != '\n');
        for(int i = Ptr - 1; i > -1; i--){
                if(Tag)
                        cout << " ";
                cout << Word[i];
                Tag = 1;
        }
}

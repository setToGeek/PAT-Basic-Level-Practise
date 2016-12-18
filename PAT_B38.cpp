#include <iostream>
using namespace std;

#define MAXSIZE 101

int main(){
        int NumOfPeople[MAXSIZE];
        int N, K, Tag = 0;
        for(int i = 0; i < MAXSIZE; i++){
                NumOfPeople[i] = 0;
        }
        cin >> N;
        for(int i  = 0; i < N; i++){
                int Tmp;
                cin >> Tmp;
                NumOfPeople[Tmp]++;
        }
        cin >> K;
        while(K--){
                int Tmp;
                cin >> Tmp;
                if(Tag)
                cout << " ";
                cout << NumOfPeople[Tmp];
                Tag = 1;
        }
        return 0;
}

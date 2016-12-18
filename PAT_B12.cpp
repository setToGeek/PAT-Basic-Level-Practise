#include <iostream>
#include <iomanip>
using namespace std;

int main(){
        int T, A[5], Tag[5], Flag = 0;
        int Coef = -1;
        for(int i = 0; i < 5; i++){
                A[i] = 0;
                Tag[i] = 0;
        }
        cin >> T;
        while(T--){
                int Input, Mod;
                cin >> Input;
                Mod = Input % 5;
                switch(Mod){
                        case 0:{
                                if(Input % 2 == 0){
                                        A[0] += Input;
                                        Tag[0] = 1;
                                }
                                break;
                        }
                        case 1:{
                                Tag[1] = 1;
                                Coef *= -1;
                                A[1] += Input * Coef;
                                break;
                        }
                        case 2:{
                                A[2]++;
                                Tag[2] = 1;
                                break;
                        }
                        case 3:{
                                A[3] += Input;
                                Tag[3]++;
                                break;
                        }
                        case 4:{
                                if(Input > A[4])
                                        A[4] = Input;
                                Tag[4] = 1;
                                break;
                        }
                }
        }
        float Modify = (float)A[3] / Tag[3];
        for(int i = 0; i < 5; i++){
                if(Flag)        cout << " ";
                if(!Tag[i]){
                        cout << 'N';
                        Flag = 1;
                        continue;
                }
                if(i == 3){
                        cout << setiosflags(ios::fixed) << setprecision(1) << Modify;
                }
                else
                        cout << A[i];
                Flag = 1;
        }
        return 0;
}

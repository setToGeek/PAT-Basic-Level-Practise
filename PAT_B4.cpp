#include <iostream>
#include <cstring>
using namespace std;

struct STUDENT{
        char Name[11];
        char Id[11];
        int Score;
        STUDENT operator=(STUDENT &Stu){
                strcpy(Name, Stu.Name);
                strcpy(Id, Stu.Id);
                Score = Stu.Score;
                return *this;
        }
};

int main(){
        int N;
        STUDENT MaxStu, MinStu, Tmp;
        MaxStu.Score =  0;
        MinStu.Score = 101;
        cin >> N;
        for(int i = 0; i < N; i++){
                cin >> Tmp.Name;
                cin >> Tmp.Id;
                cin >> Tmp.Score;
                if(Tmp.Score > MaxStu.Score){
                        MaxStu = Tmp;
                }
                if(Tmp.Score < MinStu.Score){
                        MinStu = Tmp;
                }
        }
        cout << MaxStu.Name << " " << MaxStu.Id << endl;
        cout << MinStu.Name << " " << MinStu.Id;
        return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

int main(){
        int T, Len, Tag, Test[3];
        string Str;
        cin >> T;
        while(T--){
                cin >> Str;
                Tag = 0;
                for(int i = 0; i < 3; i++){
                        Test[i] = 0;
                }
                Len = Str.size();
                int Ptr, PPos, TPos;
                Ptr = PPos = TPos = 0;
                for(; Ptr < Len; Ptr++){
                        if(Str[Ptr] == 'P'){
                                Test[0]++;
                                PPos = Ptr;
                                continue;
                        }
                        if(Str[Ptr] == 'A'){
                                Test[1]++;
                                continue;
                        }
                        if(Str[Ptr] == 'T'){
                                Test[2]++;
                                TPos = Ptr;
                                continue;
                        }
                                break;
                }
                if(Ptr == Len && Test[0] == 1 && Test[2] == 1 && Test[1] >= 1){
                        int Mid = TPos - PPos - 1;
                        int Left = PPos;
                        int Right = Len - 1 - TPos;
                        if(Mid == 1 && Left == Right)   Tag = 1;
                        if(Mid >=2 && Right == Mid * Left) Tag = 1;
                }
                if(Tag)
                        cout << "YES" << endl;
                else
                        cout << "NO" <<endl;
        }
        return 0;
}

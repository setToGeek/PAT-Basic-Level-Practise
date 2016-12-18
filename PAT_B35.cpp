#include <iostream>
#include <cstring>
using namespace std;

void InsertSort(int SrcArr[], int n){
        int Tmp = SrcArr[n], i = 0;
        while(SrcArr[i] < Tmp)  {
                ++i;
        }
        for(int j = n; j > i; --j){
                SrcArr[j] = SrcArr[j - 1];
        }
        SrcArr[i] = Tmp;
}

void Merge(int SrcArr[], int StartIndex, int MidIndex, int EndIndex){
        int *TmpArr = new int[EndIndex - StartIndex + 1];
        int i = StartIndex, j = MidIndex + 1, k = 0;
        while(i <= MidIndex && j <= EndIndex){
                if(SrcArr[i] <= SrcArr[j])
                TmpArr[k++] = SrcArr[i++];
                else
                TmpArr[k++] = SrcArr[j++];
        }
        while(i <= MidIndex)
        TmpArr[k++] = SrcArr[i++];
        while(j <= EndIndex)
        TmpArr[k++] = SrcArr[j++];
        memcpy(SrcArr + StartIndex, TmpArr, (EndIndex - StartIndex + 1) * sizeof(int));
        delete []TmpArr;
}

void MergeSort(int SrcArr[], int n, int Length){
        int i = 0;
        for(; i + 2 * Length - 1 < n; i += 2 * Length)
        Merge(SrcArr, i, i + Length - 1, i + 2 * Length - 1);
        if(i + Length <= n - 1)
        Merge(SrcArr, i, i + Length - 1, n - 1);
}

int main(){
        int n;
        cin >> n;
        int *Data = new int[n];
        int *Dest = new int[n];
        int *TmpInsert = new int[n];
        for(int i = 0; i < n; ++i)  cin >> Data[i];
        for(int i = 0; i < n; ++i)  cin >> Dest[i];
        for(int i = 0; i < n; ++i){
                TmpInsert[i] = Data[i];
        }
        for(int i = 1; i < n; ++i){
                InsertSort(TmpInsert, i);
                if(!memcmp(Dest, TmpInsert, n * sizeof(int))){
                        cout << "Insertion Sort" << endl;
                        InsertSort(TmpInsert, ++i);
                        for(int j = 0; j < n; ++j)  {
                                if(j)
                                cout << " ";
                                cout << TmpInsert[j];
                        }
                        return 0;
                }
        }
        int Length = 1;
        for(; Length < n; Length *= 2){
                MergeSort(Data, n, Length);
                if(!memcmp(Dest, Data, n * sizeof(int))){
                        cout << "Merge Sort" << endl;
                        MergeSort(Data, n, 2 * Length);
                        for(int i = 0; i < n; ++i)  {
                                if(i)
                                cout << " ";
                                cout << Data[i];
                        }
                        return 0;
                }
        }
}

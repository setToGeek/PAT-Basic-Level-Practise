// 根据维基百科的定义：
//
// 插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
//
// 归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。
//
// 现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？
//
// 输入格式：
//
// 输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。
//
// 输出格式：
//
// 首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。

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

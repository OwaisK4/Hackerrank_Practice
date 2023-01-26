#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

template <class Container>
void PrintContainer(const Container& object){
    for (auto it = begin(object); it != end(object); it++){
        cout << *it << " ";
    }
    cout << "\n";
}

void Merge(int *array, int p, int q, int r){
    int N_L = q - p + 1;
    int N_R = r - q;
    int *L = new int[N_L];
    int *R = new int[N_R];
    for (int i=0; i<N_L; i++){
        L[i] = array[p + i];
    }
    for (int j=0; j<N_R; j++){
        R[j] = array[q + j + 1];
    }
    int i=0, j=0, k=p;
    while (i < N_L && j < N_R){
        if (L[i] <= R[j]){
            array[k] = L[i];
            i = i + 1;
        }
        else{
            array[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < N_L){
        array[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < N_R){
        array[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
    delete [] L;
    delete [] R;
}

void MergeSort(int *array, int p, int r){
    if (p >= r)
        return;
    int q = (p + r) / 2;
    MergeSort(array, p, q);
    MergeSort(array, q+1, r);
    Merge(array, p, q, r);
}

int main(){
    srand(time(0));
    int array[10] = {2,5,1,6,4,8,7,3,9,0};
    for (int i=0; i<10; i++){
        array[i] = rand() % 10;
    }
    MergeSort(array, 0, 10);
    PrintContainer<int [10]>(array);
    return 0;
}
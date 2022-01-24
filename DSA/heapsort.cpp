#include <iostream>
using namespace std;


void heapSort(int pq[], int n) {
    if(n<3){
        return;
    }
    for(int childIndex = 1 ; childIndex<n; childIndex++){
        int currentIndex = childIndex;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }
    int si = 0;
    for(int ei  = n-1;ei>0;ei--){
        int ans = pq[si];
        pq[si] = pq[ei];
        pq[ei] = ans;
        int pi = si;
        int ri = (2*pi)+2;
        int li = (2*pi)+1;
        while(li < ei){
            int lmin = pi;
            if(pq[li]<pq[lmin]){   
                lmin = li;
            }
            if(ri<ei&&pq[ri]<pq[lmin]){
                lmin = ri;
            }
            if(pi==lmin)
            break;
            int temp = pq[pi];
            pq[pi] = pq[lmin];
            pq[lmin]  = temp;
            pi = lmin;
            ri = (2*pi+2);
			li = (2*pi+1);
        }
    }

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}
class DynamicArray
{
private:
    int nIdx;
    int size;
    int *dArr;
public:
    // this the basic empty constructior
    DynamicArray(){
        int *Arr = new int[5];
        dArr = Arr;
        nIdx = 0;
        size = 5;
    }

    // the copy constructor for deep copying
    DynamicArray(DynamicArray& d){
        int *nArr = new int[d.size];
        for(int i = 0;i<d.size;i++){
            nArr[i]=d.dArr[i];
        }
        dArr = nArr;
        this->size = d.size;
        this->nIdx = d.nIdx;
    }
    
    //inserting elements in this array
    void add(int num){
        if(nIdx+1>size){
            /* ---logic---
            basically a new array is made with twice the size of 
            the array and all the elements of the earler array 
            are copied in the new array and the pointer now 
            points to the new array.
            */
            int *nArr = new int[size*2];
            for(int i = 0;i<size;i++){
                nArr[i]=dArr[i];
            }
            dArr=nArr;
            size*=2;            // updating the value of the size
            dArr[nIdx]=num;     //inserting the element finally
            this->nIdx++;
        }else{
            dArr[nIdx]=num;     //inserting the element normally
            this->nIdx++;
        }
    }

    //getting element
    int getElem(int idx){
        
        if(idx<nIdx){
            return dArr[idx];
        }else{
            return -1;
        }
    }
 
};

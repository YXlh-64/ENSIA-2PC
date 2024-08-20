#ifndef ORDEREDCOLLECTION_H
#define ORDEREDCOLLECTION_H
template <typename comparables> //a collection of comparables
class orderedCollection
{
public:
    orderedCollection(int M = 50)
    {
        size = 0;
        maxSize = M;
        arr = new comparables[maxSize];
    };
    bool isEmpty() const
    {
        return size == 0;
    };
    void MakeEmpty()
    {
        size = 0;
    };
    void insert(const comparables& value)
    {
        if(maxSize == size){
            maxSize *=2;
            comparables* newArray = new comparables[maxSize];
            for(int i=0; i<size; ++i)
                newArray[i] = arr[i];
            delete[] array;
            array = newArray;
        }
        if(size == 0)    
        {
            arr[size] = value;
            size++;
        }
        else{
            for(int i = 0 ; i < size ; i++){
                if(arr[i] <= value && arr[i+1] >= value){
                    for(int j = size ; j >i+1 ; j++){
                        arr[j] = arr[j-1];
                    } 
                    arr[i+1] = value;
                }
            }
        }
    };
    comparables remove(const comparables& to_be_removed)
    {
        /*
        if(!isEmpty()){
            int i=0;
            while(i<size && )
        }
        */
        comparables deleted;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == to_be_removed)
            {
                deleted = arr[i];
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                return deleted;
            }
        }
        return -1;
    };
    comparables& findMin(){
        if(!isEmpty())
            return arr[0];
        else throw out_of_range("The array is empty!")
    }
        
    comparables& findMin(){
        if(!isEmpty())
            return arr[size-1];
        else throw out_of_range("The array is empty!")
    }

private:
    int size;
    int maxSize;
    comparables *arr;
};

#endif
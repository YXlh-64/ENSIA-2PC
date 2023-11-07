#ifndef COLLECTION_H
#define COLLECTION_H
template <typename T>
class collection
{
public:
    collection(int M = 50)
    {
        size = 0;
        maxSize = M;
        arr = new T[maxSize];
    };
    bool isEmpty() const
    {
        return size == 0;
    };
    void MakeEmpty()
    {
        size = 0;
        delete[] arr;
        // optional: to avoid memory leaks
        arr = nullptr;
        arr = new T[maxSize];
    };
    void insert(T value)
    {
        arr[size] = value;
        size++;
    };
    T remove(T to_be_removed)
    {
        T deleted;
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
    bool contains(T value) const
    {
        // check if the array has the value to be searched for
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                return true;
            }
        }
        return false;
    };

private:
    int size;
    int maxSize;
    T *arr;
};

#endif
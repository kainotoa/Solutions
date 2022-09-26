template<typename T>
int merge(T* arr, int& left, int& mid,
    int& right, int inv)
{
    int const leftArrSize = mid - left + 1;
    int const rightArrSize = right - mid;

    T* leftArr = new T[leftArrSize];
    T* rightArr = new T[rightArrSize];


    for (int i = 0; i < leftArrSize; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightArrSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    int leftArrIdx = 0, rightArrIdx = 0;

    while (leftArrIdx < leftArrSize
        && rightArrIdx < rightArrSize) {
        if (leftArr[leftArrIdx]
            <= rightArr[rightArrIdx]) {
            arr[left]
                = leftArr[leftArrIdx];
            leftArrIdx++;
        }
        else {
            arr[left]
                = rightArr[rightArrIdx];
            rightArrIdx++;
            inv += leftArrSize - leftArrIdx;
        }
        left++;
    }

    while (leftArrIdx < leftArrSize) {
        arr[left]
            = leftArr[leftArrIdx];
        leftArrIdx++;
        left++;
    }

    while (rightArrIdx < rightArrSize) {
        arr[left]
            = rightArr[rightArrIdx];
        rightArrIdx++;
        left++;
    }
    delete[] leftArr;
    delete[] rightArr;

    return inv;
}

template<typename T>
int mergeSort(T* arr, int begin, int end)
{
    if (begin >= end)
        return 0;

    int inv = 0;
    auto mid = begin + (end - begin) / 2;
    inv = mergeSort(arr, begin, mid);
    inv += mergeSort(arr, mid + 1, end);
    inv =  merge(arr, begin, mid, end,inv);
    return inv;
}

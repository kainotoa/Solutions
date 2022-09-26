template<typename T>
void merge(T* arr, int& left, int& mid,
    int& right)
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
}

template<typename T>
void mergeSort(T* arr, int begin, int end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

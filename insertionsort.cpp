void insertionSort(long data[], size_t n) {
    for (size_t i = 1; i < n; i++) {
        long tmp = data[i];
        size_t j = i;
        while (j > 0 && tmp < data[j - 1]) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    }
}

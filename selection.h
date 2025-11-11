template<class T>
void swap(T &a, T &b) {
	T t = a; //creates temporary variable in order to swap values
	a = b; //puts second value into first variable
	b = t; //puts first value into second variable
}

template<class T>
void selectionsort(T data[], int n) {
	for(int i = 0, j, least; i < n-1; i++) {
		for(j = i+1, least = i; j < n; j++) {
			if(data[j] < data[least]) {
				least = j;
			}
		}
		swap(data[least], data[i]);
	}
}

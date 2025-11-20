// Julianna Petrelli
// Lab #5, ECE 2161-001
// The following code preforms a merge sort algorithm on a given data set. 

void merge(long array[], long first, long last);                 //merge function declaration

void mergesort(long data[], long first, long last) {             //mergesort function declaration and definition
	if (first < last) {
		long mid = (first + last)/2;
		mergesort(data, first, mid);                             //sorts through the first half of the data set
		mergesort(data, mid+1, last);                            //sorts through the second hald of the data set
		merge(data, first, last);
	}
	return;
}
void merge(long array[], long first, long last) {                //merge function definition
	long mid, i1, i2;
	mid = (first + last)/2;
	i1 = first;
	i2 = mid + 1;
	int k = first;
	int n1 = i2 - i1;
	int n2 = last - mid;
	long head[n1];
	long tail[n2];

	for (int i = 0; i < n1; i++) {                             
		head[i] = array[first + i];                              //loading values into subarray for first half
	}
	for (int j = 0; j < n2; j++) {
		tail[j] = array[mid + 1 + j];							 //loading values into subarray for second half
	}

	int i = 0;
	int j = 0;

	while (i < n1 && j < n2) {                                   //merge first and second half subarrays together
		if (head[i] <= tail[j]) {
			array[k] = head[i];
			i++;
		}
		else {
			array[k] = tail[j];
			j++;
		}
		k++;
	}
	while (i < n1) {                                             //copy remaining values into first half subarray
		array[k] = head[i];
		i++;
		k++;
	}
	while (j < n2) {                                             //copy remaining values into second half array
			array[k] = tail[j];
			j++;
			k++;
		}

	return;
}

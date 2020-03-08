void Swap(int *a, int *b)
{	       
	int t = *a; 
	*a = *b;
	*b = t;
}

void AdjustDown(int array[], int size, int r)
{
	int left = 2 * r + 1;
	int right = 2 * r + 2; 
	if (left >= size) 
		return;
	int m = left; 
	if (right < size && array[right] > array[left]) 
		m = right; 
	if (array[r] >= array[m]) 
		return;
	Swap(array + r, array + m);
	AdjustDown(array, size, m);
}


// 建堆
void CreateHeap(int array[], int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(array, size, i);
}


// 排序
void HeapSort(int array[], int size)
{
	CreateHeap(array, size);
	for (int i = 0; i < size; i++)
	{
		Swap(array, array + size - 1 - i);
		AdjustDown(array, size - 1 - i, 0);
	}
}


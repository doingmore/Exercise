#ifndef ALGORITHMS_H
#define ALGORITHMS_H

void print(int* data, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << ' ';
	}
	std::cout << '\n';
}

void swap(int& left, int& right)
{
	int temp{ left };
	left = right;
	right = temp;
}

void insertionAlg(int* data, const int& size)
{
	for (int i = 1; i < size; i++) 
	{
		//print(data, size);
		int key = data[i];
		int internalCounter = i - 1;

		while (internalCounter >= 0 && key < data[internalCounter] )
		{
			data[internalCounter + 1] = data[internalCounter];
			internalCounter--;
		}
		data[internalCounter + 1] = key;
	}
}

void selectionAlg(int* data, const int& size)
{
	for (int i = 0; i < size-1; i++)
	{
		int minIndex{ i };
		for (int k = i+1; k < size; k++)
		{
			if (data[minIndex] > data[k])
			{
				minIndex = k;
			}
		}
		if (minIndex != i)
		{
			swap(data[i], data[minIndex]);
		}
		print(data, size);
	}
}

void bubbleSort(int* data, const int& size)
{
	bool flagSwap = true;
	for (int i = 0; i < size; i++)
	{
		flagSwap = true;
		for (int k = 0; k < size - i - 1; k++)
		{
			if (data[k] > data[k+1])
			{
				swap(data[k], data[k+1]);
				//print(data, size);
				flagSwap = false;
			}
		}
		if (flagSwap)
		{
			break;
		}
	}
}

void merge(int data[], int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (data[i] < data[j])
        {
            c[k] = data[i];
            k++;
            i++;
        }
        else
        {
            c[k] = data[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = data[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = data[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        data[i] = c[i];
    }
}


void mergeSort(int* data,const int& begin, const int& end)
{
    if (begin < end)
    {
        int mid{ (begin + end) / 2 };


        mergeSort(data, begin, mid);
        mergeSort(data, mid + 1, end);

        merge(data,begin,end,mid);
    }
}

#endif // !ALGORITHMS_H

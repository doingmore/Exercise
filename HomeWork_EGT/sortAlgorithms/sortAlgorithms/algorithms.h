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
	for (int i = 0; i < size; i++)
	{
		//print(data, size);
		int min{ i }; 
		for (int k = i+1; k < size; k++)
		{
			if (data[min] > data[k])
			{
				min = k;
			}
		}
		swap(data[i], data[min]);
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


#endif // !ALGORITHMS_H

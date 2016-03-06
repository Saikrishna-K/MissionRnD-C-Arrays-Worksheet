/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len < 1) return NULL;

	

	int mIndex=0, sIndex = 0, eIndex = len, index = eIndex / 2, i;
	Arr = (int *) realloc(Arr, sizeof(int)*len);
	
	// if the element to insert is at first position
	if (Arr[0] > num && len>=1)
	{
		num += Arr[0];
		Arr[0] = num - Arr[0];
		num = num - Arr[0];
		mIndex = 0;
	}
	
	else
	{
		//finding the index value to insert the new element using binary search technique 
		while (sIndex <= eIndex)
		{
			if ((Arr[index] <= num && Arr[index + 1] >= num) || index == len - 1 )
			{
				mIndex = index; break;

			}

			else if (Arr[index] <= num)
			{
				sIndex = index + 1;
				index = (sIndex + eIndex) / 2;


			}
			else if (Arr[index] >= num)
			{
				eIndex = index - 1;
				index = (sIndex + eIndex) / 2;
			}


		}
	}

	

	len++;
        if (len!=1)
	for (i = len - 1; i > mIndex; i--)
	{
		Arr[i] = Arr[i - 1];

	}
	Arr[i+1] = num;

  return Arr;

}
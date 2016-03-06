/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
if (Arr == NULL || len < 1) return NULL;

	int i,index1=-1,index2=-1;
	for (i = 1; i < len; i++){

		if (Arr[i - 1] > Arr[i])
		{
			index1 = i-1 ; break;
		}


	}
	if (index1 == -1) return Arr;
	if (index1 == (len - 2)) index2 = len - 1;
	else{
		  for (i = i; i < len - 1; i++)
		  {
			if (Arr[i]> Arr[i + 1])
			{
				index2 = i + 1;
			}
		  }
	}
	if (index2 == -1) index2 = 1;
	Arr[index1] = Arr[index1] + Arr[index2];
	Arr[index2] = Arr[index1] - Arr[index2];
	Arr[index1] = Arr[index1] - Arr[index2];
	
	return Arr;
}
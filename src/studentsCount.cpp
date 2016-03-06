#include<stdio.h>
#include<stdlib.h>
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/



void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {

	if (Arr == NULL || score <0 || len <1) return NULL;
	*lessCount = 0, *moreCount = 0;
	if (len != 1){
		int sIndex = 0, eIndex = len - 1;
		int index = (len - 1) / 2;


// To find the highest index of the less values for a given number in  a given array,using BinarySearch.

		while (sIndex <= eIndex)
		{

			if (Arr[index] >= score && Arr[index - 1] < score)
			{

				(*lessCount) = index;
				break;
			}
			else if (Arr[index] <= score){
				sIndex = index + 1;
				index = (sIndex + eIndex) / 2;
			}
			else if (Arr[index] >= score){
				eIndex = index - 1;
				index = (sIndex + eIndex) / 2;

			}
		}


	

		sIndex = index, eIndex = len - 1;
		index = (sIndex + eIndex) / 2;

// To find the least Index value of the greatest values than the given number in a given array, using Binary Search.

		while (sIndex <= eIndex)
		{

			if (Arr[index - 1] <= score && Arr[index] > score)
			{

				(*moreCount) = len - index;
				break;
			}
			else if (Arr[index] <= score){
				sIndex = index + 1;
				index = (sIndex + eIndex) / 2;
			}
			else if (Arr[index] >= score){
				eIndex = index - 1;
				index = (sIndex + eIndex) / 2;

			}
		}
	}


	else if (Arr[0] > score)
	{
		
		(*moreCount)++;
		printf("%d ", *moreCount);
	}
	else if (Arr[0]<score)
		(*lessCount)++;



	return Arr;




}

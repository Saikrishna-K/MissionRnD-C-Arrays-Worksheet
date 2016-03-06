/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};


//Sorting using quickSort in descending order
void Sort(struct student *arr, int left, int right)
{

	struct student pivot = arr[right];
	int  leftIndex = left, rightIndex = right;

	while (leftIndex<rightIndex){
		while (arr[leftIndex].score > pivot.score && leftIndex < rightIndex){ leftIndex++; }
		if (leftIndex != rightIndex)  arr[rightIndex] = arr[leftIndex];

		while (arr[rightIndex].score <= pivot.score && leftIndex < rightIndex){ rightIndex--; }
		if (leftIndex != rightIndex) arr[leftIndex] = arr[rightIndex];

	}

	arr[leftIndex] = pivot;

	int	pivotIndex = leftIndex;
	if (left<pivotIndex)
		Sort(arr, left, pivotIndex - 1);
	if (pivotIndex<right)
		Sort(arr, pivotIndex + 1, right);

}


void * scoresDescendingSort(struct student *students, int len) {

	if (students == NULL || len < 1) return NULL;

	else
	{
		Sort(students, 0, len - 1);
	}

	return students ;
}
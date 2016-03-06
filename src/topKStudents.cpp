/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};


int quickSortKthelement(struct student *arr, int leftIndex, int rightIndex)
{
	struct student pivot = arr[rightIndex];

	while (leftIndex<rightIndex){
		while (arr[leftIndex].score > pivot.score && leftIndex < rightIndex){ leftIndex++; }
		if (leftIndex != rightIndex)  arr[rightIndex] = arr[leftIndex];
		
		while (arr[rightIndex].score <= pivot.score && leftIndex < rightIndex){ rightIndex--; }
		if (leftIndex != rightIndex) arr[leftIndex] = arr[rightIndex];
		
	}

	arr[leftIndex] = pivot;

	return leftIndex;

}

void kthStudent(struct student *arr, int left, int right, int K)
{
	if (left < right){
		int pivot = quickSortKthelement(arr, left, right);

		//if the Index values matches with the pivot+1 value then
		//we have sorted the left side of the pivot with K top student marks ,but not in a specific (ascending or Descending).
		if (K == pivot + 1) return;


		else if (pivot < K) { kthStudent(arr, pivot + 1, right, K); }
		else if (pivot >K)  { kthStudent(arr, left, pivot - 1, K); }
	}

}



struct student ** topKStudents(struct student *students, int len, int K) {
	struct student **null = NULL;
	if (students == NULL || len < 1 || K<1) return null;
	int i;
	if (K<len)
		kthStudent(students, 0, len - 1, K);
	else{ K = len; }

	struct student **topstudents = (struct student**)calloc(K, sizeof(struct student*));
	for (i = 0; i < K; i++)
	{
		topstudents[i] = (struct student*)calloc(1, sizeof(struct student));

	}

	for (i = 0; i < K; i++)
	{
		*(topstudents[i]) = students[i];

	}

	return topstudents;
}


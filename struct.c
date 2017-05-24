# include <stdio.h>
# include <stdlib.h>

int main()
{
	typedef struct student
	{
		int age;
		char* name;
	}student;

	student* ptr = malloc(sizeof(student));

	/* ptr = {3, "OLA"};  */
	
	(*ptr).age  = 4;

	printf ("%d", (*ptr).age);

	ptr -> age = 10;
	printf ("\n%d\n", ptr -> age);
	

	/*
	int fick = 10;

	int* lol = malloc (sizeof(int));

	*lol = 100;

	printf ("%d", *lol);
	*/

	return 0;
}


/*	~ int 

	struct
	{
		int age;
		char* name;
	};
--------------------------------

	~ int student;
	struct
	{
		int age;
		char* name;
	}student;	
--------------------------------

	~ give a name to the structure 
	struct student
	{
		int age;
		char* name;
	}s1;

	struct student s2; 
-----------------------------------

	typedef struct student
	{
		int age;
		char* name;
	}student;


*/



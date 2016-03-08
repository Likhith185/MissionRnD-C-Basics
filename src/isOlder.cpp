/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	return 0;
}

int checkValidity(int a, int b, int c)
{
	if (b == 0 || b > 12)
		return 0;

	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (b == 2 && isLeap(c))
		arr[1]++;
	if (a <= arr[b - 1])
		return 1;
	return 0;
}

int length(char * str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

int isOlder(char *dob1, char *dob2) 
{
	if (length(dob1) != 10 || length(dob2) != 10)
		return -1;
	int dd1, mm1, yy1, dd2, mm2, yy2;
	dd1 = dob1[0] * 10 + dob1[1]- 11 * '0';
	mm1 = dob1[3] * 10 + dob1[4]- 11 * '0';
	yy1 = dob1[6] * 1000 + dob1[7] * 100 + dob1[8] * 10 + dob1[9] - 1111 * '0';
	dd2 = dob2[0] * 10 + dob2[1] - 11 * '0';
	mm2 = dob2[3] * 10 + dob2[4] - 11 * '0';
	yy2 = dob2[6] * 1000 + dob2[7] * 100 + dob2[8] * 10 + dob2[9] - 1111 * '0';

	if (checkValidity(dd1, mm1, yy1) != 1 || checkValidity(dd2, mm2, yy2) != 1)
		return -1;
	
	if (yy1 > yy2)
		return 2;
	else if (yy1 < yy2)
		return 1;
	else
	{
		if (mm1 > mm2)
			return 2;
		else if (mm1<mm2)
			return 1;
		else
		{
			if (dd1 > dd2)
				return 2;
			else if (dd1 < dd2)
				return 1;
			else
				return 0;
		}
	}
}

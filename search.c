#include <stdio.h>
#include "phone.h"

extern struct Contact PhoneBook[MAX];
extern int size;

void searchByName(void)
{
	char name_buffer[256];
	printf(">> Enter a name to search : ");
	scanf("%s", name_buffer);
	int i, j, check;
	for(i = 0; i < size; i++)
	{
		check = 1;
		for(j = 0; name_buffer[j] != 0 && PhoneBook[i].Name[j] != 0; j++)
			check &= (name_buffer[j] == PhoneBook[i].Name[j]);
		check &= (name_buffer[j] == 0 && PhoneBook[i].Name[j] == 0);
		if(check)
		{
			printf("%s\t%s\n", PhoneBook[i].Name, PhoneBook[i].PhoneNumber);
			return;
		}
	}
	printf("Oops, %s is not in the PhoneBook.\n", name_buffer);
}

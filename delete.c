#include <stdio.h>
#include "phone.h"
extern struct Contact PhoneBook[MAX];
extern int size;
void deleteByName(void)
{
	char name_buffer[256];
	int i, j, check;
	printf(">> Enter a name to delete : ");
	scanf("%s", name_buffer);
	for(i = 0; i < size; i++)
	{
		check = 1;
		for(j = 0; name_buffer[j] != 0 && PhoneBook[i].Name[j] != 0; j++)
			check &= name_buffer[j] == PhoneBook[i].Name[j];
		check &= (name_buffer[j] == 0 && PhoneBook[i].Name[j] == 0);
		if(check)
		{
			int k;
			for(j = i; j < size - 1; j++)
			{
				for(k = 0; PhoneBook[j + 1].Name[k] != 0; k++)
					PhoneBook[j].Name[k] = PhoneBook[j + 1].Name[k];
				PhoneBook[j].Name[k] = 0;
				for(k = 0; PhoneBook[j + 1].PhoneNumber[k] != 0; k++)
					PhoneBook[j].PhoneNumber[k] = PhoneBook[j + 1].PhoneNumber[k];
				PhoneBook[j].PhoneNumber[k] = 0;
			}
			size--;
			printf("%s is deleted.\n", name_buffer);
			return;
		}
	}
	printf("Oops, %s is not in the PhoneBook.\n", name_buffer);
}

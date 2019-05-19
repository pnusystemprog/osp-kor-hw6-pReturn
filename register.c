#include <stdio.h>
#include "phone.h"

extern char* init_password;
extern struct Contact PhoneBook[MAX];
extern int size;
static char* not_matched[3] = 
{
	"",
	"(twice)",
	"(3 times)"
};

void registerPhoneData(void)
{
	int failed_times = 0;
	while(1)
	{
		int i, check = 1;
		char password_buffer[256];
		printf("Password : ");
		scanf("%s", password_buffer);
		for(i = 0; password_buffer[i] != 0 && init_password[i] != 0; i++)
			check &= password_buffer[i] == init_password[i];
		check &= (password_buffer[i] == 0 && init_password[i] == 0);
		if(check)
			break;
		else
		{
			if(failed_times > 2)
			{
				printf(">> You are not allowed to access PhoneBook.\n");
				return;
			}
			else
			{
				printf(">> Not Matched %s !!!\n", not_matched[failed_times++]);
			}
		}
	}
	char username_buffer[256];
	char phonenumber_buffer[256];
	printf("New User Name : ");
	scanf("%s", username_buffer);
	printf("PhoneNumber : ");
	scanf("%s", phonenumber_buffer);
	int i;
	for(i = 0; username_buffer[i] != 0; i++)
		PhoneBook[size].Name[i] = username_buffer[i];
	PhoneBook[size].Name[i] = 0;
	for(i = 0; phonenumber_buffer[i] != 0; i++)
		PhoneBook[size].PhoneNumber[i] = phonenumber_buffer[i];
	PhoneBook[size].PhoneNumber[i] = 0;
	size++;
	printf("Registered\n");
}

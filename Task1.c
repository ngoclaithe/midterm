#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Address
{
	char name[100];
	char email[100];
	char phone[100];
};


void chuanHoa(char * s)
{
	while(s[0] == '\n') strcpy(&s[0],&s[1]);
	while(s[strlen(s)-1] == '\n') strcpy(&s[strlen(s)-1],&s[strlen(s)]);
}


void sort(struct Address address[], int size)
{
	int i,j;
	for (i = 0; i < size; i++)
	{
		for (i = 0; i < size; i++)
		{
			if (strcmp(address[i].name,address[j].name) < 0){
				struct Address temp;
				temp = address[i];
				address[i] = address[j];
				address[j] = temp;
			}
		}
	}
}

void print(struct Address address[], int size)
{
    int i,j;
	for (i = 0; i < size; i++)
	{
		printf("\n%s %s %s",address[i].name,address[i].email,address[i].phone);
	}	
}

void menu(char * filename)
{
	int select = 0;
	do{
		printf("\n_________________________ MENU _____________________________");
	    printf("\n1.Implement this program using an array of structure.");
	    printf("\n2.Implement this program using a singly-linked list or a doublylinked list.");
	    printf("\n3.Implement this program using queue.");
	    printf("\n4.Read address data from the standard input, and add them to the queue.");
		printf("\n select:");
		scanf("%d",&select);
		switch(select){
			case 1:{
				struct Address address[SIZE];
                int size = 0;
	            FILE * fp = fopen(filename, "r");
	            while(!feof(fp))
	            {
		           char s[256];
		           fgets(s,sizeof(s),fp);
		           chuanHoa(s);	
		           char * token1, * token2, * token3;
		           token1 = strtok(s," ");
		           token2 = strtok(NULL," ");
		           token3 = strtok(NULL," ");
		           strcpy(address[size].name,token1);
		           strcpy(address[size].email,token2);
		           strcpy(address[size].phone,token3);
		           size ++;
				}
				fclose(fp);
	            sort(address,size);
	            print(address,size);
				break;
			}
			case 2:{
				
				break;
			}
			case 3:{
				struct Address address[SIZE];
                int size = 0;
	            FILE * fp = fopen(filename, "r");
	            while(!feof(fp))
	            {
		           char s[256];
		           fgets(s,sizeof(s),fp);
		           chuanHoa(s);	
		           char * token1, * token2, * token3;
		           token1 = strtok(s," ");
		           token2 = strtok(NULL," ");
		           token3 = strtok(NULL," ");
		           if (size == 0){
		           	   strcpy(address[size].name,token1);
		               strcpy(address[size].email,token2);
		               strcpy(address[size].phone,token3);
		               size ++;
				   }
				   else{
				   	   int i;
				   	   size ++;
				   	   for (i = size; i >= 1; i--){
				   	   	   address[i] = address[i-1];
					   }
					   strcpy(address[0].name,token1);
		               strcpy(address[0].email,token2);
		               strcpy(address[0].phone,token3);  
				   }
				}
				fclose(fp);
				//sort(address,size);
				print(address,size);
				break;
			}
			case 4:{
				
				break;
			}
		}
	}while(select >= 1 || select <= 4);
}

int main()
{
	menu("data.txt");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[] = "22233344455566677778889999";
char str[80], telNumbers[100000][9];

int compare(const void *elem1,const void *elem2) {
	//Define a comparison function for array elements for function template sort
	return (strcmp((char*)elem1, (char*)elem2));
};

void standardizeTel(int n) {
	int j, k;
	j = k = -1 ;
	while ( k<8 ) {
		j++;
		if ( str[j] == '-' )
			continue;
		k++;
		if (k==3) {
			telNumbers[n][k]='-';
			k++;
		}
		if(str[j]>='A' && str[j]<='Z') {
			telNumbers[n][k]=map[str[j]-'A'];
			continue;
		}
		telNumbers[n][k]=str[j];
	}
	telNumbers[n][k]='\0';
	return;
}

void main()
{
	int n,i,j;
	bool noduplicate;

	scanf("%d",&n);
	for(i=0;i<n;i++){//Enter the phone number and store it in the array telNumbers
		scanf("%s",str);
		standardizeTel(i); //Convert the phone number in str to standard form, stored in line il of telNumbers
	}
	qsort(telNumbers,n,9,compare);//Sort the entered phone number
	noduplicate = true;
	i=0;
	while(i<n){//Search for duplicate phone numbers and output
		j=i;
		i++;
		while(i<n&&strcmp(telNumbers[i], telNumbers[j])==0) i++;
		if(i-j>1) {
			printf("%s %d\n", telNumbers[j], i-j);
			noduplicate = false;
		}
	}
	if ( noduplicate ) {
		printf("No duplicates.\n");
	}
}


//I [HUU NGOC CHINH CAO] ([4529434]) affirm that this
//program is entirely my own work and that I have neither developed my code together with any
//another person, nor copied any code from any other person, nor permitted my code to be copied
//or otherwise used by any other person, nor have I copied, modified, or otherwise used programs
//created by others. I acknowledge that any violation of the above terms will be treated as academic
//dishonesty


#include <stdkeyLetter.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//Main function
int main(int argc, char **argv)
{
	//Initiate and take file name
	FILE *ifp = NULL;
	FILE *ifp2 = NULL;
	char FileName[7], FileName2[7];
	
	//variable used for function
	int i, n = 0, a = 0, b = 0, k=0;
	
	//Numberber of string
	int Number_string = 0, Number_string2 = 0;
	
	// Max char in text file
	char buffer[513], key[513];
	char *Letter, *Letter2;
	char Number[9], Number2[9];
	char x[513][513], y[513][513];
	char keyLetter[513],op[513], enncrypted[513];
	int q=0, w=0;
	
	strcpy(FileName, argv[1]);
	strcpy(FileName2, argv[2]);

//Exit if no filename
	if ((ifp = fopen(FileName, "r")) == NULL || (ifp2 = fopen(FileName2, "r")) == NULL )
	{
		exit(0);
	}
	
//Scan through every letter in text file and store in key
	while (fscanf(ifp, "%s", key) != EOF)
	{
		Letter = malloc(sizeof(char) * (strlen(key) + 1));
		strcpy(Letter, key);
		for(i = 0; i < (strlen(key) + 1); i++)
		{
			Letter[i] = tolower(Letter[i]);
			if (isalpha(Letter[i]))
				x[a][i] = Letter[i];
			else;
		}
		Number2[a] = strlen(key);
		a++;
		Number_string++;
	}
	
//Scan through and store in buffer
	while (fscanf(ifp2, "%s", buffer) != EOF)
	{
		Letter2 = malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy(Letter2, buffer);
		for(i = 0; i < (strlen(buffer) + 1); i++)
		{
			Letter2[i] = tolower(Letter2[i]);
			if (isalpha(Letter2[i]))
				y[b][i] = Letter2[i];
			else;
		}
		Number[b] = strlen(buffer);
		b++;
		Number_string2++;
	}
	
//Print key
	printf("\n\n\nVigenere Key:\n\n");
	for (a = 0; a < Number_string; a++)
	{
		for (i = 0; i < 512; i++)
		{
			if (isalNumber(x[a][i]))
			{
			keyLetter[q] = x[a][i];
			q++;
			if ( q >= 512)
				q = 512;
			}
		else;
		}
	}
	for (i = 0; i < q; i++)
	{
		if ( (i%80) == 0 && i !=0)
			printf("\n");
		printf("%c", keyLetter[i]);
	}
	
//Print plain text	
	printf("\n\n\nPlaintext:\n\n");
	for (b = 0; b < Number_string2; b++)
	{
		for (i = 0; i < 512; i++)
		{
			if (isalNumber(y[b][i]))
			{
				op[w] = y[b][i];
				w++;
			}
			else;
			if (w >= 512)
				w = 512;
		}
	}

	for (i = 0; i < w; i++)
	{
		if ( (i%80) == 0 && i !=0)
			printf("\n");
		printf("%c", op[i]);
	}
	for (i = w; i < 512; i++)
	{
		if ( (i%80) == 0 && i !=0)
			printf("\n");
		op[i] = 'x';
		printf("%c", op[i]);
	}
	
//Print encrypted text
	printf("\n\n\nCiphertext:\n\n");

	for (i = 0; i < 512; i++)
	{
		
		if (k >= strlen(keyLetter))
			k = 0;
		keyLetter[k] -= 97;
		op[i] -= 97;
		enncrypted[i] = op[i]  + keyLetter[k];
		if (enncrypted[i] > 25)
			enncrypted[i] -=26;
		keyLetter[k] +=97;
		op[i] +=97;
		enncrypted[i] += 97;
		if ((i%80) == 0 && i!= 0)
			printf("\n");
		printf("%c", enncrypted[i]);
		k++;
	}
	
//End of file, close text file
printf ("\n");
	fclose(ifp);
	fclose(ifp2);
	ifp = NULL;
	ifp2 = NULL;
	
    return 0;
}


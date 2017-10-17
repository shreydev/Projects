#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_WORD_SIZE 34


void removeDuplicate(char sorted[MAX_ROW][MAX_COL], int count)
{
  char temp[MAX_ROW][MAX_COL];
  int temp_count=0, detection = 0;
  for (int p = 0;  p < count; p++)
    {
      for (int k = 0; k < temp_count; k++)
	{
	  if(strcmp(sorted[p], temp[k]) == 0)
	    detection = 1;
	}
      if(detection == 0)
	{
	  for(int i = 0; i < strlen(sorted[p]); i++)
	    {
	      temp[temp_count][i] = sorted[p][i];
	    }
	  temp_count++;
	}
      detection = 0;
    }
  
  for(int k = 0; k < MAX_ROW; k++)
    {
      for(int i = 0; i < MAX_COL; i++)
	{
	  sorted[k][i] = '\0';
	}
    }
  
    for(int k = 0; k < MAX_ROW; k++)
    {
      for(int i = 0; i < MAX_COL; i++)
	{
	  sorted[k][i] = temp[k][i];
	}
    }
  count = temp_count;
  
}



int main(int argc, char *argv[])
{

  int partDecider = 0, fileIndicator = 0;

  if (argc == 3)
    {
      if (!strcmp(argv[1], "--infile"))
	{
	  partDecider = 1;
	  fileIndicator = 2;
	}
      else
	{
	  printf("\n\n");
	  printf("Please check the argument");
	  printf("\n\n");
	  return 0;
	}
    }

  else if(argc == 4)
    {
      if ((!strcmp(argv[1], "--sort")) && (!strcmp(argv[2], "--infile")))
	{
	  partDecider = 2;
	  fileIndicator = 3;
	}
      else
	{
	  printf("\n\n");
	  printf("Please check the argument");
	  printf("\n\n");
	  return 0;
	}
    }

  else if (argc == 5)
    {
      if ((!strcmp(argv[1], "--sort")) && (!strcmp(argv[2], "--print-words")) && (!strcmp(argv[3], "--infile")))
	{
	  partDecider = 3;
	  fileIndicator = 4;
	}
      else
	{
	  printf("\n\n");
	  printf("Please check the argument");
	  printf("\n\n");
	  return 0;
	}
    }
  else
    {
      printf("\n\n");
      printf("Please enter correct command");
      printf("\n\n");
      return 0;
    }


  FILE * filp;
  
  if(argc == 3)
    {
      filp = fopen(argv[fileIndicator], "r");
      if(filp == NULL)
	printf("File not found\n");
    }
  if(argc == 4)
    {
      filp = fopen(argv[fileIndicator], "r");
      if(filp == NULL)
	printf("File not found\n");
    }
  if(argc == 5)
    {
      filp = fopen(argv[fileIndicator], "r");
      if(filp == NULL)
	printf("File not found\n");
    }
  char sorted[MAX_ROW][MAX_COL];
  int row, count, col = 0;
  char file[MAX_COL], c;
  
  
  
  
  /********************************
   ********************************
   ***********PART 1***************
   ********************************
   ********************************/

  while((c = fgetc(filp)) != EOF)
    {
      file[col]=c;
      col++;
    }
      
  file[--col]='\0';
  col = 0;
  char* word = strtok(file, " ,.;()\n");
  while(word != NULL)
    {
      count++;
      strcpy(sorted[row], word);
      word=strtok(NULL, " ,.;()\n");
      row++;
    }
  
  
  //sort the words in the given string */
  char temp[256];
  for (int i=0; i < count; i++)
    {
      strcpy(temp,sorted[i]);
      for  (int j =i+1; j < count; j++)
	{
	  if(strlen(sorted[i]) > strlen(sorted[j]))
	    {
	      strcpy(temp,sorted[i]);
	      strcpy(sorted[i], sorted[j]);
	      strcpy(sorted[j], temp);
	    }
	}
    }  
  
  
  /*//printf("%d",count);
    for(row=0;row<count;row++)
    {
    int n=strlen(sorted[row]);
    printf("%d\n", n);
    printf("%s\n",sorted[row]);
    
    }*/
  
  
  //Create Index Array
  int final_index[MAX_COL][MAX_ROW];
  int length_final_index = 0;
  
  row =0;
  col = 0;
  final_index[row][col] = strlen(sorted[0]);
  //printf("%d", final_index[col]);  
  length_final_index = col + 1;
  
  for(int i=1; i < count; i++)
    {
      if(final_index[row][col] != strlen(sorted[i]))
	{
	  col++;
	  final_index[row][col] = strlen(sorted[i]);
	  length_final_index = col + 1;
	}
    }
  
  //completing upper array ith frequencies of each
  col = 0; 
  int i =0;
  
  while(i < length_final_index)
    {
      row =0;
      int n = final_index[row][col];
      int repetation = 0;
      for(int j = 0; j<count; j++)
	{
	  if (strlen(sorted[j]) == n)
	    repetation++;
	}
      row=1;
      final_index[row][col]=repetation;
      col++;
      i++;
    }
  
  row = 1;
  
  if (partDecider == 1)
    {
      printf("\n\n");
      //final printing process for part A
      for(int p = 0; p < length_final_index; p++)
	{
	  printf("Count[%02d]=%02d;\n", final_index[0][p], final_index[1][p]);
	}
      printf("\n\n");
      return 0;
    } 
  
  /********************************
   ********************************
   ***********PART 2***************
   ********************************
   ********************************/
  
  if(partDecider == 2 || partDecider == 3)
    {
      int a,b;
      
      for (int p = 0; p < length_final_index; p++)
	{
	  for (int j = p + 1; j < length_final_index; j++)
	    {
	      if (final_index[1][p] < final_index[1][j])
		{
		  a = final_index[1][p];
		  b = final_index[0][p];
		  final_index[1][p] = final_index[1][j];
		  final_index[0][p] = final_index[0][j];
		  final_index[1][j] = a;
		  final_index[0][j] = b;
		}
	    }
	}
      
      if(partDecider == 2)
	{
	  printf("\n\n");
	  for(int p = 0; p < length_final_index; p++)
	    {
	      printf("Count[%02d]=%02d;\n", final_index[0][p], final_index[1][p]);
	    }
	  printf("\n\n");
	  return 0;
	}

    }
  
  /********************************
   ********************************
   ***********PART 3***************
   ********************************
   ********************************/
  
      if(partDecider == 3)
	{
	  //loop to make the whole array in lower case
	  for (int j = 0; j < count; j++)
	    {
	      for(int k = 0; k < (strlen(sorted[j])); k++)
		{
		  sorted[j][k]= tolower(sorted[j][k]);
		}
	    }
	  
	  //delete repeating string
	  
	  removeDuplicate(sorted, count); 
	  
	  //Print final result
	  int freq, count_freq, and_indicator=0;  
	  
	  printf("\n\n");
	  for (int p = 0; p < length_final_index; p++)
	    {
	      printf("Count[%02d]=%02d; (words: ", final_index[0][p], final_index[1][p]);
	      freq = final_index [0][p];
	      count_freq=0;
	      and_indicator = 0;
	      for(int j = 0; j < count; j++)
		{	  
		  j=j+1;
		  if(count_freq > 0 && strlen(sorted[j]) != freq)
		    {
		      printf(" and ");
		      count_freq = 0;
		      and_indicator = 1;
		    }
		  j=j-1;
		  if(count_freq > 0 && strlen(sorted[j]) == freq && and_indicator != 1)
		    {
		      printf(", ");
		    }
		  if ( strlen(sorted[j]) == freq)
		    {
		      printf("\"%s\"", sorted[j]);
		      count_freq++;
		    }
		  j=j+1;
		  if(count_freq > 0 && strlen(sorted[j]) != freq)
		    {
		      count_freq = 0;
		    }
		  j=j-1;
		}
	      printf(")\n");
	    }
	}
      printf("\n\n");
      return 0;
}

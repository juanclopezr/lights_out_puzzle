#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int unsigned inv[64][64];
  FILE * fp;

  fp =fopen ("inverse.dat", "r");
  rewind(fp);
  for(int i=63;i>=0;i--)
    {
      for(int j=63;j>=0;j--)
	{
	  int temp;
	  fscanf(fp,"%i",&temp);
	  inv[i][j] = temp;
	}
    }
  int unsigned pattern[64];
  int unsigned solution[64];
  time_t t;
  srand((unsigned) time(&t));
  for(int i=0;i<64;i++)
    {
      pattern[i]=rand() % 2;
    }
  for(int i=0;i<64;i++)
    {
      int unsigned temp=0;
      for(int j=0;j<64;j++)
	{
	  temp = temp^(inv[i][j]&pattern[j]);
	}
      solution[i]=temp;
      printf("%u,%u\n",pattern[i],temp);
    }
}

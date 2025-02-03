#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fp, *fp1; int i, a, b; i = 1500;
if ((fp = fopen("binary", "wb")) == NULL)
{
printf("the binary file couldnt open\n"); exit(1);
}
if ((fp1 = fopen("txt", "w")) == NULL)
{
printf("the txt file couldnt open\n"); exit(2);
}
fprintf(fp1, "%d", i); if (fwrite(&i, sizeof(int), 1, fp) != 1)
{
printf("write error occured\n"); exit(3);
}
fclose(fp); fclose(fp1);
if ((fp = fopen("binary", "rb")) == NULL)
{
printf("the binary file couldnt open\n"); exit(4);
}
if ((fp1 = fopen("txt", "r")) == NULL)
{
printf("the txt file couldnt open\n"); exit(5);
}
if (fread(&a, sizeof(int), 1, fp) != 1)
{
printf("write error occured\n"); exit(6);
}
fscanf(fp1, "%d", &b);
printf("a is %d and b is %d", a, b);
fclose(fp);
fclose(fp1);
system("pause");
return 0;

// this file will take a document for which you want some similar documents 
// code starts here 

#include<stdio.h>
#include<string.h>
int main()
{
FILE *fp;
int stopwordlen; // total stop words
int maxwordlen;
int j,k,l,i,check,len;
char ch;
char stop[120][120];
char temp[120];
char upload[1000][100]; // This list is used to keep all words that are occuring frequently
j=0;
// this part will keep a list  of the stop words that we will keep a track in a document as not to process them 
fp=fopen("stopwords.txt","r");
stopwordlen=0;
while(fgets(stop[j],120,fp)!=NULL)
{
len=strlen(stop[j]);
stop[j][len-1]='\0';
stopwordlen++;
j++;
}

fp=fopen("upload.txt","r"); // document file that is uploaded 
// 
j=0;
maxwordlen=0;
while(1)
{
ch=fgetc(fp);
if(ch==EOF)
{	
break;
}
if(ch!=' ')
{
temp[j]=ch;
j++;
}
else
{

temp[j]='\0';
//Now here it  checks whether the word proccesed is a stop word or not
i=0;
check=0;
while(i<stopwordlen)
{
if(strcmp(temp,stop[i])==0)
{
check=1;
}
i++;
}
if(check==0)
{
strcpy(upload[maxwordlen],temp);
printf("%s\n",upload[maxwordlen]);
maxwordlen++;
}
j=0;
}
}
//ends here
return 0;
}

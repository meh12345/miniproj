// This script is to automate the process of create a index to each file in the document pool 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int count,i,total,j,stopwordlen,len,maxwordlen,check,k,len1; // temp variables
char ch;
char stop[120][120];
char temp[120];
char copy[100];
char upload[1000][100];

int maxfiles=100; // maximum files in document pools
char str1[100];// to hold index files name
char **str=(char **)malloc(sizeof(char *)*maxfiles); // this array will hold the name  of files  in the document pool 
FILE *fp; 
for(i=0;i<maxfiles;i++)
{
str[i]=(char *)malloc(sizeof(char)*100); 
} 
//printf("dfdf");
fp=popen("ls ./files/ | cut -c-100","r");
if(fp==NULL)
{
printf("failed to run command\n");
exit(0);
}
total=0;
while(fgets(str[total],sizeof(str[total])-1,fp)!=NULL)
{
len1=strlen(str[total]);
if(str[total][len1-1]=='\n')
{
str[total][len1-1]='\0';
}
printf("%s",str[total]);
total++;
}
printf("%d",total);
pclose(fp);

// this part will keep a list  of the stop words that we will keep a track in a document as not to process them 
j=0;
fp=fopen("stopwords.txt","r");
stopwordlen=0;
while(fgets(stop[j],120,fp)!=NULL)
{
len=strlen(stop[j]);
stop[j][len-1]='\0';
stopwordlen++;
j++;
}
// ends here 

// code to build index in each file starts here 
k=0;
while(k<total)
{
strcpy(copy,"./files/");
strcat(copy,str[k]);
fp=fopen(copy,"r");
if(fp==NULL)
{
printf("can not open file\n");
break;
}
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
//printf("%s\n",upload[maxwordlen]);
maxwordlen++;
}
j=0;
}
}
//ends here
sprintf(str1,"index%d.txt",k);
strcpy(copy,"./index/");
strcat(copy,str1);
fp=fopen(copy,"w");
if(fp==NULL)
{
printf("can not open file");
}
for(i=0;i<maxwordlen;i++)
{
fputs(upload[i],fp);
fputs("\n",fp);
}
fclose(fp);
k++;
}
return 0;
}


// this file will take a document for which you want some similar documents 
// code starts here 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include "./class/stopwords.cpp"
#include "./class/hashtable.cpp"
#include "./class/index1.cpp"
using namespace std;
int main()
{

int i;
stopword s1;
index1 s2;
			
hashtable **s4=new hashtable*[26];
for(i=0;i<26;i++)
{
s4[i]=NULL;
}


			/*This section will make index file of the document that is uploaded */
// store the stop words 
s1.stoplist("stopwords.txt","r");

//make index of file that is uploaded 
s2.makeindex(s1,s4,"upload.txt","r");
//copy index to a file
//(*s4)->print(s4);
//printf("\n\n-----------------------------------------------------------------------------------------------\n\n");
//s2.upload1(s4,"baseindex.txt","w");

				/* ends here */


			/* this section will make index of each document in the  document pool */

int maxfiles=100; // maximum files in document pools
int arr[100]={0};
int k,total,len1;
char copy[100];
char **str=(char **)malloc(sizeof(char *)*maxfiles); // this array will hold the name  of files  in the document pool
file f1;

if(f1.popen("ls ./files/ | cut -c-100","r")==NULL)
{
printf("failed to run command\n");
exit(0);
}
for(i=0;i<maxfiles;i++)
{
str[i]=(char *)malloc(sizeof(char)*100); 
}

total=0;
while(f1.fgets(str[total],sizeof(str[total])-1)!=NULL)
{
if(strcmp(str[total],"\n")!=0)
{
len1=strlen(str[total]);
if(str[total][len1-1]=='\n')
{
str[total][len1-1]='\0';
}
total++;
}	
}
		
k=0;
while(k<total)
{
strcpy(copy,"./files/");
strcat(copy,str[k]);
index1 s3;

hashtable **s5=new hashtable*[26];
for(i=0;i<26;i++)
{
s5[i]=NULL;
}

s3.makeindex1(s1,s4,s5,copy,"r");
arr[k]=s3.getmaxwordlen();
//(*s5)->print(s5);
//printf("\n\n-----------------------------------------------------------------------------------------------\n\n");
strcpy(copy,"./index/");
strcat(copy,str[k]);
(*s5)->upload(s5,copy,"w");
k++;
}
for(k=0;k<100;k++)
{
if(arr[k]!=0)
{
printf("%s :%d\n",str[k],arr[k]);	
}
}			 
return 0;
}

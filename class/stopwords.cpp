// this part will keep a list  of the stop words that we will keep a track in a document as not to process them
#include <stdbool.h>
#include "./file.cpp"
class stopword
{
private:
  char **stop; 
  int stopwordlen;
  int i;
public:
	stopword()
	{
	stopwordlen=0;
	stop=(char **)malloc(sizeof(char *)*1000);
	for(i=0;i<1000;i++)
	{
	stop[i]=(char *)malloc(sizeof(char)*100); 
	}
	}

	char** stoplist(char *filename,char* mode)
	{
	int j,len;
	file f(filename,mode);
	j=0;
	while(f.fgets(stop[j],120)!=NULL)
	{
	len=strlen(stop[j]);
	stop[j][len-1]='\0';
	stopwordlen++;
	j++;
	}
	return stop;
	}
	int getstopwordlen()
	{
		return stopwordlen;
	}
	bool comparestopword(char *temp)
	{
		i=0;
		while(i<stopwordlen)
		{
		if(strcmp(temp,stop[i])==0)
		{
			return true;
		}
		
		i++;
		}
	return false;
	}	

};

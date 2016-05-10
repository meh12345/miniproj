class index1
{
private:
//int maxwordlen;
char * upload;
int i,sflag;
int count;
public :
	index1()
	{
	//maxwordlen=0;
	upload=(char *)malloc(sizeof(char )*100);
	count=0;
	}

	char ** makeindex(stopword s1, hashtable **s4,char *filename,char *mode)
	{
//printf("hi");
		char temp[120],ch;
		int j;
		j=0;
		file f1(filename,mode);
		while(1)
		{
		ch=f1.fgetc();
		if(ch==EOF)
		{	
		break;
		}
		if(ch!=' ' && ch!='\n' && ch!=',' && ch!='.' && ch!='?')
		{
		temp[j]=tolower(ch);
		j++;
		}
		else
		{
		temp[j]='\0';
		if(!s1.comparestopword(temp))
		{
		strcpy(upload,temp);
	//printf("%s\n",upload);
	sflag=(*s4)->hash_search(s4,toupper(upload[0])-65,upload);
		//
	
		if(!sflag)
		{
		//printf("%d",sflag);
		(*s4)->addtohash(s4,toupper(upload[0])-65,upload);
		}


		//maxwordlen++;
		}
		j=0;
		}
		}		
		
	
	}
	

char ** makeindex1(stopword s1, hashtable **s4,hashtable **s5,char *filename,char *mode)
{
		char temp[120],ch;

		int j;
		j=0;
		file f1(filename,mode);
		while(1)
		{
		ch=f1.fgetc();
		if(ch==EOF)
		{	
		break;
		}
		if(ch!=' ' && ch!='\n' && ch!=',' && ch!='.' && ch!='?')
		{
		temp[j]=tolower(ch);
		j++;
		}
		else
		{
		temp[j]='\0';
		if(!s1.comparestopword(temp))
		{
		strcpy(upload,temp);
	//printf("%s\n",upload);
		sflag=(*s5)->hash_search(s4,toupper(upload[0])-65,upload);
	
	
		if(sflag)
		{
		count++;
		(*s5)->addtohash(s5,toupper(upload[0])-65,upload);
		}


		//maxwordlen++;
		}
		j=0;
		}
		}		
		
	
	}
	int getmaxwordlen()
	{
	return count;
	}

	
	/*void upload1(char * filename , char *mode)
	{
	int i;	
	file f3(filename,mode);
	if(f3.getfilepointer()==NULL)
	{
	printf("unable to open file for writing\n");
	}
	for(i=0;i<maxwordlen;i++)
	{
	f3.fputs(upload[i]);
	f3.fputs("\n");
	} 	 	
	}*/


};


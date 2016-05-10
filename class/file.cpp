class file
{
private:
FILE *fp;
public:
	file()
	{
	
	}
	file(const char *name, const char * mode)
	{
	    fp=fopen(name,mode);
	    if(fp==NULL)
	    {
		printf("\ncannot open file:%s",name);
		exit(1);
	    }
	}
	
	

	int fgetc()
	{
	int ch;
	ch=::fgetc(fp);
	return ch;
	}
		
	char* fgets(char *stop,int max)
	{
	char *ch;
	ch=::fgets(stop,max,fp);
	return ch;
	}
	
	int fputs(char *str)
	{
	int ch;
	ch=::fputs(str,fp);
	return ch;
	}
	
	FILE* getfilepointer()
	{
	   return fp;
	}
	FILE *popen(char *command, char *mode)
	{
		fp=::popen(command,mode);
	   return fp;
	}
		~file()
		{
		  fclose(fp);
		}	
	
};

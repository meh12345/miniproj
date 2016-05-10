class hashtable
{
private:
char name[100];
int count;
 hashtable *link;
public:
	
	bool hash_search(hashtable **s4,int index,char *upload)
	{
	hashtable *s;
	s=s4[index];
	if(s==NULL)
	return false;
	else
	{
	while(s!=NULL)
	{
	if(strcmp(upload,s->name)==0)
	{
	
	//s->count++;
	return true;
	}	
	else
	s=s->link;
	}
	return false;
	}
	}

	void addtohash(hashtable **s4,int index,char *upload)
	{
	hashtable *s,*a,*temp;
	temp=s=s4[index];
	a=new hashtable;
	strcpy(a->name,upload);
	a->count=1;	
	if(s==NULL || strcmp(s->name,upload)>0)
	{
	s=a;
	s->link=s4[index];
	s4[index]=s;
	return;	
	}
	else
	{
	while(temp!=NULL)
	{
	if(temp->link!=NULL)
	{
	if(strcmp(temp->name,upload)<=0 && strcmp(temp->link->name,upload)>0)
	{
	a->link=temp->link;
	temp->link=a;
	return;
	}
	temp=temp->link;
	}
	else
	{
	a->link=NULL;
	
	temp->link=a;
	return ;	
	}
			
	}
			
	}
	}
	void print(hashtable **s4)
	{
	hashtable *s;
	int i;
	i=0;
	while(i<26)
	{
	s=s4[i];
	while(s!=NULL)
	{
	printf("%s->",s->name);
		s=s->link;
	}
	printf("\n");
	i++;
	}
	}

	void upload(hashtable **s4,char * filename , char *mode)
	{
	char str[130];
	int check=0;
	file f3(filename,mode);
	if(f3.getfilepointer()==NULL)
	{
	printf("unable to open file for writing\n");
	}
	hashtable *s;
	int i;
	i=0;
	while(i<26)
	{
	s=s4[i];
	while(s!=NULL)
	{
	check=1;
	f3.fputs(s->name); 
	f3.fputs("\n");
	//printf("%s->",s->name);
		s=s->link;
	}
	//printf("\n");
	i++;
	}
	if(check==0)
	{
	strcpy(str,"rm ");
	strcat(str,filename);
	 system(str);
	}
	}

};

/*LL in sorted order*/
#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
//#include<time.h>
#define BUFSIZE 100
#define FILESIZE 256
void red()
{
	printf("\033[1;31m");
}

void yellow()
{
	printf("\033[0;33m");
}

void green()
{
	printf("\033[0;32m");
}
void cyan()
{
	printf("\033[0;36m");
}

void reset()
{
	printf("\033[0m");
}
void swap(char **str1, char **str2)
{
	char *temp = *str1;
	*str1 = *str2;
	*str2 = temp;
	//printf("%s\n%s\n\n\n",*str1,*str2);
}
void sort(char*** fileparameters,char*** filenames, int size)
{
	int temp;
	int min_index = 0;
	int min_comp = 0;
	for(int i = 0; i < size;i++)
	{
		min_index = i;
		
		for(int j = i+1; j < size ;j++)
		{
			if( strcmp((*filenames)[j],(*filenames)[min_index]) < 0)
			{
				min_index = j;
			}
		//printf("%d",temp);
		//printf(" %s %s", (*filenames)[j+1],(*filenames)[j]);
			/*
			if(strcmp((*filenames)[j+1],(*filenames)[j]) < 0)
			{

				swap(&(*filenames)[j+1],&(*filenames)[j]);
				swap(&(*fileparameters)[j+1],&(*fileparameters)[j]);
			}
			*/
		//printf(" %s %s\n\n", (*filenames)[j+1],(*filenames)[j]);
			//printf("No error here\n");
		}
		
		swap(&(*filenames)[i],&(*filenames)[min_index]);
		swap(&(*fileparameters)[i],&(*fileparameters)[min_index]);
		
	}
}

int main(int argc, char* argv[]){
	char** fileparameters = NULL;
	char** filenames = NULL;
	DIR *d;
	struct dirent *de;
	struct stat buf;
	int i,j,k=0,index=0;
	char P[10]="rwxrwxrwx",AP[10]=" ";
	struct passwd *p;
	struct group *g;
	struct tm *t;
	char time[26];
	d=opendir(".");
	while((de=readdir(d))!=NULL){
		fileparameters = (char**)realloc(fileparameters,sizeof(char*)*(index+1));
		filenames = (char**)realloc(filenames,sizeof(char*)*(index+1));
		*(fileparameters + index) = (char*)malloc(sizeof(char)*BUFSIZE);
		*(filenames + index) = (char*)malloc(sizeof(char)*FILESIZE);
		stat(de->d_name,&buf);
		if(S_ISDIR(buf.st_mode))
			fileparameters[index][k]='d';
		else if(S_ISREG(buf.st_mode))
			fileparameters[index][k]='-';
		else if(S_ISCHR(buf.st_mode))
			fileparameters[index][k]='c';
		else if(S_ISBLK(buf.st_mode))
			fileparameters[index][k]='b';
		else if(S_ISLNK(buf.st_mode))
			fileparameters[index][k]='l';
		else if(S_ISFIFO(buf.st_mode))
			fileparameters[index][k]='p';
		else if(S_ISSOCK(buf.st_mode))
			fileparameters[index][k]='s';
		for(i=0,j=(1<<8);i<9;i++,j>>=1)
			AP[i] = (buf.st_mode & j) ? P[i]:'-';
		++k;
		k += snprintf(fileparameters[index]+k,BUFSIZE-k,"%s",AP);
		
		k += snprintf(fileparameters[index]+k,BUFSIZE-k," %ld ",buf.st_nlink);
		
		p=getpwuid(buf.st_uid);
		k += snprintf(fileparameters[index]+k,BUFSIZE-k,"%.8s",p->pw_name);
		
		g=getgrgid(buf.st_gid);
		k +=  snprintf(fileparameters[index]+k,BUFSIZE-k," %.8s",g->gr_name);
		
		k +=  snprintf(fileparameters[index]+k,BUFSIZE-k,"%8ld",buf.st_size);
		
		t = localtime(&buf.st_mtime);
		strftime(time,sizeof(time),"%b %d %H:%M",t);
		k +=  snprintf(fileparameters[index]+k,BUFSIZE-k,"  %s  ",time);
		snprintf(filenames[index],FILESIZE,"%s",de->d_name);
		//printf("%s\n",fileparameters[index]);
		k = 0;
		index++;
		//printf("%d\n",index);
	}
	
//printf("\n");
	sort(&fileparameters,&filenames,index);
	
	for(i = 0; i< index;i++){
		
		printf("%s",fileparameters[i]);
		if(fileparameters[i][0]=='d')
			red();
		else if(fileparameters[i][9]=='x'||fileparameters[i][3]=='x'||fileparameters[i][6]=='x')
			green();
		printf("%s",filenames[i]);
		reset();
		if(fileparameters[i][0]=='d')
			printf("/");
		else if(fileparameters[i][9]=='x'||fileparameters[i][3]=='x'||fileparameters[i][6]=='x')
			printf("*");
		printf("\n");
	}
	for(i = 0; i < index;i++){
		free(fileparameters[i]);
		free(filenames[i]);
	}
	free(fileparameters);
	free(filenames);
	
	/*for(i = 0; i< index;i++)
		
	*/
	//sleep(2);
}
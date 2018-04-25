#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm time1, time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
   if(stat("text1",&stat1)==-1)
   {
      printf("text1 is not opened.\n");
   }
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
   if(stat("text2",&stat2)==-1)
   {
      printf("text2 is not opened.\n");
   }
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	localtime_r(&stat1.st_mtime,&time1);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
  	 localtime_r(&stat2.st_mtime,&time2);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	if((int)stat1.st_size>(int)stat2.st_size)
		printf("text1 is bigger\n");
	else if((int)stat1.st_size<(int)stat2.st_size)
		printf("text2 is bigger\n");
	else
		printf("sizes are equal\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
    if((int)stat1.st_size>(int)stat2.st_size)
            printf("text1 is bigger\n");
    else if((int)stat1.st_size<(int)stat2.st_size)
            printf("text2 is bigger\n");
    else
            printf("same\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	if(time1.tm_yday<time2.tm_yday)
		printf("text1 is early.\n");
	else if(time1.tm_yday>time2.tm_yday)
		printf("text2 is early.\n");
	else
		printf("same time\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	if(time1.tm_hour<time2.tm_hour)
		printf("text1 is early.\n");
	else if(time1.tm_hour>time2.tm_hour)
		printf("text2 is early.\n");
	else
	{		
		if(time1.tm_min<time2.tm_min)
			printf("text1 is early.\n");
		else if(time1.tm_min>time2.tm_min)
			printf("text2 is early.\n");
		else
		printf("same time\n");
	}
}

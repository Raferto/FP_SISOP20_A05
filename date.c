#include "types.h"  
#include "user.h"   
#include "date.h"   


int kabisat(int th){
	// int flag = 0;
	if(th%400==0)
		return 1;
	else if(th%100==0)
		return 0;
	else if(th%4==0)
		return 1;
	else 
		return 0;
}


void month(int x){
	switch(x)
	{
		case 1:printf(1," Jan");
		       break;
		case 2:printf(1," Feb");
		       break;
		case 3:printf(1," Mar");
		       break;
		case 4:printf(1," Apr");
		       break;
		case 5:printf(1," May");
		       break;
		case 6:printf(1," Jun");
		       break;
		case 7:printf(1," Jul");
		       break;
		case 8:printf(1," Aug");
		       break;
		case 9:printf(1," Sep");
		       break;
		case 10:printf(1," Oct");
		       break;
		case 11:printf(1," Nov");
		       break;
		case 12:printf(1," Dec");
		       break;
	}
}


void day(int x,int y,int z){
	int initial_day = 4;
	int count = 0;	
	if(x>1970)
	{
		for(int i=1970;i<x;i++)
		{
			if(kabisat(i))
				count += 366;
			else
				count += 365;
		}
	}
	for(int i=1;i<y;i++)
	{
		if(i==2)
		{
			if(kabisat(x))
				count += 29;
			else
				count += 28;
		}
		else if((i<8)&&(i%2==1))
			count += 31;
		else if((i<8)&&(i%2==0))
			count += 30;
		else if((i>=8)&&(i%2==0))
			count += 31;
		else
			count += 30;
	}
	int final = (initial_day+count+z-1)%7;
	switch(final)
	{
		case 0:printf(1,"Sun");
		       break;
		case 1:printf(1,"Mon");
		       break;
		case 2:printf(1,"Tue");
		       break;
		case 3:printf(1,"Wed");
		       break;
		case 4:printf(1,"Thur");
		       break;
		case 5:printf(1,"Fri");
		       break;
		case 6:printf(1,"Sat");
		       break;
	 }
}


void time(){
	struct rtcdate tgl;
	if (date(&tgl)) 
	{
		printf(2, "Error\n");
		exit();
	}
	if(tgl.minute>59)
	{
		tgl.hour = tgl.hour + 8;
		tgl.minute = tgl.minute-59;
	}
	else
	{
		tgl.hour = tgl.hour + 7;
	}
	if(tgl.hour>=24)
		tgl.hour -= 24;
	printf(1," %d:%d:%d", tgl.hour, tgl.minute, tgl.second);
}

void now(){
	struct rtcdate tg;
	if (date(&tg)) 
	{
		printf(2, "Error\n");
		exit();
	}
	day_name(tg.year, tg.month, tg.day);	 
	month_name(tg.month);  
	printf(1," %d", tg.day);  
	time();  
	printf(1," WIB");
	printf(1," %d\n", tg.year);  
}

void utc(){
	struct rtcdate tgl;
	if (date(&tgl)) 
	{
		printf(2, "Error\n");
		exit();
	}
	day_name(tgl.year, tgl.month, tgl.day);	
	month_name(tgl.month); 
	printf(1," %d", tgl.day); 
	printf(1," %d:%d:%d", tgl.hour, tgl.minute, tgl.second); 
	printf(1," UTC");
	printf(1," %d\n", tgl.year);  
}

int main(int argc, char *argv[]){
	
	if(argc==1)
		now();  
	else
	{
		
		if((argc==2) && (!strcmp(argv[1], "-u")))
			utc();  

		else
			printf(1,"Invalid\n");
	}
exit();
}

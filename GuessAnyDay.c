#include<stdio.h>
#include<stdbool.h>
#include <time.h>

int dayInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
char dayOfWeekMap[][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int refDate,refMonth,refYear,refDayOfWeek;

bool isLeapYear(int year){
    if(year%4!=0) return false;
    if(year%100==0 && year%400!=0) return false;
    return true;
}

int diffToEndOfMonth(int date,int month,int year){
    int leapDay=(month==1 && isLeapYear(year));
    return (dayInMonth[month]+leapDay)-date;
}

int totalDaysBetweenMonths(int startMonth,int endMonth,int year){
    int noOfDays=0;
    int leapDay=0;
    for (int i = startMonth-1; i < endMonth; i++){
        leapDay=(i==1 && isLeapYear(year));
        noOfDays=noOfDays+dayInMonth[i]+leapDay;
    }
    return noOfDays; 
}
int dTotalDaysBetweenYears(int startYear, int endYear, int startMonth, int endMonth){
    int noOfDays=0;
    int leapDay=0;
    int temp=startYear;
    for (int i = 1; i<= endYear-startYear+1; i++){
        leapDay=isLeapYear(temp++);
        noOfDays+=365+leapDay;
    }
    noOfDays=noOfDays-totalDaysBetweenMonths(1,startMonth-1,startYear)-totalDaysBetweenMonths(endMonth+1,12,endYear);
    return noOfDays;
}
int getFutureDay(int date,int month,int year){
    int noOfDaysBetweenMonth=dTotalDaysBetweenYears(refYear, year, refMonth, month);
    noOfDaysBetweenMonth=noOfDaysBetweenMonth-refDate-(dayInMonth[month-1]-date);
    int dayOfWeek=(refDayOfWeek+(noOfDaysBetweenMonth))%7;
    return dayOfWeek;
}

int getPastDay(int date,int month,int year){
    int noOfDaysBetweenMonth=dTotalDaysBetweenYears( year,  refYear, month, refMonth);
    noOfDaysBetweenMonth=noOfDaysBetweenMonth-date-(dayInMonth[refMonth-1]-refDate);
    int dayOfWeek=(refDayOfWeek-noOfDaysBetweenMonth)%7;
    if(dayOfWeek<0) dayOfWeek+=7;
    return dayOfWeek;
}

int main(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    refDate=tm.tm_mday;refMonth=tm.tm_mon+1;refYear=tm.tm_year+1900;refDayOfWeek=tm.tm_wday;
    
    //printf("%d %d %d %d",refDate,refMonth,refYear,refDayOfWeek);
    int dateToFind;
    printf("Enter the date to find:\n");
    scanf("%d",&dateToFind);

    int monthToFind;
    printf("Enter the month to find:\n");
    scanf("%d",&monthToFind);

    int yearToFind;
    printf("Enter the year to find:\n");
    scanf("%d",&yearToFind);

    if(getFutureDay(dateToFind,monthToFind,yearToFind)>-1)
        printf("%s\n",dayOfWeekMap[getFutureDay(dateToFind,monthToFind,yearToFind)]);
    else
        printf("%s\n",dayOfWeekMap[getPastDay(dateToFind,monthToFind,yearToFind)]);
    
    return 0;
}
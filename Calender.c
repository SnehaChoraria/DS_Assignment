#include <stdio.h>

int isLeap(int year) {
    return (year % 4 == 0);
}

int main() {
    char days[7][3] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char months[12][3] = {"Jan","Feb","Mar","Apr","May","Jun",
                           "Jul","Aug","Sep","Oct","Nov","Dec"};
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int month,year;
    printf("Enter month (1-12) and year: ");
    scanf("%d %d", &month, &year);

    if (isLeap(year))
        daysInMonth[1]=29;

    int totalDays = 0;
    for (int y=1900; y<year;y++)// taking 1 jan 1900 as base Sunday 
        totalDays+=isLeap(y)?366:365;

    for (int m=0;m<month-1;m++)
        totalDays+=daysInMonth[m];

    int startDay=totalDays%(7);

    printf("\n%s %d\n",months[month-1],year);
    for (int i=0;i<7;i++)
        printf("%s ", days[i]);
    printf("\n");

    for (int i=0; i<startDay;i++)
        printf("    ");

    for (int d=1; d<=daysInMonth[month-1];d++) 
    {
        printf("%3d ",d);
        if ((d + startDay) % 7 == 0)
            printf("\n");
    }
}
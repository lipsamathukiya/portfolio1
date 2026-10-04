/*Time Converter*/
#include<iostream.h>
#include<conio.h>

class timeconverter
{
   int hours,minutes,seconds;

     public:
	 void secondstotime()
	 {
	     int total;

	     cout<<"Enter total seconds: ";
	     cin>> total;

	     hours=total/3600;
	     total=total%3600;

	     minutes=total/60;
	     seconds=total%60;

	     cout<<"HH:MM:SS ="<< hours << ":" << minutes << ":" << seconds;
	 }

void timetoseconds()
{
   int total;

    cout<<"\nEnter Hours:";
    cin >> hours;

    cout<<"Enter minutes:";
    cin >>minutes;

    cout<<"Enter seconds:";
    cin >>seconds;

    total=(hours * 3600) +(minutes*60)+ seconds;

    cout<<"total seconds: "<<total;
    }
};

void main()
{
      clrscr();

      timeconverter t;
      t.secondstotime();
      t.timetoseconds();

      getch();
}
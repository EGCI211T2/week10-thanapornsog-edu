#include <iostream>
#include <iomanip>
using namespace std;
#include "Time.h"

void getTime(struct Time &t){
   char c;
   cout<<"Input Time(hh:mm:ss)";
   cin>>t.h>>c>>t.m>>c>>t.s;
}
struct Time subtract(struct Time t2, struct Time t1){
   struct Time t3;
   int t1_seconds=t1.h *3600 +t1.m*60+t1.s;
   int t2_seconds=t2.h *3600 +t2.m*60+t2.s;
   int diff = t2_seconds-t1_seconds;
   if (diff < 0) {
       diff = diff + (24 * 3600);
   }
   t3.h = diff/3600;
   diff = diff%3600;
   t3.m = diff/60;
   t3.s = diff%60;
   return t3;
}
void display(struct Time t3){
   cout<< setfill('0') << setw(2) << t3.h<<":"<<t3.m<<":"<<t3.s<<"\n";
}
int main(){
   struct Time t1,t2,t3;
   cout<<"What time was it?" << "\n";
   getTime(t1);
   cout<<"What time is it now?"<< "\n";
   getTime(t2);
   t3=subtract(t2,t1); 
   cout<<"Time diff is ";
   display(t3);
   return 0;
}
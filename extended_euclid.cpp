#include<iostream>
using namespace std;
int x,y,d;
void extended_euclid(int a,int b){
	if(b==0){
	  x=1;
	  y=0;
	  d=a;
	  return;	
	}
   extended_euclid(b,a%b);
   int x1=y;
   int y1=x-(a/b)*y;
   x=x1;
   y=y1;
}


int main(){
int a=24,b=7;
extended_euclid(a,b);

cout<<x<<" "<<y<<" "<<d;

return 0;	
}
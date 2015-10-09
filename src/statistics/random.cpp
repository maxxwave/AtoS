#include <iostream>
#include <ctime> // Needed for the true randomization
#include <cstdlib> 
#include <cmath>
#define PI 3.14159265358979323846264338327950288
double random(double sigma, double miu)
{	
	float x;
	float f;
	float tmp;
	x = float (rand()+1.0f)/(RAND_MAX+1.0f);
//	srand( time(0)); // This will ensure a really randomized number by help of time.
	tmp=(x-miu)/sigma;
	f=(1/(sigma*sqrt(2*PI))) * exp(-tmp*tmp/2.0f);
	return f;
}
/*int main()
{
double number[1000]={};
double miu=-2;
double sigma=0.7;
for (int i=0; i<1000; i++){
  number[i] = random(sigma, miu);
  cout<<number[i]<<"\t"<<i<<"\n";}
return 0;
}*/

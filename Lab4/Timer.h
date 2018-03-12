#ifndef TIMER_H
#define TIMER_H

#include<chrono>

template<class T>
double Timer(void (*T) func){
   
   clock_t start, finish;

   start = clock();
   func();
   finish = clock();
   return finish - start;
}

double Add(double a, double b){
  return a+b;
}

double Mult(double a, double b){
  return a*b;
}

// int main(){
//   Timer(Add(1,2));
//   //Combiner();
// }


#endif
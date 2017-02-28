#ifndef DATAMANIP_H
#define DATAMANIP_H
#include <iomanip>
#include <string>


namespace Datamanip
{

template<typename T>
struct Data_three_arg
{
   int arg;
   T  arg2;

  std::ostream & (*pf) (std::ostream &,const int & ,T );

  Data_three_arg(std::ostream & (*f) (std::ostream &,const int & ,  T  ),const int & i,T  s)
  :arg(i),arg2(s),pf(f){}

};


template<typename T>
struct Data_two_arg
{

   T  arg;

  std::ostream & (*pf) (std::ostream & ,T );

  Data_two_arg(std::ostream & (*f) (std::ostream &, T ),T s)
  :arg(s),pf(f){}

};



template<typename T>
std::ostream & operator << (std::ostream & os, const Data_three_arg<T> &a)
{

    a.pf(os,a.arg,a.arg2);
    return os;

}



template<typename T>
std::ostream & operator << (std::ostream & os, const Data_two_arg<T> &a)
{

    a.pf(os,a.arg);
    return os;

}






}





























#endif // DATAMANIP_H


#ifndef FUNCTORS_H
#define FUNCTORS_H
#include <string>
#include <algorithm>

namespace Myfunctors
{

struct strtolower{

void operator() (std::string &) const ;


};

struct strtoupper{

void operator() (std::string &) const ;


};



struct  delallpunckt
{

char ch;
public:
   delallpunckt(const char & c):ch(c){}
   delallpunckt():ch(' '){}
   void operator ()(std::string &) const ;




};












}

using Myfunctors::strtolower;
using Myfunctors::strtoupper;
using Myfunctors::delallpunckt;










#endif // FUNCTORS_H


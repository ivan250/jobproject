#include "projmanip_impl.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <codecvt>
#include <algorithm>
#include <iterator>
#include <functional>
#include <storage.h>
#include <vector>
#include <cctype>

using Storage::counter_Storage;
using Storage::row_Storage;


int myf(std::istream & is)
{
    int i=1;

    while(!is.eof()){ if(is.get()=='\n') i++;}
    is.clear();is.seekg(0);
    return i;

}


bool Projmanip::replace_word(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}


/*
Защита от повторной инициализации в циклах.
Что позволяет использовать манипулятор в цикле и не тормозить программу.
*/

std::ostream & Projmanip::mydescent (std::ostream & os , const int & i, const char *s)
{
Storage::counter_Storage::initialization(i);
if(counter_Storage::showfl())
{

 int a,b,c =0;
 b =i+1;
 a = counter_Storage::getcountrow();

   c = (a / b)+1;
   c*=b;

   if(row_Storage::show() == c)
   {
        os<<s;
         counter_Storage::fl();
        return os;
   }
    return os;
}

    Storage::counter_Storage::initialization(i);
    if (Storage::counter_Storage::get()) {os << s;}

   return os;

}



std::ostream & Projmanip::addchar(std::ostream & o, const  int  & i, const char & ch)
{
     std::string str(i,ch);
     o<<str;
     return o;

}




std::string Projmanip::curtime(const char * format)
{

char buf[40];
time_t seconds = time(0);
tm* timeinfo = localtime(&seconds);
strftime(buf,sizeof(buf), format, timeinfo);
return buf;

}
/*                                                  //old realization
std::istream& row (std::istream & is)
{

if(Storage::row_Storage::status())
 {      int i =0;

        is>>std::noskipws;
        i = std::count(std::istream_iterator<char>(is),std::istream_iterator<char>(),'\n');
        is>>std::skipws;
        is.clear();is.seekg(0);

        Storage::row_Storage::initialization(i);
 }
    return is;

}
*/
std::istream& Projmanip::prow(std::istream & is)
{
  if(Storage::row_Storage::status())
    {   int counter=0;
        int i=0;
        std::string str;
                 while(std::getline(is,str))
                {

                        ++counter;
                        if(str.empty()) ++i;

                }

        is.clear();is.seekg(0);
        Storage::row_Storage::initialization(counter-i);
        Storage::counter_Storage::initialiazation_row(counter-i);
     }
        return is;

}

std::ostream & Projmanip::convert_in_rus(std::ostream & os, const std::string &trlt)
{

    char buf[100];
    OemToCharA(trlt.c_str(),buf);

    os<< buf;
    return os;
}




std::ostream & Projmanip::widthPlusArgs (std::ostream & os, const  int & i, const char * str )
{

    os << std::setw(i) <<str;

    return os;




}





std::ostream & Projmanip::widthShiftLeft (std::ostream & os, const  int & i, const char *str )
{

    os << std::setw(i)<<std::left<<str;

    return os;


}

std::ostream & Projmanip::widthShiftRight (std::ostream & os, const  int & i, const char *str )
{

    os << std::setw(i)<<std::right<<str;

    return os;


}




std::ostream & Projmanip::widthShiftRight (std::ostream & os, const  int & i, const int & val )
{

    os << std::setw(i)<<std::right<<val;

    return os;


}













#ifndef PROJMANIP_H
#define PROJMANIP_H
#include "datamanip.h"
#include "storage.h"

#include <iostream>
#include <algorithm>
#include <functional>

namespace Projmanip
{










bool replace_word(std::string& str, const std::string& from, const std::string& to);



std::ostream & widthPlusArgs (std::ostream &, const  int &, const char *  );
std::ostream & widthShiftLeft (std::ostream &,const  int &, const char *  );
std::ostream & widthShiftRight (std::ostream &,const  int &, const char *   );
std::ostream & mydescent (std::ostream &, const int &, const char *);

std::ostream & addchar (std::ostream &, const int &  , const char &);

std::string curtime(const char *);

std::istream& get_allrow (std::istream & f);
std::istream& prow(std::istream & );


std::ostream & convert_in_rus(std::ostream & , const std::string & );




std::ostream & widthShiftRight (std::ostream &,const  int &, const int &   );





inline Datamanip::Data_three_arg<const char *> gwstr (const int & i, const char * str)
{
    return Datamanip::Data_three_arg<const char *>(Projmanip::widthPlusArgs,i,str);


}




inline Datamanip::Data_three_arg<const char *> gsetwl (const int & i,const char * str)
{
    return Datamanip::Data_three_arg<const char *>(Projmanip::widthShiftLeft,i,str);


}

inline Datamanip::Data_three_arg<const char *> gsetwr (const int & i, const char * str)
{
    return Datamanip::Data_three_arg<const char *>(Projmanip::widthShiftRight,i,str);


}





inline Datamanip::Data_three_arg<const int &> gsetwr (const int & i, const int & val)
{
    return Datamanip::Data_three_arg<const int &>(Projmanip::widthShiftRight,i,val);


}




inline Datamanip::Data_three_arg<const char *> gdesc (const int & i,const char *  s)
{

    return Datamanip::Data_three_arg<const char *>(Projmanip::mydescent,i,s);


}


inline std::ostream & gnumstr(std::ostream & os)
{
    os<<(Storage::row_Storage::get()+1);
    return os;

}

inline std::ostream & gtime (std::ostream & os)
{

    os<<Projmanip::curtime("%X");
    return os;

}

inline std::ostream & gdate (std::ostream & os)
{

    os<<Projmanip::curtime("%x");
    return os;

}

inline Datamanip::Data_three_arg<const char &> gline (const int & i,const char & ch )
{
    return Datamanip::Data_three_arg<const char &>(Projmanip::addchar,i,ch);


}



inline Datamanip::Data_two_arg<const std::string &> grus (const std::string & s)
{

   return Datamanip::Data_two_arg<const std::string &>(Projmanip::convert_in_rus,s);



}














}









#endif // PROJMANIP_H


#ifndef PROJMANIP_IMPL_H
#define PROJMANIP_IMPL_H
#include "projmanip.h"
#include "datamanip.h"
#include "storage.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>

namespace Projmanip



{



int myf(std::istream &os);

int position(std::istream & o);

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



























}

















#endif // PROJMANIP_IMPL_H


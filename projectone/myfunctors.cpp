#include "myfunctors.h"

#include <string>
#include <algorithm>
#include <cctype>

void  Myfunctors::delallpunckt:: operator ()(std::string & s) const{
std::replace_if(s.begin(),s.end(),::ispunct,ch);

}


void Myfunctors::strtolower::operator() (  std::string & s) const {
    std::transform(s.begin(),s.end(),s.begin(),::tolower);}


void Myfunctors::strtoupper::operator() (  std::string & s) const {
    std::transform(s.begin(),s.end(),s.begin(),::toupper);}











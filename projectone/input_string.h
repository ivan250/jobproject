#ifndef INPUT_STRING_H
#define INPUT_STRING_H
#include <sstream>
namespace Stringinput
{

class Inputstring
{

private:

    std::ostringstream buf;

public:


    template<class T>
    Inputstring& operator<< (const T & val) {
        buf << val;
        return *this;
    }

    operator std::string () const {
        return buf.str();
    }

    const std::string  str() const {return buf.str();}


    size_t size() {return buf.str().size();}
    void clear() {buf.str("");} //ïîçâîëÿåò ðàáîòàòü â öèêëàõ


};






}



using Stringinput::Inputstring;










#endif // INPUT_STRING_H


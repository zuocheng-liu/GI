#include "FastCGI.h"

#include <sstream>

using namespace std;
namespace FastCGI {

bool Header::Dump(std::string& str) {
    stringstream ss;
    ss << "|FastCGI Header" 
        << "|"
        << endl;
    ss << "|Version" << "\t|" << (uint32_t)content.version 
        << "|"
        << endl;
    ss << "|Type" << "\t|" << (uint32_t)content.type 
        << "|"
        << endl;
    ss << "|requestIdB1" << "\t|" << (uint32_t)content.requestIdB1 
        << "|"
        << endl;
    ss << "|requestIdB0" << "\t|" << (uint32_t)content.requestIdB0 
        << "|"
        << endl;
    ss << "|contentLengthB1" << "\t|" << (uint32_t)content.contentLengthB1 
        << "|"
        << endl;
    ss << "|contentLengthB0" << "\t|" << (uint32_t)content.contentLengthB0 
        << "|"
        << endl;
    ss << "|paddingLength" << "\t|" << (uint32_t)content.paddingLength 
        << "|"
        << endl;
    ss << "|reserved" << "\t|" << (uint32_t)content.reserved 
        << "|"
        << endl;
    str = ss.str();
    return true;
}

} // end namespace FASTCGI

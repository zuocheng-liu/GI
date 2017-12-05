#ifndef FASTCGI_STDOUT_STREAM_H
#define FASTCGI_STDOUT_STREAM_H

#include <string>

#include "FastCGI.h"
namespace FastCGI {
class FastCGIStdOutStream {
    public :
        FastCGIStdOutStream& operator << (const std::string& str);
};
} // namespace FastCGI

#endif 

#ifndef FASTCGI_SERVICE_H
#define FASTCGI_SERVICE_H

#include "FastCGI.h"
#include "FastCGIStdOutStream.h"

namespace FastCGI {

    
class Context {
    public :
    private :
};

class FastCGIService {
    public :
        virtual void Run(const Context &context, FastCGIStdOutStream& out);
    private :
};


} // namespace FastCGI

#endif

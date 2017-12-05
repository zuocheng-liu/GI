#include "FastCGIService.h"

namespace FastCGI {

void FastCGIService::Run(const Context &context, FastCGIStdOutStream& out) {
    out << "Hello FastCGI";
}

}



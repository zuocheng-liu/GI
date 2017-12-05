#include "FastCGIStdOutStream.h"

namespace FastCGI {

FastCGIStdOutStream& FastCGIStdOutStream::operator << (const std::string& str) {
    return *this;
}

} // namespace FastCGI

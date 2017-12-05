#ifndef FASTCGI_H
#define FASTCGI_H

#include <stdint.h>

#include <cstring>
#include <string>

namespace FastCGI {
typedef int8_t byte_t;
#define HEADER_Context_LEN 8
#define FCGI_VERSION_1 1
// #define FCGI_MAXTYPE (FCGI_UNKNOWN_TYPE)

class Record {
  public :
    virtual bool Dump(std::string& str) { return false;}
//    virtual bool Serialize(std::string& str) = 0;
//    virtual bool Serialize(std::string& str, size_t size) = 0;
//    virtual bool Unserialize(const std::string& str) = 0;
};

class Header : public Record {
  public :
    enum RecordType {
        FCGI_BEGIN_REQUEST      = 1,
        FCGI_ABORT_REQUEST      = 2,
        FCGI_END_REQUEST        = 3,
        FCGI_PARAMS             = 4,
        FCGI_STDIN              = 5,
        FCGI_STDOUT             = 6,
        FCGI_STDERR             = 7,
        FCGI_DATA               = 8,
        FCGI_GET_VALUES         = 9,
        FCGI_GET_VALUES_RESULT  = 10,
        FCGI_UNKNOWN_TYPE       = 11
    };

    typedef struct {
        byte_t version;
        byte_t type;
        byte_t requestIdB1;
        byte_t requestIdB0;
        byte_t contentLengthB1;
        byte_t contentLengthB0;
        byte_t paddingLength;
        byte_t reserved;
    } Content;

    Content content;
    
    Header() {
        bzero(&content, sizeof(Content));
    }
    bool Dump(std::string& str);
};

// #define FCGI_NULL_REQUEST_ID 0
class BeginRequestRecord : public Record {
  public :
    enum FastCGIRole {
        FCGI_RESPONDER = 1,
        FCGI_AUTHORIZER = 2,
        FCGI_FILTER = 3,
    };
    
    typedef struct {
        byte_t roleB1;
        byte_t roleB0;
        byte_t flags;
        byte_t reserved[5];
    } Body;

    typedef struct {
        Header::Content header;
        Body body;
    } Content;

    Content content;
};

class EndRequestRecord : public Record {
    public :
        enum ProtocolStatus {
            FCGI_REQUEST_COMPLETE = 0,
            FCGI_CANT_MPX_CONN = 1,
            FCGI_OVERLOADED = 2,
            FCGI_UNKNOWN_ROLE = 3,
        };

        typedef struct {
            byte_t appStatusB3;
            byte_t appStatusB2;
            byte_t appStatusB1;
            byte_t appStatusB0;
            byte_t protocolStatus;
            byte_t reserved[3];
        } Body;

        typedef struct {
            Header::Content header;
            Body body;
        } Content;
    
        Content content;
};


#define FCGI_MAX_CONNS "FCGI_MAX_CONNS"
#define FCGI_MAX_REQS "FCGI_MAX_REQS"
#define FCGI_MPXS_CONNS "FCGI_MPXS_CONNS"

class UnknownTypeRecord {
    public :
        typedef struct {
            byte_t type; 
            byte_t reserved[7];
        } Body;

        typedef struct {
            Header::Content header;
            Body body;
        } Content;
        
        Content content;
};

class StdIn : public Record {
    public :
        typedef struct {
            Header::Content header;
            std::string content;
            std::string padding;
        } Content;
        Content content;
};

class StdOut : public Record {
    public :
        typedef struct {
            Header::Content header;
            std::string content;
            std::string padding;
        } Content;
        Content content;
};

} // end namespace FastCGI
#endif

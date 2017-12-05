#include "FastCGIProcessor.h"

using namespace std;

namespace  FastCGI {

bool FastCGIProcessor::process(boost::shared_ptr<apache::thrift::protocol::TProtocol> in, boost::shared_ptr<apache::thrift::protocol::TProtocol> out) {
    try {
        // read header
        FastCGI::Header header;
        in->readByte(header.content.version);
        in->readByte(header.content.type);
        in->readByte(header.content.requestIdB1);
        in->readByte(header.content.requestIdB0);
        in->readByte(header.content.contentLengthB1);
        in->readByte(header.content.contentLengthB1);
        in->readByte(header.content.paddingLength);
        in->readByte(header.content.reserved);

        string debug_str;
        header.Dump(debug_str);
        apache::thrift::GlobalOutput.printf("%s", debug_str.c_str());
    } catch (...) {
    }
    FastCGI::StdOut fast_stdout;
    fast_stdout.content.header.version = 1;
    fast_stdout.content.header.type = 6;
    fast_stdout.content.header.requestIdB1 = 0;
    fast_stdout.content.header.requestIdB0 = 1;
    fast_stdout.content.header.contentLengthB1 = 0;
    fast_stdout.content.header.contentLengthB0 = 80;
    fast_stdout.content.header.paddingLength = 0;
    fast_stdout.content.content = "X-Powered-By: PHP/7.1.11\r\nContent-type: text/html; charset=UTF-8\r\n\r\nHello PHP  !";
    fast_stdout.content.padding = "";
    FastCGI::EndRequestRecord fast_end;
    fast_end.content.header.version = 1;
    fast_end.content.header.type = 3;
    fast_end.content.header.requestIdB1 = 0;
    fast_end.content.header.requestIdB0 = 1;
    fast_end.content.header.contentLengthB1 = 0;
    fast_end.content.header.contentLengthB0 = 8;
    fast_end.content.header.paddingLength = 0;
    fast_end.content.body.appStatusB3 = 0;
    fast_end.content.body.appStatusB2 = 0;
    fast_end.content.body.appStatusB1 = 0;
    fast_end.content.body.appStatusB0 = 0;
    fast_end.content.body.protocolStatus = 0;
    std::string output = "";
    output.append((char *)&(fast_stdout.content.header), 8);
    output.append(fast_stdout.content.content);
    output.append((char *)&(fast_end.content.header), 8);
    output.append((char *)&(fast_end.content.body), 8);
    out->writeBinary(output);
    out->getOutputTransport()->flush();
    //out->getOutputTransport()->close();
    //in->getInputTransport()->close();
    return false;
  }



} // end namespace FastCGI

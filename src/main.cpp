#include <iostream>
#include <unistd.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>

#include "uwsgi.h"
#include <concurrency/ThreadManager.h>
#include <concurrency/PosixThreadFactory.h>
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <server/TThreadPoolServer.h>
#include <server/TThreadedServer.h>
#include <transport/TServerSocket.h>

#include <FastCGIProcessor.h>

using namespace std;

using namespace apache::thrift;
//using namespace apache::thrift::processor;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;
using namespace FastCGI;


int main(int argc, char **argv) {
  
  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  boost::shared_ptr<TProcessor> processor(new FastCGIProcessor());
  boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(9000));
  boost::shared_ptr<TTransportFactory> transportFactory(new TServerSocketTransportFactory());

  TSimpleServer server(processor,
      serverTransport,
      transportFactory,
      protocolFactory);
  
  printf("Starting the server...\n");
  server.serve();
  printf("done.\n");
  return 0;

}

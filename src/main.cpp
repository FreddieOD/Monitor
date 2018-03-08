#include "HelloHandler.h"
#include "pistache/endpoint.h"
using namespace Pistache;

int main(){
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
    auto opts = Pistache::Http::Endpoint::options().threads(1);

    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(Http::make_handler<HelloHandler>());
    server.serve();

    server.shutdown();
    std::cout << "ending server" << std::endl;
    return 0;
}
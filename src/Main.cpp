#include <iostream>
#include "Types.h"
#include "UciClient.h"

int main(int count, char* values[])
{
    std::cout << ENGINE_ANCII_ART  << std::endl;
    std::cout << ENGINE_VERSION << std::endl;
    std::cout << "Homepage and source code: " << HOMEPAGE << std::endl;
    std::shared_ptr<UciClient> uci_client = std::make_shared<UciClient>();
    uci_client->Init();
    uci_client->Run();
    return 0;   
}
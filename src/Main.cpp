#include <iostream>
#include "Info.h"
#include "Types.h"
#include "UciClient.h"

int main(int count, char* values[])
{
    // Init client first
    std::shared_ptr<UciClient> uci_client = std::make_shared<UciClient>();
    uci_client->Init();

    std::cout << ENGINE_ANCII_ART  << std::endl;
    std::cout << ENGINE_VERSION << std::endl;
    std::cout << "Homepage and source code: " << HOMEPAGE << std::endl;
    uci_client->Run();
    return 0;   
}
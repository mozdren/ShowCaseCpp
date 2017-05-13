#include "CzechHelloService.hpp"
#include "EnglishHelloService.hpp"
#include "GermanHelloService.hpp"

#include <iostream>

/**
 * Prints hello world message using shared pointer to a service.
 *
 * @param servicePtr shared pointer to a service that provides the hello string
 */
void printHelloWorld(std::shared_ptr<Services::IHelloService> servicePtr)
{
  // check pointer to the service
  if (servicePtr)
  {
    // get hello string result
    auto helloResult = servicePtr->getHelloString();
    
    // check the result of the service call
    if (helloResult.isSuccess()) 
    {
      // if OK pring hello
      std::cout << helloResult.getValue() << std::endl;
    }
    else
    {
      // else print error message
      std::cerr << helloResult.getMessage() << std::endl;
    }
  }
  else 
  {
    std::cerr << "Could not get the service pointer!" << std::endl;
  }
}

int main()
{
  // Get services
  auto czService = Services::CzechHelloService::GetService();
  auto geService = Services::GermanHelloService::GetService();
  auto enService = Services::EnglishHelloService::GetService();

  printHelloWorld(czService);
  printHelloWorld(geService);
  printHelloWorld(enService);
  
  return 0;
}


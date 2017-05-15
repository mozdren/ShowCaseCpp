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

  // testing async method calls
  if (!czService || !geService || !enService)
  {
    std::cerr << "Could not get services!" << std::endl;
    return 0;
  }

  try 
  {
    auto czResultFuture = czService->getHelloStringAsync();
    auto geResultFuture = geService->getHelloStringAsync();
    auto enResultFuture = enService->getHelloStringAsync();

    czResultFuture.wait();
    geResultFuture.wait();
    enResultFuture.wait();

    Services::StringResult czResult = czResultFuture.get();
    Services::StringResult geResult = geResultFuture.get();
    Services::StringResult enResult = enResultFuture.get();

    if (czResult.isSuccess() && 
        geResult.isSuccess() && 
        enResult.isSuccess())
    {
      std::cout 
        << czResult.getValue() << std::endl
        << geResult.getValue() << std::endl
        << enResult.getValue() << std::endl;
    }
    else
    {
      std::cerr << "Could'n get hello string" << std::endl;
    }
  }
  catch(const std::future_error &error)
  {
    std::cerr << error.what() << std::endl;
  }

  return 0;
}


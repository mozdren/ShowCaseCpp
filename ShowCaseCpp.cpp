#include "CzechHelloService.hpp"
#include "EnglishHelloService.hpp"
#include "GermanHelloService.hpp"

#include <iostream>

int main()
{
  auto czService = Services::CzechHelloService::GetService();
  auto geService = Services::GermanHelloService::GetService();
  auto enService = Services::EnglishHelloService::GetService();

  // get czech hello service
  if (czService)
  {
    auto helloResult = czService->getHelloString();
    if (helloResult.isSuccess()) 
    {
      std::cout << helloResult.getValue() << std::endl;
    }
    else
    {
      std::cerr << helloResult.getMessage() << std::endl;
    }
  }
  else 
  {
    std::cerr << "Could not get czech service!" << std::endl;
  }

  // get german hello service
  if (geService)
  {
    auto helloResult = geService->getHelloString();
    if (helloResult.isSuccess())
    {
      std::cout << helloResult.getValue() << std::endl;
    }
    else
    {
      std::cerr << helloResult.getMessage() << std::endl;
    }
  }
  else 
  {
    std::cerr << "Could not get german service!" << std::endl;
  }

  // get english hello service
  if (enService)
  {
    auto helloResult = enService->getHelloString();
    if (helloResult.isSuccess())
    {
      std::cout << helloResult.getValue() << std::endl;
    }
    else
    {
      std::cerr << helloResult.getMessage() << std::endl;
    }
  }
  else
  {
    std::cerr << "Could not get english service!" << std::endl;
  }
}


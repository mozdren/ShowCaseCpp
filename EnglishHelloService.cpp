#include "EnglishHelloService.hpp"

namespace Services
{
  /// returns english hello string 
  StringResult EnglishHelloService::getHelloString()
  {
    return StringResult::Success("Hello, World!");
  }

  /// returns service name
  const std::string EnglishHelloService::getName()
  {
    return "English Hello Service";
  }

  /// constructor
  EnglishHelloService::EnglishHelloService()
  {
  }

  /// destructor
  EnglishHelloService::~EnglishHelloService()
  {
  }

}

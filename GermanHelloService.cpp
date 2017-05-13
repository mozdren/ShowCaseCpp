#include "GermanHelloService.hpp"

namespace Services
{
  /// Returns german hello world string
  StringResult GermanHelloService::getHelloString()
  {
    return StringResult::Success("Hallo, Welt!");
  }

  /// Returns service name
  const std::string GermanHelloService::getName()
  {
    return "German Hello Service";
  }

  /// Constructor
  GermanHelloService::GermanHelloService()
  {
  }

  /// Destructor
  GermanHelloService::~GermanHelloService()
  {
  }

}

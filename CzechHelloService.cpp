#include "CzechHelloService.hpp"

namespace Services
{
  /// returns czech hello string
  StringResult CzechHelloService::getHelloString()
  {
    return StringResult::Success("Ahoj, Svete!");
  }

  /// returns name of the service
  const std::string CzechHelloService::getName()
  {
    return "Czech Hello Service";
  }
 
  /// constructor
  CzechHelloService::CzechHelloService()
  {
  }

  /// destructor
  CzechHelloService::~CzechHelloService()
  {
  }

}

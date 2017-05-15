#include "CzechHelloService.hpp"

namespace Services
{
  // Constants

  /// Hello string in czech language.
  const char* HELLO_STRING_CZ = "Ahoj, Svete!";

  /// Service name
  const char* SERVICE_NAME_CZ = "English Hello Service";

  // Local methods

  /// Create hello result
  StringResult createCzechHelloStringResult()
  {
    return StringResult::Success(HELLO_STRING_CZ);
  }

  // class implementation

  /// returns english hello string
  StringResult CzechHelloService::getHelloString()
  {
    return createCzechHelloStringResult();
  }

  /// returns name of the service
  const std::string CzechHelloService::getName()
  {
    return SERVICE_NAME_CZ;
  }

  /// returns hello string asynchronously
  std::future<StringResult> CzechHelloService::getHelloStringAsync()
  {
    return std::async(createCzechHelloStringResult);
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

#include "GermanHelloService.hpp"

namespace Services
{
  // Constants

  /// Hello string in czech language.
  const char* HELLO_STRING_GE = "Hallo, Welt!";

  /// Service name
  const char* SERVICE_NAME_GE = "English Hello Service";

  // Local methods

  /// Create hello result
  StringResult createGermanHelloStringResult()
  {
    return StringResult::Success(HELLO_STRING_GE);
  }

  // class implementation

  /// returns english hello string
  StringResult GermanHelloService::getHelloString()
  {
    return createGermanHelloStringResult();
  }

  /// returns name of the service
  const std::string GermanHelloService::getName()
  {
    return SERVICE_NAME_GE;
  }

  /// returns hello string asynchronously
  std::future<StringResult> GermanHelloService::getHelloStringAsync()
  {
    return std::async(createGermanHelloStringResult);
  }
 
  /// constructor
  GermanHelloService::GermanHelloService()
  {
  }

  /// destructor
  GermanHelloService::~GermanHelloService()
  {
  }

}

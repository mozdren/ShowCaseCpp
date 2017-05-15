#include "EnglishHelloService.hpp"

namespace Services
{
  // Constants

  /// Hello string in czech language.
  const char* HELLO_STRING_EN = "Hello, World!";

  /// Service name
  const char* SERVICE_NAME_EN = "English Hello Service";

  // Local methods

  /// Create hello result
  StringResult createEnglishHelloStringResult()
  {
    return StringResult::Success(HELLO_STRING_EN);
  }

  // class implementation

  /// returns english hello string
  StringResult EnglishHelloService::getHelloString()
  {
    return createEnglishHelloStringResult();
  }

  /// returns name of the service
  const std::string EnglishHelloService::getName()
  {
    return SERVICE_NAME_EN;
  }

  /// returns hello string asynchronously
  std::future<StringResult> EnglishHelloService::getHelloStringAsync()
  {
    return std::async(createEnglishHelloStringResult);
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

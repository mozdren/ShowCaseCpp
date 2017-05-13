#pragma once

#include "Service.hpp"
#include "IHelloService.hpp"

namespace Services
{

  /// English hello service
  class EnglishHelloService : 
    public Service<EnglishHelloService>, 
    public IHelloService
  {
  public:

    // definitions for Service

    /**
    * Returns service name.
    *
    * @return service name
    */
    virtual const std::string getName() override;

    // definitions for IHelloService

    /**
    * Returns hello string in czech language.
    *
    * @return hello string in czech language
    */
    virtual StringResult getHelloString() override;

    /// Destructor
    ~EnglishHelloService();

    /// Constructor
    EnglishHelloService();
  };

}

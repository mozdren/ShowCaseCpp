#pragma once

#include "Service.hpp"
#include "IHelloService.hpp"

namespace Services
{

  /// German hello service class.
  class GermanHelloService : 
    public Service<GermanHelloService>,
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
    * Returns hello string in german language.
    *
    * @return hello string in german language
    */
    virtual StringResult getHelloString() override;

    /// Destructor
    ~GermanHelloService();

    /// Constructor
    GermanHelloService();
  };

}

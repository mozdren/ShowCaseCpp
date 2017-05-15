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
    * Returns hello string in english language.
    *
    * @return hello string in english language
    */
    virtual StringResult getHelloString() override;

    /**
     * Returns hello string in english language asynchronously.
     *
     * @return future hello string in english language
     */
    virtual std::future<StringResult> getHelloStringAsync() override;

    /// Destructor
    ~EnglishHelloService();

    /// Constructor
    EnglishHelloService();
  };

}

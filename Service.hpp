#pragma once

#include <memory>
#include <string>

namespace Services
{

  /// Service template
  template <class TServiceClass>
  class Service
  {
  public:

    // friendly classes

    friend class CzechHelloService;
    friend class EnglishHelloService;
    friend class GermanHelloService;

    /**
     * Returs shared pointer to a singleton of a service.
     *
     * @return shared pointer to a service
     */
    static std::shared_ptr<TServiceClass> GetService()
    {
      static auto servicePtr = std::shared_ptr<TServiceClass>(new TServiceClass());
      return servicePtr;
    }

    /**
     * Pure virtual method returning name of the service.
     *
     * @return service name
     */
    virtual const std::string getName() = 0;

    /// Destructor
    ~Service() {}

  private:

    /// Constructor
    Service() {}

  };

}

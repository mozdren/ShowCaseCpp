#pragma once

#include <future>

#include "BasicResults.hpp"

namespace Services
{

  /// Abstract overview of the interface of all Hello Services
  class IHelloService
  {
  public:

    /**
     * Method returning hello string.
     *
     * @return object that will contain the result
     */
    virtual StringResult getHelloString() = 0;

    /**
     * Async method returning hello string
     *
     * @return result object containing result in the future object
     */
    virtual std::future<StringResult> getHelloStringAsync() = 0;
  };

}


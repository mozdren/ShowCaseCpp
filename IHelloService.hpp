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
     * Async method returning hello string.
     *
     * @return object that will contain the result
     */
    virtual StringResult getHelloString() = 0;

  };

}


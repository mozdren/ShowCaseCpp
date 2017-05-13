#pragma once

#include "ValueResult.hpp"

#include <string>

namespace Services {

  /// Basic String Result
  typedef ValueResult<std::string>        StringResult;

  /// Basic Integer Result
  typedef ValueResult<int>                IntResult;

  /// Basic Unsigned Integer Result
  typedef ValueResult<unsigned>           UIntResult;

  /// Basic Character Result
  typedef ValueResult<char>               CharResult;

  /// Basic Unsigned Character Result
  typedef ValueResult<unsigned char>      UCharResult;

  /// Basic Long Result
  typedef ValueResult<long>               LongResult;

  /// Basic Long Long Result
  typedef ValueResult<long long>          LongLongResult;

  /// Basic Unsigned Long Result
  typedef ValueResult<unsigned long>      ULongResult;

  /// Basic Unsigned Long Long Result
  typedef ValueResult<unsigned long long> ULongLongResult;

  /// Basic Short Result
  typedef ValueResult<short>              ShortResult;

  /// Basic Unsigned Short Result
  typedef ValueResult<unsigned short>     UShortResult;

  /// Basic Float Result
  typedef ValueResult<float>              FloatResult;

  /// Basic Double Result
  typedef ValueResult<double>             DoubleResult;

}

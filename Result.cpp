#include "Result.hpp"

namespace Services
{

  /// Copy constructor
  Result::Result(const Result & result) :
    m_Message(result.m_Message),
    m_ResultType(result.m_ResultType)
  {
    // nothing here
  }

  /// Default constructor
  Result::Result() :
    m_Message(""),
    m_ResultType(ResultType::Success)
  {
    // nothing there
  }

  /// Specific constructor with message and type
  Result::Result(std::string message, ResultType resultType) :
    m_Message(message),
    m_ResultType(resultType)
  {
    // nothin there
  }

  /// Destructor
  Result::~Result()
  {
    // nothing there
  }

  /// returns the type of the result
  ResultType Result::getType() const
  {
    return m_ResultType;
  }

  /// sets the type of the result
  void Result::setType(ResultType resultType)
  {
    m_ResultType = resultType;
  }

  /// resurns true if result type is Success
  bool Result::isSuccess() const
  {
    return m_ResultType == ResultType::Success;
  }

  /// returns true if result type is not Success
  bool Result::isNotSuccess() const
  {
    return m_ResultType != ResultType::Success;
  }

  /// returns the result message
  std::string Result::getMessage() const
  {
    return m_Message;
  }

  /// Sets the result message
  void Result::setMessage(std::string message)
  {
    m_Message = message;
  }

  /// Create success result
  Result Result::Success()
  {
    return Result("", ResultType::Success);
  }

  /// Create success result with message
  Result Result::Success(std::string message)
  {
    return Result(message, ResultType::Success);
  }

  /// Create warnign result
  Result Result::Warning()
  {
    return Result("", ResultType::Warning);
  }

  /// Create warning result with message
  Result Result::Warning(std::string message)
  {
    return Result(message, ResultType::Warning);
  }

  /// Create error result
  Result Result::Error()
  {
    return Result("", ResultType::Error);
  }

  /// Create error result with message
  Result Result::Error(std::string message)
  {
    return Result(message, ResultType::Error);
  }

  /// Create fatal result
  Result Result::Fatal()
  {
    return Result("", ResultType::Fatal);
  }

  /// Create fatal result with message
  Result Result::Fatal(std::string message)
  {
    return Result(message, ResultType::Fatal);
  }

  /// serialization of a result to a output stream in the JSON format
  std::ostream & operator<<(std::ostream & stream, Result & result)
  {
    return stream
      << "{\"IsSuccess\":" << (result.isSuccess() ? "true" : "false")
      << ",\"message\":\"" << result.getMessage() << "\"}";
  }
}

#pragma once

#include "Result.hpp"

namespace Services
{

  /// Class representing a general result.
  template <class TValue>
  class ValueResult :
    public Result
  {
  public:

    /**
    * Creates a success result with a specific value.
    *
    * @return Returns a success result.
    */
    static ValueResult Success(TValue value)
    {
      return ValueResult(value, "", ResultType::Success);
    }

    /**
    * Creates a success result with a specific value and message.
    *
    * @return Returns a success result.
    */
    static ValueResult Success(TValue value, std::string message) 
    {
      return ValueResult(value, message, ResultType::Success);
    }

    /**
    * Creates a warning result with a specific value.
    *
    * @return Returns a warning result
    */
    static ValueResult Warning(TValue value) 
    {
      return ValueResult(value, "", ResultType::Warning);
    }

    /**
    * Creates a warning result with a specific value and message.
    *
    * @return Returns a warning result.
    */
    static ValueResult Warning(TValue value, std::string message) 
    {
      return ValueResult(value, message, ResultType::Warning);
    }

    /**
    * Creates an error result.
    *
    * @return Returns a error result.
    */
    static ValueResult Error() 
    {
      return ValueResult("", ResultType::Error);
    }

    /**
    * Creates an error result with a specific message.
    *
    * @return Returns a error result.
    */
    static ValueResult Error(std::string message) 
    {
      return ValueResult(message, ResultType::Error);
    }

    /**
    * Creates a fatal result.
    *
    * @return Returns a fatal result.
    */
    static ValueResult Fatal() 
    {
      return ValueResult("", ResultType::Fatal);
    }

    /**
    * Creates a fatal result with a specific message.
    *
    * @return Returns a fatal result.
    */
    static ValueResult Fatal(std::string message) 
    {
      return ValueResult(message, ResultType::Fatal);
    }

    /**
    * Sets the result value.
    *
    * @param value The value to be set to the result
    */
    void setValue(TValue value) { m_Value = value; }

    /**
    * Returns the results value.
    *
    * @return returns the value of the result.
    */
    TValue getValue() { return m_Value; }

    /**
     * Destructor.
     */
    ~ValueResult()
    {
    }

    /**
    * Copy constructor.
    *
    * @param copyItem item to be copied
    */
    ValueResult(const ValueResult<TValue> &valueResult) :
      m_Value(valueResult.m_Value)
    {
      setMessage(valueResult.getMessage());
      setType(valueResult.getType());
    }

  private:

    /// Private constructor
    ValueResult()
    {
      setMessage("");
      setType(ResultType::Success);
    }

    /**
     * Private constructcor setting message and result type.
     *
     * @param message Message to be set to the result
     * @param resultType result type
     */
    ValueResult(std::string message, ResultType resultType)
    {
      setMessage(message);
      setType(resultType);
    }

    /**
     * Private constructor setting value, message, and result type.
     *
     * @param value Value of the result
     * @param message Message of the result
     * @param resultType Result type
     */
    ValueResult(TValue value, std::string message, ResultType resultType) :
      m_Value(value)
    {
      setMessage(message);
      setType(resultType);
    }

    /// Value of a template type which holds the result data.
    TValue m_Value;

  };

}


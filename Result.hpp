#pragma once

#include <string>
#include <ostream>

#include "Enums.hpp"

namespace Services
{

  /**
   * This class represents a base result to be used by all specific results as a base class.
   * The constructor of this class is private and only static factory methods Create should
   * be used.
   */
  class Result
  {
  public:

    /// Making Value Result a friend class
    template <class TValue> friend class ValueResult;
    
    /**
     * Provides the result type of the result.
     *
     * @return result type
     */
    ResultType getType() const;

    /**
     * Sets result type of the result.
     *
     * @param resultType the result to be set
     */
    void setType(ResultType resultType);

    /**
     * Returns true if result type is success.
     *
     * @return true if result type is success
     */
    bool isSuccess() const;

    /**
     * Returns frue is result type is not success.
     *
     * @return true if result type us not success
     */
    bool isNotSuccess() const;

    /**
     * Returns the message stored in the result.
     *
     * @return message stored in the result
     */
    std::string getMessage() const;

    /**
     * Sets the message to be stored in the result.
     *
     * @param message the message to be set
     */
    void setMessage(std::string message);

    /// Static Result Factories

    /**
     * Creates a success result. This type of result should be used only if everything
     * went as planned.
     *
     * @return Returns a success result.
     */
    static Result Success();

    /**
     * Creates a success result with a message. This type of result should be used only if
     * everything went as planned.
     *
     * @param message The message to be set to the result.
     * @return Returns a success result with message.
     */
    static Result Success(std::string message);

    /**
    * Creates a warning result. This message should be used if something went wrong, but
    * doesn't influence the result.
    *
    * @return Returns a warning result.
    */
    static Result Warning();

    /**
    * Creates a success result with a message. This message should be used if something
    * went wrong, but doesn't influence the result.
    *
    * @param message The message to be set to the result.
    * @return Returns a warning result with message.
    */
    static Result Warning(std::string message);

    /**
    * Creates an error result. This type of message should be used only for result that
    * represent an error, but not exceptions etc.
    *
    * @return Returns an error result.
    */
    static Result Error();

    /**
    * Creates a error result with a message. This type of message should be used only
    * for result that represent an error, but not exceptions etc.
    *
    * @param message The message to be set to the result.
    * @return Returns a error result with message.
    */
    static Result Error(std::string message);

    /**
    * Creates a fatal result. This result type should be used only if something went
    * terribly wrong (e.g. exeption while oppenig file).
    *
    * @return Returns a fatal result.
    */
    static Result Fatal();

    /**
    * Creates a success result with a message.. This result type should be used only if something went
    * terribly wrong (e.g. exeption while oppenig file).
    *
    * @param message The message to be set to the result.
    * @return Returns a fatal result with message.
    */
    static Result Fatal(std::string message);

    /// Destructor
    ~Result();

    /**
    * Copy constructor.
    *
    * @param The object reference to be copied.
    */
    Result(const Result &result);

    /**
     * Definition of a friend method to provide objects serialization to output stream in a JSON format.
     * 
     * @param stream reference to a stream
     * @param result result to be serialized
     * @return reference to resulting output stream
     */
    friend std::ostream& operator<< (std::ostream& stream, Result& result);

  private:

    /// represents result type
    ResultType m_ResultType;

    /// string value holding the message of the result
    std::string m_Message;

    /// A private constructor which should not be used from the outside.
    Result();

    /**
     * Private constructor with result type and message
     *
     * @param message the message of the result
     * @param resultType the type of the result
     */
    Result(std::string message, ResultType resultType);
  };

}

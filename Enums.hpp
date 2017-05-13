#pragma once

namespace Services
{

  /// Represents possible result types
  enum ResultType
  {
    /// Represents a result of an operation that was completely successful.
    Success,

    /// Represents a result of an operation that was successful with a small warning which doesnt influence the result data.
    Warning,

    /// Represents a result of an operation that was not successful, but there were no exceptions.
    Error,

    /// Represents a result representing a failiure in the code (e.g exception while reading file).
    Fatal
  };

}
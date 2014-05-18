//--------------------------------------------------------------------*- C++ -*-
// CLING - the C++ LLVM-based InterpreterG :)
// author:  Axel Naumann <axel@cern.ch>
//
// This file is dual-licensed: you can choose to license it under the University
// of Illinois Open Source License or the GNU Lesser General Public License. See
// LICENSE.TXT for details.
//------------------------------------------------------------------------------

#ifndef CLING_VALUEPRINTER_H
#define CLING_VALUEPRINTER_H

namespace llvm {
  class raw_ostream;
}

namespace cling {
  class Value;

  ///\brief Generic interface to value printing.
  ///
  /// Can be re-implemented to print type-specific details, e.g. as
  ///\code
  ///   template <typename POSSIBLYDERIVED>
  ///   std::string printValue(const MyClass* const p, POSSIBLYDERIVED* ac,
  ///                          const Value& V);
  ///\endcode
  //template <typename TY>
  //std::string printValue(const void* const p, TY* const u,
  //                       const Value& V);

  ///\brief Generic interface to type printing.
  ///
  /// Can be re-implemented to print a user type differently, e.g. as
  ///\code
  ///   template <typename POSSIBLYDERIVED>
  ///   std::string printType(const MyClass* const p, POSSIBLYDERIVED* ac,
  ///                         const Value& V);
  ///\endcode
  //template <typename TY>
  //std::string printType(const void* const p, TY* const u,
  //                      const Value& V);
  namespace valuePrinterInternal {
    void printValue_Default(llvm::raw_ostream& o, const Value& V);
    void printType_Default(llvm::raw_ostream& o, const Value& V);
  } // end namespace valuePrinterInternal
}

#endif // CLING_VALUEPRINTER_H

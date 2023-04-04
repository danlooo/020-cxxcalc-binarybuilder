#include <type_traits>
#include "jlcxx/jlcxx.hpp"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

#include "jlCxxCalc.h"

#ifdef VERBOSE_IMPORT
#  define DEBUG_MSG(a) std::cerr << a << "\n"
#else
#  define DEBUG_MSG(a)
#endif
#define __HERE__  __FILE__ ":" QUOTE2(__LINE__)
#define QUOTE(arg) #arg
#define QUOTE2(arg) QUOTE(arg)

namespace jlcxx {
  template<> struct IsMirroredType<CxxCalculator> : std::false_type { };
}

JLCXX_MODULE define_julia_module(jlcxx::Module& types){

  DEBUG_MSG("Adding wrapper for type CxxCalculator (" __HERE__ ")");
  // defined in ./CxxCalc.cpp:5:7
  auto t0 = types.add_type<CxxCalculator>("CxxCalculator");

  /**********************************************************************/
  /* Wrappers for the methods of class CxxCalculator
   */


  DEBUG_MSG("Adding wrapper for void CxxCalculator::CxxCalculator(const char *) (" __HERE__ ")");
  // defined in ./CxxCalc.cpp:8:5
  t0.constructor<>();
  t0.constructor<const char *>();

  DEBUG_MSG("Adding wrapper for void CxxCalculator::say_hello() (" __HERE__ ")");
  // signature to use in the veto list: void CxxCalculator::say_hello()
  // defined in ./CxxCalc.cpp:10:10
  t0.method("say_hello", static_cast<void (CxxCalculator::*)()  const>(&CxxCalculator::say_hello));

  DEBUG_MSG("Adding wrapper for double CxxCalculator::cxx_add(double, double) (" __HERE__ ")");
  // signature to use in the veto list: double CxxCalculator::cxx_add(double, double)
  // defined in ./CxxCalc.cpp:22:19
  t0.method("CxxCalculator!cxx_add", static_cast<double (*)(double, double) >(&CxxCalculator::cxx_add));

  DEBUG_MSG("Adding wrapper for double CxxCalculator::cxx_subtract(double, double) (" __HERE__ ")");
  // signature to use in the veto list: double CxxCalculator::cxx_subtract(double, double)
  // defined in ./CxxCalc.cpp:34:19
  t0.method("CxxCalculator!cxx_subtract", static_cast<double (*)(double, double) >(&CxxCalculator::cxx_subtract));

  DEBUG_MSG("Adding wrapper for double CxxCalculator::cxx_multiply(double, double) (" __HERE__ ")");
  // signature to use in the veto list: double CxxCalculator::cxx_multiply(double, double)
  // defined in ./CxxCalc.cpp:46:19
  t0.method("CxxCalculator!cxx_multiply", static_cast<double (*)(double, double) >(&CxxCalculator::cxx_multiply));

  DEBUG_MSG("Adding wrapper for double CxxCalculator::cxx_divide(double, double) (" __HERE__ ")");
  // signature to use in the veto list: double CxxCalculator::cxx_divide(double, double)
  // defined in ./CxxCalc.cpp:58:19
  t0.method("CxxCalculator!cxx_divide", static_cast<double (*)(double, double) >(&CxxCalculator::cxx_divide));

  DEBUG_MSG("Adding wrapper for double CxxCalculator::add(double, double) (" __HERE__ ")");
  // signature to use in the veto list: double CxxCalculator::add(double, double)
  // defined in ./CxxCalc.cpp:63:19
  t0.method("CxxCalculator!add", static_cast<double (*)(double, double) >(&CxxCalculator::add));

  /* End of CxxCalculator class method wrappers
   **********************************************************************/

  /**********************************************************************
   * Wrappers for global functions and variables including
   * class static members
   */

  DEBUG_MSG("Adding wrapper for int main(int, const char *[]) (" __HERE__ ")");
  // signature to use in the veto list: int main(int, const char *[])
  // defined in ./CxxCalc.cpp:72:5
  types.method("main", static_cast<int (*)(int, const char *[]) >(&main));
  /* End of global function wrappers
   **********************************************************************/

  DEBUG_MSG("End of wrapper definitions");

}

// bslmf_isreference.t.cpp                                            -*-C++-*-
#include <bslmf_isreference.h>

#include <iostream>
#include <cstdlib>

using namespace std;
using namespace bsl;
using namespace BloombergLP;

//=============================================================================
//                                TEST PLAN
//-----------------------------------------------------------------------------
//                                Overview
//                                --------
// The object under test is a meta-function, 'bsl::is_reference', which
// determine whether a template parameter type is a reference type.  Thus, we
// need to ensure that the value returned by this meta-functions is correct for
// each possible category of types.
//
// ----------------------------------------------------------------------------
// PUBLIC CLASS DATA
// [ 1] bsl::is_reference::value
//
// ----------------------------------------------------------------------------
// [ 2] USAGE EXAMPLE

//=============================================================================
//                  STANDARD BDE ASSERT TEST MACRO
//-----------------------------------------------------------------------------

static int testStatus = 0;

static void aSsErT(int c, const char *s, int i)
{
    if (c) {
        cout << "Error " << __FILE__ << "(" << i << "): " << s
             << "    (failed)" << endl;
        if (testStatus >= 0 && testStatus <= 100) ++testStatus;
    }
}

#define ASSERT(X) { aSsErT(!(X), #X, __LINE__); }
//-----------------------------------------------------------------------------
#define LOOP_ASSERT(I,X) { \
    if (!(X)) { cout << #I << ": " << I << "\n"; aSsErT(1, #X, __LINE__);}}

#define LOOP2_ASSERT(I,J,X) { \
    if (!(X)) { cout << #I << ": " << I << "\t" << #J << ": " \
        << J << "\n"; aSsErT(1, #X, __LINE__); } }
//=============================================================================
#define P(X) cout << #X " = " << (X) << endl; // Print identifier and value.
#define Q(X) cout << "<| " #X " |>" << endl;  // Quote identifier literally.
#define P_(X) cout << #X " = " << (X) << ", " << flush; // P(X) without '\n'
#define L_ __LINE__                           // current Line number
#define T_() cout << '\t' << flush;           // Print tab w/o linefeed.

//=============================================================================
//                  GLOBAL TYPEDEFS/CONSTANTS FOR TESTING
//-----------------------------------------------------------------------------

namespace {

enum   EnumTestType {
    // This user-defined 'enum' type is intended to be used during testing as
    // an argument for the template parameter 'TYPE' of 'bsl::is_reference'.
};

struct StructTestType {
    // This user-defined 'struct' type is intended to be used during testing as
    // an argument for the template parameter 'TYPE' of 'bsl::is_reference'.
};

union  UnionTestType {
    // This user-defined 'union' type is intended to be used during testing as
    // an argument for the template parameter 'TYPE' of 'bsl::is_reference'.
};

class  BaseClassTestType {
    // This user-defined base class type is intended to be used during testing
    // as an argument for the template parameter 'TYPE' of 'bsl::is_reference'.
};

class  DerivedClassTestType : public BaseClassTestType {
    // This user-defined derived class type is intended to be used during
    // testing as an argument for the template parameter 'TYPE' of
    // 'bsl::is_reference'.
};

typedef int (StructTestType::*MethodPtrTestType) ();
    // This non-static function member type is intended to be used during
    // testing as an argument for the template parameter 'TYPE' of
    // 'bsl::is_reference'.

typedef void (*FunctionPtrTestType) ();
    // This function pointer type is intended to be used during testing as an
    // argument as an argument for the template parameter 'TYPE' of
    // 'bsl::is_reference'.

typedef int StructTestType::* PMD;
    // This class public data member pointer type is intended to be used during
    // testing as an argument as an argument for the template parameter 'TYPE'
    // of 'bsl::is_reference'.

struct Incomplete;
    // This incomplete 'struct' type is intended to be used during testing as
    // an argument as an argument for the template parameter 'TYPE' of
    // 'bsl::is_reference'.

}  // close unnamed namespace

#define TYPE_ASSERT_CVQ_SUFFIX(metaFunc, member, type, result)                \
    ASSERT(result == metaFunc<type>::member);                                 \
    ASSERT(result == metaFunc<type const>::member);                           \
    ASSERT(result == metaFunc<type volatile>::member);                        \
    ASSERT(result == metaFunc<type const volatile>::member);

#define TYPE_ASSERT_CVQ_PREFIX(metaFunc, member, type, result)                \
    ASSERT(result == metaFunc<type>::member);                                 \
    ASSERT(result == metaFunc<const type>::member);                           \
    ASSERT(result == metaFunc<volatile type>::member);                        \
    ASSERT(result == metaFunc<const volatile type>::member);

#define TYPE_ASSERT_CVQ_REF(metaFunc, member, type, result)                   \
    ASSERT(result == metaFunc<type&>::member);                                \
    ASSERT(result == metaFunc<type const&>::member);                          \
    ASSERT(result == metaFunc<type volatile&>::member);                       \
    ASSERT(result == metaFunc<type const volatile&>::member);

#define TYPE_ASSERT_CVQ_RREF(metaFunc, member, type, result)                  \
    ASSERT(result == metaFunc<type&&>::member);                               \
    ASSERT(result == metaFunc<type const&&>::member);                         \
    ASSERT(result == metaFunc<type volatile&&>::member);                      \
    ASSERT(result == metaFunc<type const volatile&&>::member);

#define TYPE_ASSERT_CVQ(metaFunc, member, type, result)                       \
    TYPE_ASSERT_CVQ_SUFFIX(metaFunc, member, type, result);                   \
    TYPE_ASSERT_CVQ_SUFFIX(metaFunc, member, const type, result);             \
    TYPE_ASSERT_CVQ_SUFFIX(metaFunc, member, volatile type, result);          \
    TYPE_ASSERT_CVQ_SUFFIX(metaFunc, member, const volatile type, result);


//=============================================================================
//                              MAIN PROGRAM
//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    int test = argc > 1 ? atoi(argv[1]) : 0;
    int verbose = argc > 2;
    int veryVerbose = argc > 3;

    cout << "TEST " << __FILE__ << " CASE " << test << endl;

    switch (test) { case 0:
      case 2: {
        // --------------------------------------------------------------------
        // USAGE EXAMPLE
        //
        // Concerns:
        //: 1 The usage example provided in the component header file compiles,
        //:   links, and runs as shown.
        //
        // Plan:
        //: 1 Incorporate usage example from header into test driver, remove
        //:   leading comment characters, and replace 'assert' with 'ASSERT'.
        //:   (C-1)
        //
        // Testing:
        //   USAGE EXAMPLE
        // --------------------------------------------------------------------

        if (verbose) cout << endl << "USAGE EXAMPLE" << endl
                                  << "=============" << endl;


      } break;
      case 1: {
        // --------------------------------------------------------------------
        // 'bsl::is_reference::value'
        //   Ensure that the static data member 'value' of
        //   'bsl::is_reference' instantiations having various (template
        //   parameter) 'TYPES' has the correct value.
        //
        // Concerns:
        //: 1 'is_reference::value' is 'false' when 'TYPE' is a (possibly
        //:   cv-qualified) primitive type.
        //:
        //: 2 'is_reference::value' is 'false' when 'TYPE' is a (possibly
        //:   cv-qualified) user-defined type.
        //:
        //: 3 'is_reference::value' is 'false' when 'TYPE' is a (possibly
        //:   cv-qualified) pointer type.
        //:
        //: 4 'is_reference::value' is 'true' when 'TYPE' is a (possibly
        //:   cv-qualified) lvalue or rvalue reference type.
        //:
        //: 5 'is_reference::value' is 'false' when 'TYPE' is a (possibly
        //:   cv-qualified) function type.
        //
        // Plan:
        //   Verify that 'bsl::is_reference::value' has the correct value for
        //   each (template parameter) 'TYPE' in the concerns.
        //
        // Testing:
        //   bsl::is_reference::value
        // --------------------------------------------------------------------

        if (verbose) cout << endl
                          << "bsl::is_reference::value" << endl
                          << "========================" << endl;

        // C-1
        TYPE_ASSERT_CVQ_SUFFIX(bsl::is_reference, value, void, false);
        TYPE_ASSERT_CVQ_SUFFIX(bsl::is_reference, value, int,  false);

        // C-2
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_reference, value, EnumTestType,         false);
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_reference, value, StructTestType,       false);
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_reference, value, UnionTestType,        false);
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_reference, value, BaseClassTestType,    false);
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_reference, value, DerivedClassTestType, false);

        // C-3
        TYPE_ASSERT_CVQ(
                   bsl::is_reference, value, int*,                      false);
        TYPE_ASSERT_CVQ(
                   bsl::is_reference, value, StructTestType*,           false);
        TYPE_ASSERT_CVQ(
                  bsl::is_reference, value, int StructTestType::*,      false);
        TYPE_ASSERT_CVQ(
                  bsl::is_reference, value, int StructTestType::* *,    false);
        TYPE_ASSERT_CVQ(
                  bsl::is_reference, value, UnionTestType*,             false);
        TYPE_ASSERT_CVQ(
                  bsl::is_reference, value, PMD BaseClassTestType::*,   false);
        TYPE_ASSERT_CVQ(
                  bsl::is_reference, value, PMD BaseClassTestType::* *, false);
        TYPE_ASSERT_CVQ(
                  bsl::is_reference, value, BaseClassTestType*,         false);
        TYPE_ASSERT_CVQ(
                  bsl::is_reference, value, DerivedClassTestType*,      false);
        TYPE_ASSERT_CVQ(
                  bsl::is_reference, value, Incomplete*,                false);
        TYPE_ASSERT_CVQ_SUFFIX(
                  bsl::is_reference, value, MethodPtrTestType,          false);
        TYPE_ASSERT_CVQ_SUFFIX(
                  bsl::is_reference, value, FunctionPtrTestType,        false);

        // C-4
        TYPE_ASSERT_CVQ_REF(bsl::is_reference, value, int,  true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_reference, value, EnumTestType,         true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_reference, value, StructTestType,       true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_reference, value, UnionTestType,        true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_reference, value, BaseClassTestType,    true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_reference, value, DerivedClassTestType, true);

        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, int*,                       true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, StructTestType*,            true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, int StructTestType::*,      true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, int StructTestType::* *,    true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, UnionTestType*,             true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, PMD BaseClassTestType::*,   true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, PMD BaseClassTestType::* *, true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, BaseClassTestType*,         true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, DerivedClassTestType*,      true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, Incomplete*,                true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, MethodPtrTestType,          true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_reference, value, FunctionPtrTestType,        true);

#if defined(BSLS_COMPILERFEATURES_SUPPORT_RVALUE_REFERENCES)
        TYPE_ASSERT_CVQ_RREF(bsl::is_reference, value, int,  true);

        TYPE_ASSERT_CVQ_RREF(
                         bsl::is_reference, value, EnumTestType,         true);
        TYPE_ASSERT_CVQ_RREF(
                         bsl::is_reference, value, StructTestType,       true);
        TYPE_ASSERT_CVQ_RREF(
                         bsl::is_reference, value, UnionTestType,        true);
        TYPE_ASSERT_CVQ_RREF(
                         bsl::is_reference, value, BaseClassTestType,    true);
        TYPE_ASSERT_CVQ_RREF(
                         bsl::is_reference, value, DerivedClassTestType, true);

        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, int*,                       true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, StructTestType*,            true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, int StructTestType::*,      true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, int StructTestType::* *,    true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, UnionTestType*,             true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, PMD BaseClassTestType::*,   true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, PMD BaseClassTestType::* *, true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, BaseClassTestType*,         true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, DerivedClassTestType*,      true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, Incomplete*,                true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, MethodPtrTestType,          true);
        TYPE_ASSERT_CVQ_RREF(
                   bsl::is_reference, value, FunctionPtrTestType,        true);
#endif

        // C-5
        TYPE_ASSERT_CVQ_PREFIX(bsl::is_reference, value, int  (int),  false);
        TYPE_ASSERT_CVQ_PREFIX(bsl::is_reference, value, void (void), false);
        TYPE_ASSERT_CVQ_PREFIX(bsl::is_reference, value, int  (void), false);
        TYPE_ASSERT_CVQ_PREFIX(bsl::is_reference, value, void (int),  false);
      } break;
      default: {
        cerr << "WARNING: CASE `" << test << "' NOT FOUND." << endl;
        testStatus = -1;
      }
    }

    if (testStatus > 0) {
        cerr << "Error, non-zero test status = " << testStatus << "." << endl;
    }

    return testStatus;
}

// ----------------------------------------------------------------------------
// Copyright (C) 2012 Bloomberg L.P.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------- END-OF-FILE ----------------------------------
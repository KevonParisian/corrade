/*
    Corrade::Containers::ArrayView
    Corrade::Containers::StaticArrayView
        — lightweight alternatives to std::span / gsl::span

    https://doc.magnum.graphics/corrade/classCorrade_1_1Containers_1_1ArrayView.html
    https://doc.magnum.graphics/corrade/classCorrade_1_1Containers_1_1StaticArrayView.html

    This is a single-header library generated from the Corrade project. With
    the goal being easy integration, it's deliberately free of all comments
    to keep the file size small. More info, detailed changelogs and docs here:

    -   Project homepage — https://magnum.graphics/corrade/
    -   Documentation — https://doc.magnum.graphics/corrade/
    -   GitHub project page — https://github.com/mosra/corrade
    -   GitHub Singles repository — https://github.com/mosra/magnum-singles

    The STL compatibility bits are included as well --- opt-in by specifying
    either `#define CORRADE_ARRAYVIEW_STL_COMPATIBILITY` or
    `#define CORRADE_ARRAYVIEW_STL_SPAN_COMPATIBILITY` before including the
    file. Including it multiple times with different macros defined works too.

    v2020.06-1502-g147e (2023-09-11)
    -   Fixes to the Utility::swap() helper to avoid ambiguity with std::swap()
    v2020.06-1454-gfc3b7 (2023-08-27)
    -   New exceptPrefix() API, the except() API is renamed to exceptSuffix().
        The suffix() API, which took an offset, is removed and will be
        eventually reintroduced again but taking suffix size, consistently with
        prefix() that takes prefix size.
    -   New sliceSize() API, taking a begin + size instead of begin + end
    -   Element access with operator[](), front() and back() is now
        bounds-checked with assertions
    -   The front() and back() APIs are now constexpr
    -   Convenience ArrayView2, ArrayView3, ArrayView4 aliases for
        StaticArrayView
    -   Renamed empty() to isEmpty() for consistency with other bool-returning
        APIs
    -   MSVC 2022 compatibility
    -   Compatibility of the std::span conversion code with C++20 which removes
        the <ciso646> header
    -   Removed dependency on <utility>, resulting in about ~600 preprocessed
        lines less
    v2020.06-0-g61d1b58c (2020-06-27)
    -   Conversion of const types to mutable arrays is now disabled with SFINAE
        to prevent ambiguous constructor overloads
    -   Added arrayCast() overloads from ArrayView<void> and
        ArrayView<const void>
    -   Updated std::span compatibility for libc++ 9.0, which switched away
        from a signed size type
    v2019.10-0-g162d6a7d (2019-10-24)
    -   Fixed OOB access when converting empty STL containers to ArrayView
    v2019.01-301-gefe8d740 (2019-08-05)
    -   MSVC 2019 compatibility
    -   Added except() for taking everything except last N elements
    -   Added StaticArrayView::slice() with compile-time begin and end
    v2019.01-173-ge663b49c (2019-04-30)
    -   Added ArrayView<void> as a counterpart to ArrayView<const void>
    -   Added compile-time-sized StaticArrayView::suffix()
    v2019.01-107-g80d9f347 (2019-03-23)
    -   Including <cassert> only when needed
    v2019.01-41-g39c08d7c (2019-02-18)
    -   Initial release

    Generated from Corrade {{revision}}, {{stats:loc}} / {{stats:preprocessed}} LoC
*/

#include "base.h"
// {{includes}}
#include <cstddef>
#if (!defined(CORRADE_ASSERT) || !defined(CORRADE_CONSTEXPR_ASSERT)) && !defined(NDEBUG)
#include <cassert>
#endif

/* We need just CORRADE_MSVC{,2015}_COMPATIBILITY from configure.h. This is
   equivalent to the version check in UseCorrade.cmake. */
#pragma ACME enable Corrade_configure_h
#ifdef _MSC_VER
#define CORRADE_MSVC_COMPATIBILITY
#endif
#if defined(_MSC_VER) && _MSC_VER < 1910
#define CORRADE_MSVC2015_COMPATIBILITY
#endif

/* We need just the array forward declarations from Containers.h */
#pragma ACME enable Corrade_Containers_Containers_h

/* Disable asserts that are not used. CORRADE_ASSERT and
   CORRADE_CONSTEXPR_DEBUG_ASSERT is used, wrapping the #include <cassert>
   above. When enabling additional asserts, be sure to update it above as
   well -- without the _DEBUG variants, as they just delegate to the non-debug
   version of the macro. */
#include "assert.h"
#pragma ACME forget CORRADE_ASSERT
#pragma ACME forget CORRADE_CONSTEXPR_ASSERT
#pragma ACME forget CORRADE_CONSTEXPR_DEBUG_ASSERT

#ifndef CorradeArrayView_h
#define CorradeArrayView_h
namespace Corrade { namespace Containers {

/* Needs to be defined here because it's referenced before its definition */
template<std::size_t, class> class StaticArrayView;
/* These need to be defined here because the other occurence is guarded with
   #ifndef CORRADE_MSVC2015_COMPATIBILITY */
template<class T> using ArrayView2 = StaticArrayView<2, T>;
template<class T> using ArrayView3 = StaticArrayView<3, T>;
template<class T> using ArrayView4 = StaticArrayView<4, T>;

}}
#endif
#include "Corrade/Containers/ArrayView.h"
#ifdef CORRADE_ARRAYVIEW_STL_COMPATIBILITY
// {{includes}}
#include "Corrade/Containers/ArrayViewStl.h"
#endif
#ifdef CORRADE_ARRAYVIEW_STL_SPAN_COMPATIBILITY
// {{includes}}
#ifdef _MSC_VER
#ifdef _MSVC_LANG
#define CORRADE_CXX_STANDARD _MSVC_LANG
#else
#define CORRADE_CXX_STANDARD 201103L
#endif
#else
#define CORRADE_CXX_STANDARD __cplusplus
#endif
#if CORRADE_CXX_STANDARD > 201703
#include <version>
#else
#include <ciso646>
#endif
#ifdef _LIBCPP_VERSION
#define CORRADE_TARGET_LIBCXX
#endif
#include "Corrade/Containers/ArrayViewStlSpan.h"
#endif

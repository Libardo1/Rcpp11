#ifndef Rcpp_vector_ListOf_h_
#define Rcpp_vector_ListOf_h_

// a define used to clean up some of the code repetition
#define THIS static_cast<List>(this->list)[this->index]
#define LHS  static_cast<List>(lhs.list)[lhs.index]
#define RHS  static_cast<List>(rhs.list)[rhs.index]

namespace Rcpp {

  // operator=
  template <typename T>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator=(const ListOf<T>::ListOfProxy& rhs) {
    THIS = RHS;
    return *this;
  }

  template <typename T>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator=(T vector) {
    THIS = vector;
    return *this;
  }

  // operator+
  template <typename T>
  typename ListOf<T>::ListOfProxy ListOf<T>::ListOfProxy::operator+(const ListOf<T>::ListOfProxy& rhs) {
    THIS = as<T>(THIS) + as<T>(RHS);
    return *this;
  }

  template <typename T>
  template <typename U>
  typename ListOf<T>::ListOfProxy ListOf<T>::ListOfProxy::operator+(const U& rhs) {
    THIS = as<T>(THIS) + rhs;
    return *this;
  }

  template <typename T>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator+=(const ListOf<T>::ListOfProxy& rhs) {
    THIS = as<T>(THIS) + as<T>(RHS);
    return *this;
  }

  template <typename T>
  template <typename U>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator+=(const U& rhs) {
    THIS = as<T>(THIS) + rhs;
    return *this;
  }

  // operator-
  template <typename T>
  typename ListOf<T>::ListOfProxy ListOf<T>::ListOfProxy::operator-(const ListOf<T>::ListOfProxy& rhs) {
    THIS = as<T>(THIS) - as<T>(RHS);
    return *this;
  }

  template <typename T>
  template <typename U>
  typename ListOf<T>::ListOfProxy ListOf<T>::ListOfProxy::operator-(const U& rhs) {
    THIS = as<T>(THIS) - rhs;
    return *this;
  }

  template <typename T>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator-=(const ListOf<T>::ListOfProxy& rhs) {
    THIS = as<T>(THIS) - as<T>(RHS);
    return *this;
  }

  template <typename T>
  template <typename U>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator-=(const U& rhs) {
    THIS = as<T>(THIS) - rhs;
    return *this;
  }

  // operator*
  template <typename T>
  typename ListOf<T>::ListOfProxy ListOf<T>::ListOfProxy::operator*(const ListOf<T>::ListOfProxy& rhs) {
    THIS = as<T>(THIS) * as<T>(RHS);
    return *this;
  }

  template <typename T>
  template <typename U>
  typename ListOf<T>::ListOfProxy ListOf<T>::ListOfProxy::operator*(const U& rhs) {
    THIS = as<T>(THIS) * rhs;
    return *this;
  }

  template <typename T>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator*=(const ListOf<T>::ListOfProxy& rhs) {
    THIS = as<T>(THIS) * as<T>(RHS);
    return *this;
  }

  template <typename T>
  template <typename U>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator*=(const U& rhs) {
    THIS = as<T>(THIS) * rhs;
    return *this;
  }

  // operator/
  template <typename T>
  typename ListOf<T>::ListOfProxy ListOf<T>::ListOfProxy::operator/(const ListOf<T>::ListOfProxy& rhs) {
    THIS = as<T>(THIS) / as<T>(RHS);
    return *this;
  }

  template <typename T>
  template <typename U>
  typename ListOf<T>::ListOfProxy ListOf<T>::ListOfProxy::operator/(const U& rhs) {
    THIS = as<T>(THIS) / rhs;
    return *this;
  }

  template <typename T>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator/=(const ListOf<T>::ListOfProxy& rhs) {
    THIS = as<T>(THIS) / as<T>(RHS);
    return *this;
  }

  template <typename T>
  template <typename U>
  typename ListOf<T>::ListOfProxy& ListOf<T>::ListOfProxy::operator/=(const U& rhs) {
    THIS = as<T>(THIS) / rhs;
    return *this;
  }

  /*
  template <typename T>
  void ListOf<T>::validate() {
    for (int i=0; i < this->size(); ++i) {
      if (!is<T>( static_cast<List&>(*this)[i] )) {
        stop("Invalid ListOf<%s> object: expected %s but got %s at index %i",
          DEMANGLE(T),
          Rf_type2char( TYPEOF( T() ) ),
          Rf_type2char( TYPEOF( static_cast<List&>(*this)[i] ) ),
          i
        );
      }
    }
  }
  */

}

#undef THIS
#undef LHS
#undef RHS

#endif

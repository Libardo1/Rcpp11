#ifndef Rcpp_api_meat_ListOf_h_
#define Rcpp_api_meat_ListOf_h_

// a define used to clean up some of the code repetition
#define THIS static_cast<List>(this->list)[this->index]
#define LHS  static_cast<List>(lhs.list)[lhs.index]
#define RHS  static_cast<List>(rhs.list)[rhs.index]

namespace Rcpp {

  // operator=
  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator=(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = RHS;
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator=(T vector) {
    THIS = vector;
    return *this;
  }

  // operator+
  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy> ListOfProxy<T, StoragePolicy>::operator+(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = as<T>(THIS) + as<T>(RHS);
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  template <typename U>
  ListOfProxy<T, StoragePolicy> ListOfProxy<T, StoragePolicy>::operator+(const U& rhs) {
    THIS = as<T>(THIS) + rhs;
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator+=(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = as<T>(THIS) + as<T>(RHS);
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  template <typename U>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator+=(const U& rhs) {
    THIS = as<T>(THIS) + rhs;
    return *this;
  }

  // operator-
  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy> ListOfProxy<T, StoragePolicy>::operator-(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = as<T>(THIS) - as<T>(RHS);
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  template <typename U>
  ListOfProxy<T, StoragePolicy> ListOfProxy<T, StoragePolicy>::operator-(const U& rhs) {
    THIS = as<T>(THIS) - rhs;
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator-=(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = as<T>(THIS) - as<T>(RHS);
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  template <typename U>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator-=(const U& rhs) {
    THIS = as<T>(THIS) - rhs;
    return *this;
  }

  // operator*
  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy> ListOfProxy<T, StoragePolicy>::operator*(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = as<T>(THIS) * as<T>(RHS);
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  template <typename U>
  ListOfProxy<T, StoragePolicy> ListOfProxy<T, StoragePolicy>::operator*(const U& rhs) {
    THIS = as<T>(THIS) * rhs;
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator*=(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = as<T>(THIS) * as<T>(RHS);
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  template <typename U>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator*=(const U& rhs) {
    THIS = as<T>(THIS) * rhs;
    return *this;
  }

  // operator/
  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy> ListOfProxy<T, StoragePolicy>::operator/(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = as<T>(THIS) / as<T>(RHS);
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  template <typename U>
  ListOfProxy<T, StoragePolicy> ListOfProxy<T, StoragePolicy>::operator/(const U& rhs) {
    THIS = as<T>(THIS) / rhs;
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator/=(const ListOfProxy<T, StoragePolicy>& rhs) {
    THIS = as<T>(THIS) / as<T>(RHS);
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  template <typename U>
  ListOfProxy<T, StoragePolicy>& ListOfProxy<T, StoragePolicy>::operator/=(const U& rhs) {
    THIS = as<T>(THIS) / rhs;
    return *this;
  }

  template <typename T, template <class> class StoragePolicy>
  void ListOf<T, StoragePolicy>::validate() {
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

}

#undef THIS
#undef LHS
#undef RHS

#endif

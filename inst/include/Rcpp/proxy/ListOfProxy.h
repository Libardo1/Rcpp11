#ifndef Rcpp_proxy_ListOfProxy_h_
#define Rcpp_proxy_ListOfProxy_h_

#define THIS static_cast<List>(this->list)[this->index]
#define LHS  static_cast<List>(lhs.list)[lhs.index]
#define RHS  static_cast<List>(rhs.list)[rhs.index]

namespace Rcpp {

template <typename T, template <class> class StoragePolicy>
class ListOf;

template <typename T, template <class> class StoragePolicy = PreserveStorage>
class ListOfProxy: public GenericProxy< ListOfProxy<T> > {
public:

  typedef ListOf<T, StoragePolicy> ListOf;

  ListOfProxy(ListOf& list_, int index_): list(list_), index(index_) {
    RCPP_DEBUG("ListOfProxy(ListOf& list_, int index_): list(list_), index(index_)\n");
  }

  ~ListOfProxy() {
    RCPP_DEBUG("~ListOfProxy()\n");
  }

  // assignment operators
  ListOfProxy& operator=(const ListOfProxy& rhs);
  ListOfProxy& operator=(T vector);

  // addition operators
  ListOfProxy operator+(const ListOfProxy& rhs);

  template <typename U>
  ListOfProxy operator+(const U& rhs);

  ListOfProxy& operator+=(const ListOfProxy& rhs);

  template <typename U>
  ListOfProxy& operator+=(const U& rhs);

  // subtraction operators
  ListOfProxy operator-(const ListOfProxy& rhs);

  template <typename U>
  ListOfProxy operator-(const U& rhs);

  ListOfProxy& operator-=(const ListOfProxy& rhs);

  template <typename U>
  ListOfProxy& operator-=(const U& rhs);

  // multiplication operators
  ListOfProxy operator*(const ListOfProxy& rhs);

  template <typename U>
  ListOfProxy operator*(const U& rhs);

  ListOfProxy& operator*=(const ListOfProxy& rhs);

  template <typename U>
  ListOfProxy& operator*=(const U& rhs);

  // division operators
  ListOfProxy operator/(const ListOfProxy& rhs);

  template <typename U>
  ListOfProxy operator/(const U& rhs);

  ListOfProxy& operator/=(const ListOfProxy& rhs);

  template <typename U>
  ListOfProxy& operator/=(const U& rhs);

  // read
  inline operator T() const {
    RCPP_DEBUG("operator T() const\n");
    return as<T>(THIS);
  }

  // TODO: reference operator

private:
  ListOf& list;
  int index;
}; // ListOfProxy

}

#undef THIS
#undef LHS
#undef RHS

#endif

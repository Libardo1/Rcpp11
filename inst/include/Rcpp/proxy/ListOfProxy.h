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

  ListOfProxy(ListOf<T, StoragePolicy>& list_, int index_): list(list_), index(index_) {
    RCPP_DEBUG("ListOfProxy(ListOf& list_, int index_): list(list_), index(index_)\n");
  }

  ~ListOfProxy() {
    RCPP_DEBUG("~ListOfProxy()\n");
  }

  // assignment operators
  inline ListOfProxy& operator=(const ListOfProxy& rhs);
  inline ListOfProxy& operator=(T vector);

  // addition operators
  inline ListOfProxy operator+(const ListOfProxy& rhs);

  template <typename U>
  inline ListOfProxy operator+(const U& rhs);
  
  template <typename U>
  friend inline ListOfProxy operator+(const U& lhs, const ListOfProxy& rhs) {
    return const_cast<ListOfProxy<T, StoragePolicy>&>(rhs).operator+(lhs);
  }

  inline ListOfProxy& operator+=(const ListOfProxy& rhs);

  template <typename U>
  inline ListOfProxy& operator+=(const U& rhs);

  // subtraction operators
  inline ListOfProxy operator-(const ListOfProxy& rhs);

  template <typename U>
  inline ListOfProxy operator-(const U& rhs);
  
  template <typename U>
  friend inline ListOfProxy operator-(const U& lhs, const ListOfProxy& rhs) {
    return const_cast<ListOfProxy<T, StoragePolicy>&>(rhs).operator-(lhs);
  }

  inline ListOfProxy& operator-=(const ListOfProxy& rhs);

  template <typename U>
  inline ListOfProxy& operator-=(const U& rhs);

  // multiplication operators
  inline ListOfProxy operator*(const ListOfProxy& rhs);

  template <typename U>
  inline ListOfProxy operator*(const U& rhs);
  
  template <typename U>
  friend inline ListOfProxy operator*(const U& lhs, const ListOfProxy& rhs) {
    return const_cast<ListOfProxy<T, StoragePolicy>&>(rhs).operator*(lhs);
  }

  inline ListOfProxy& operator*=(const ListOfProxy& rhs);

  template <typename U>
  inline ListOfProxy& operator*=(const U& rhs);

  // division operators
  inline ListOfProxy operator/(const ListOfProxy& rhs);

  template <typename U>
  inline ListOfProxy operator/(const U& rhs);
  
  template <typename U>
  friend inline ListOfProxy operator/(const U& lhs, const ListOfProxy& rhs) {
    return const_cast<ListOfProxy<T, StoragePolicy>&>(rhs).operator/(lhs);
  }

  inline ListOfProxy& operator/=(const ListOfProxy& rhs);

  template <typename U>
  inline ListOfProxy& operator/=(const U& rhs);

  // read
  inline operator T() const {
    RCPP_DEBUG("operator T() const\n");
    return as<T>(THIS);
  }
  
  inline operator SEXP() const {
    return THIS;
  }

  // TODO: reference operator

private:
  ListOf<T, StoragePolicy>& list;
  int index;
}; // ListOfProxy

}

#undef THIS
#undef LHS
#undef RHS

#endif

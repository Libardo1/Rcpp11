#ifndef Rcpp_vector_ListOf_h_
#define Rcpp_vector_ListOf_h_

// a define used to clean up some of the code repetition
#define THIS static_cast<List>(list)[index]
#define LHS  static_cast<List>(lhs.list)[lhs.index]
#define RHS  static_cast<List>(rhs.list)[rhs.index]

namespace Rcpp {

  template <typename T, template <class> class StoragePolicy = PreserveStorage>
  class ListOf: public List {

  public:

    class ListOfProxy {
    public:

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

    friend class ListOfProxy;

    ListOf() {}

    ListOf(SEXP data_): List(data_) {}

    template <typename U>
    ListOf(const U& data_): List(data_) {}

    template <typename U>
    ListOf( std::initializer_list<U> l ): List( wrap(l) ) {}

    operator SEXP() const {
      return wrap(static_cast<const List&>(*this));
    }

    ListOfProxy operator[](int i) {
      return ListOfProxy(*this, i);
    }

    const ListOfProxy operator[](int i) const {
      return ListOfProxy(const_cast< ListOf<T>& >(*this), i);
    }

    ListOfProxy operator[](std::string str) {
      std::vector<std::string> names = as< std::vector<std::string> >(this->attr("names"));
      for (int i=0; i < this->size(); ++i) {
        if (names[i] == str) {
          return ListOfProxy(*this, i);
        }
      }
      stop("No name '%s' in the names of the list supplied", str);
      return ListOfProxy(*this, -1); // silence compiler
    }

    const ListOfProxy operator[](std::string str) const {
      std::vector<std::string> names = as< std::vector<std::string> >(this->attr("names"));
      for (int i=0; i < this->size(); ++i) {
        if (names[i] == str) {
          return ListOfProxy(const_cast< ListOf<T>& >(*this), i);
        }
      }
      stop("No name '%s' in the names of the list supplied", str);
      return ListOfProxy(*this, -1); // silence compiler
    }

    // void validate();

  }; // ListOf<T>

} // Rcpp

#undef THIS
#undef LHS
#undef RHS

#endif

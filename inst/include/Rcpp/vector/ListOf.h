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

    ListOf() {}

    ListOf(SEXP data_): List(data_) {}

    template <typename U>
    ListOf(const U& data_): List(data_) {}

    template <typename U>
    ListOf( std::initializer_list<U> l ): List( wrap(l) ) {}

    operator SEXP() const {
      return wrap(static_cast<const List&>(*this));
    }

    ListOfProxy<T, StoragePolicy> operator[](int i) {
      return ListOfProxy<T, StoragePolicy>(*this, i);
    }

    const ListOfProxy<T, StoragePolicy> operator[](int i) const {
      return ListOfProxy<T, StoragePolicy>(const_cast< ListOf<T>& >(*this), i);
    }

    ListOfProxy<T, StoragePolicy> operator[](std::string str) {
      std::vector<std::string> names = as< std::vector<std::string> >(this->attr("names"));
      for (int i=0; i < this->size(); ++i) {
        if (names[i] == str) {
          return ListOfProxy<T, StoragePolicy>(*this, i);
        }
      }
      stop("No name '%s' in the names of the list supplied", str);
      return ListOfProxy<T, StoragePolicy>(*this, -1); // silence compiler
    }

    const ListOfProxy<T, StoragePolicy> operator[](std::string str) const {
      std::vector<std::string> names = as< std::vector<std::string> >(this->attr("names"));
      for (int i=0; i < this->size(); ++i) {
        if (names[i] == str) {
          return ListOfProxy<T, StoragePolicy>(const_cast< ListOf<T>& >(*this), i);
        }
      }
      stop("No name '%s' in the names of the list supplied", str);
      return ListOfProxy<T, StoragePolicy>(*this, -1); // silence compiler
    }

    void validate();

  }; // ListOf<T>

} // Rcpp

#undef THIS
#undef LHS
#undef RHS

#endif

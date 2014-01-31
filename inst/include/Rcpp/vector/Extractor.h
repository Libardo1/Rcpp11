#ifndef Rcpp_vector_Extractor_h_
#define Rcpp_vector_Extractor_h_

namespace Rcpp {

template <int RTYPE, template <class> class StoragePolicy, typename T>
class Extractor {
  
  using VECTOR = Vector<RTYPE, StoragePolicy>;
  
  public:
  
  Extractor() = delete;
  Extractor(const Extractor& rhs): vec(rhs.vec), other(rhs.other) {};
  explicit Extractor(const VECTOR& vec_, const T& other_): vec(vec_), other(other_) {};
  
  inline operator SEXP() const {
    return wrap( subset_impl(vec, other) );
  }
  
  inline operator VECTOR() const {
    return subset_impl(vec, other);
  }
  
  private:
  
  // helper function used for the subset methods when going from logical to int
  template <template <class> class OtherStoragePolicy>
  static inline Vector<INTSXP, StoragePolicy> which_na( const Vector<LGLSXP, OtherStoragePolicy>& x) {
    std::vector<int> output;
    int n = x.size();
    output.reserve(n);
    for (int i=0; i < n; ++i) {
      if (x[i] == NA_LOGICAL) {
        output.push_back(NA_INTEGER);
      } else if (x[i]) {
        output.push_back(i);
      }
    }
    return wrap(output);
  }

  template <template <class> class OtherStoragePolicy>
  inline Vector<RTYPE, StoragePolicy> 
  subset_impl( const VECTOR this_, const Vector<INTSXP, OtherStoragePolicy>& x ) const {
    int n = x.size();
    if (n == 0) return this_;
    Vector<RTYPE, StoragePolicy> output = no_init(n);
    for (int i=0; i < n; ++i) {
      if (x[i] == NA_INTEGER) output[i] = traits::get_na<RTYPE>();
      else if (x[i] < 1) stop("Cannot subset with an integer vector with elements <= 0");
      else if (x[i] > this_.size()) output[i] = traits::get_na<RTYPE>();
      else output[i] = (this_)[ x[i] - 1 ];
    }
    if (!Rf_isNull( Rf_getAttrib( this_, R_NamesSymbol) )) {
      Vector<STRSXP, StoragePolicy> thisnames = as<Vector<STRSXP, StoragePolicy>>(Rf_getAttrib(this_, R_NamesSymbol));
      Vector<STRSXP, StoragePolicy> outnames = no_init(n);
      for (int i=0; i < n; ++i) {
        if (x[i] == NA_INTEGER) outnames[i] = NA_STRING;
        else if (x[i] > this_.size()) outnames[i] = NA_STRING;
        else if (x[i] > 0) outnames[i] = thisnames[ x[i] - 1 ];
      }
      output.attr("names") = outnames;
    }
    return wrap(output);
  }
  
  template <template <class> class OtherStoragePolicy>
  inline Vector<RTYPE, StoragePolicy> subset_impl( const VECTOR& this_, const Vector<LGLSXP, OtherStoragePolicy>& x ) const {
    Vector<INTSXP, StoragePolicy> tmp = which_na(x);
    if (!tmp.size()) return Vector<RTYPE, StoragePolicy>(0);
    else return subset_impl(this_, tmp);
  }
  
  template <template <class> class OtherStoragePolicy>
  inline Vector<RTYPE, StoragePolicy> subset_impl( const VECTOR& this_, const Vector<STRSXP, OtherStoragePolicy>& x ) const {
    Vector<STRSXP, StoragePolicy> names = as< Vector<STRSXP, StoragePolicy> >(Rf_getAttrib(this_, R_NamesSymbol));
    Vector<INTSXP, StoragePolicy> idx = match(x, names);
    Vector<RTYPE, StoragePolicy> output = subset_impl(this_, idx);
    int n = output.size();
    if (n == 0) return Vector<RTYPE, StoragePolicy>(0);
    Vector<STRSXP, StoragePolicy> out_names = no_init(n);
    for (int i=0; i < n; ++i) {
      if (idx[i] == NA_INTEGER) out_names[i] = NA_STRING;
      else out_names[i] = names[ idx[i] - 1 ];
    }
    output.attr("names") = out_names;
    return output;
  }
  
  const VECTOR& vec;
  const T& other;
  
};

} // namespace Rcpp

#endif

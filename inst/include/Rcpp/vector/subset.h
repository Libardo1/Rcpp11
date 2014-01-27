#ifndef Rcpp_vector_subset_h_
#define Rcpp_vector_subset_h_

// helper function used for the subset methods when going from logical to int
static inline Vector<INTSXP, StoragePolicy> which_na( const Vector<LGLSXP, StoragePolicy>& x) {
  std::vector<int> output;
  int n = x.size();
  output.reserve(n);
  for (int i=0; i < n; ++i) {
    if (x[i] == NA_LOGICAL) {
      output.push_back(NA_INTEGER);
    } else if (x[i]) {
      output.push_back(i+1);
    }
  }
  return wrap(output);
}

inline Vector<RTYPE, StoragePolicy> operator[]( Vector<INTSXP, StoragePolicy> x ) const {
  int n = x.size();
  if (n == 0) return *this;
  Vector<RTYPE, StoragePolicy> output = no_init(n);
  for (int i=0; i < n; ++i) {
    if (x[i] == NA_INTEGER) output[i] = traits::get_na<RTYPE>();
    else if (x[i] < 1) stop("Cannot subset with an integer vector with elements <= 0");
    else if (x[i] > size()) output[i] = traits::get_na<RTYPE>();
    else output[i] = (*this)[ x[i] - 1 ];
  }
  if (!Rf_isNull( Rf_getAttrib( *this, R_NamesSymbol) )) {
    Vector<STRSXP, StoragePolicy> thisnames = as<Vector<STRSXP, StoragePolicy>>(Rf_getAttrib(*this, R_NamesSymbol));
    Vector<STRSXP, StoragePolicy> outnames = no_init(n);
    for (int i=0; i < n; ++i) {
      if (x[i] == NA_INTEGER) outnames[i] = NA_STRING;
      else if (x[i] > size()) outnames[i] = NA_STRING;
      else if (x[i] > 0) outnames[i] = thisnames[ x[i] - 1 ];
    }
    output.attr("names") = outnames;
  }
  return wrap(output);
}

inline Vector<RTYPE, StoragePolicy> operator[]( Vector<LGLSXP, StoragePolicy> x ) const {
  Vector<INTSXP, StoragePolicy> tmp = which_na(x);
  if (!tmp.size()) return Vector<RTYPE, StoragePolicy>(0);
  else return operator[](tmp);
}

inline Vector<RTYPE, StoragePolicy> operator[]( Vector<STRSXP, StoragePolicy> x ) const {
  Vector<STRSXP, StoragePolicy> names = as< Vector<STRSXP, StoragePolicy> >(Rf_getAttrib(*this, R_NamesSymbol));
  Vector<INTSXP, StoragePolicy> idx = match(x, names);
  Vector<RTYPE, StoragePolicy> output = operator[](idx);
  int n = output.size();
  if (n == 0) return Vector<RTYPE, StoragePolicy>(0);
  Vector<STRSXP, StoragePolicy> out_names = no_init(n);
  for (int i=0; i < n; ++i) {
    if (idx[i] == NA_INTEGER) out_names[i] = NA_STRING;
    else out_names[i] = names[ idx[i]-1 ];
  }
  output.attr("names") = out_names;
  return output;
}

#endif

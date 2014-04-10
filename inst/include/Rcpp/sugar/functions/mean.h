#ifndef Rcpp__sugar__mean_h
#define Rcpp__sugar__mean_h

// Double pass following along from R: in summary.c, the computation for mean
// is done (for numeric vectors and complex vectors) as:

/*
PROTECT(ans = allocVector(REALSXP, 1));
      for (i = 0; i < n; i++) s += REAL(x)[i];
	    s /= n;
	    if(R_FINITE((double)s)) {
		for (i = 0; i < n; i++) t += (REAL(x)[i] - s);
		s += t/n;
	    }
	    REAL(ans)[0] = (double) s;
	    break;
*/

// The double pass is not done for integer vectors or logical vectors.

namespace Rcpp{
namespace sugar{

// traits for mean return type
// TODO: infer in some way with decltype etc?
template <int RTYPE>
struct mean_return_type {
  using type = double;
};

template <>
struct mean_return_type<CPLXSXP> {
  using type = Rcomplex;
};

template <int RTYPE, bool NA, typename T>
class Mean :
  public Lazy< double, Mean<RTYPE,NA,T> > {

public:
    typedef typename Rcpp::VectorBase<RTYPE,NA,T> VEC_TYPE ;
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;

    Mean( const VEC_TYPE& object_ ) : object(object_.get_ref()){}

    inline typename mean_return_type<RTYPE>::type get() const {
      return get__impl( traits::identity<traits::number_to_type<RTYPE>>() );
    }

private:
    const T& object ;

    template <unsigned int TT> // default: for INTSXP, LGLSXP
    double get__impl( traits::identity<traits::number_to_type<TT>> ) const {
      double s = 0;
      int n = object.size();
      for (int i=0; i < n; ++i) {
        s += object[i];
      }
      return s / n;
    }

    // REALSXP
    STORAGE get__impl( traits::identity<traits::number_to_type<REALSXP>> ) const {
      long double s = 0; // long double offers extra precision where possible
      int n = object.size();

      // first pass
      for (int i=0; i < n; ++i) {
        s += object[i];
      }
      s /= n;

      // second pass
      if (R_FINITE( (double) s)) {
        long double t = 0;
        for (int i=0; i < n; ++i) {
          t += object[i] - s;
        }
        s += t / n;
      }
      return (double) s;
    }

} ;

} // sugar

template <int RTYPE, bool NA, typename T>
inline sugar::Mean<RTYPE,NA,T> mean( const VectorBase<RTYPE,NA,T>& t){
    return sugar::Mean<RTYPE,NA,T>( t ) ;
}


} // Rcpp
#endif


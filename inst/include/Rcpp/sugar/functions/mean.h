#ifndef Rcpp__sugar__mean_h
#define Rcpp__sugar__mean_h

// Double pass following along from R: in summary.c, the computation for mean
// is done as:

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

namespace Rcpp{
namespace sugar{

template <int RTYPE, bool NA, typename T>
class Mean : public Lazy< typename Rcpp::traits::storage_type<RTYPE>::type , Mean<RTYPE,NA,T> > {
public:
    typedef typename Rcpp::VectorBase<RTYPE,NA,T> VEC_TYPE ;
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;

    Mean( const VEC_TYPE& object_ ) : object(object_){}

    STORAGE get() const {

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

private:
    const VEC_TYPE& object ;
} ;

} // sugar

template <bool NA, typename T>
inline sugar::Mean<REALSXP,NA,T> mean( const VectorBase<REALSXP,NA,T>& t){
    return sugar::Mean<REALSXP,NA,T>( t ) ;
}


} // Rcpp
#endif


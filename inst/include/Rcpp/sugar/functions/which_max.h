#ifndef Rcpp__sugar__which_max_h
#define Rcpp__sugar__which_max_h

namespace Rcpp{
namespace sugar{

template <int RTYPE, bool NA, typename T>
class WhichMax {
public:
    typedef typename Rcpp::SugarVectorExpression<RTYPE,NA,T> VEC_TYPE ;
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
    WhichMax(const VEC_TYPE& obj_ ) : obj(obj_){}

    int get() const {
        STORAGE current = obj[0] ;
        STORAGE min = current ;
        int index = 0 ;
        if( Rcpp::traits::is_na<RTYPE>(current) ) return NA_INTEGER ;
        int n = obj.size() ;
        for( int i=1; i<n; i++){
            current = obj[i] ;
            if( Rcpp::traits::is_na<RTYPE>(current) ) return NA_INTEGER ;
            if( current > min ){
                min = current ;
                index = i ;
            }
        }
        return index ;
    }

private:
    const VEC_TYPE& obj ;

} ;
   
template <int RTYPE, typename T>
class WhichMax<RTYPE,false,T> {
public:
    typedef typename Rcpp::SugarVectorExpression<RTYPE,false,T> VEC_TYPE ;
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
    WhichMax(const VEC_TYPE& obj_ ) : obj(obj_){}

    int get() const {
        STORAGE current = obj[0] ;
        STORAGE min = current ;
        int index = 0 ;
        int n = obj.size() ;
        for( int i=1; i<n; i++){
            current = obj[i] ;
            if( current > min ){
                min = current ;
                index = i ;
            }
        }
        return index ;
    }

private:
    const VEC_TYPE& obj ;

} ;

    
} // sugar



template <int RTYPE, bool NA, typename T>
int which_max( const SugarVectorExpression<RTYPE,NA,T>& t ){
    return sugar::WhichMax<RTYPE,NA,T>(t).get() ; 
}
  
} // Rcpp
#endif


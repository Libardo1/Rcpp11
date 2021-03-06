#ifndef Rcpp__sugar__pmin_h
#define Rcpp__sugar__pmin_h

namespace Rcpp{
namespace sugar{

template <int RTYPE, bool LHS_NA, bool RHS_NA> struct pmin_op ; 

// specializations for double. 
// we use the fact that NA < x is false
template <>
struct pmin_op<REALSXP,true,true>{
    inline double operator()( double left, double right ) const {
        return ( Rcpp::traits::is_na<REALSXP>( left ) || (left < right) ) ? left : right ;
    }
} ;
template <> struct pmin_op<REALSXP,true,false> {
    inline double operator()( double left, double right ) const {
        return right < left ? right : left ;
    }
} ;
template <> struct pmin_op<REALSXP,false,true> {
    inline double operator()( double left, double right ) const {
        return right < left ? right : left ;
    }
} ;
template <> struct pmin_op<REALSXP,false,false> {
    inline double operator()( double left, double right ) const {
        return left < right ? left : right ;
    }
} ;

// specializations for INTSXP. Since NA is represented as the smallest 
// int, NA is always the smallest, so it is safe to return NA
template <bool LHS_NA, bool RHS_NA>
struct pmin_op<INTSXP,LHS_NA,RHS_NA> {
    inline int operator()(int left, int right) const {
        return left < right ? left : right ;
    }
} ;


// general case
template <int RTYPE, bool NA> class pmin_op_Vector_Primitive {
public:
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;

    pmin_op_Vector_Primitive( STORAGE right_ ) :  right(right_) {}

    inline STORAGE operator()( STORAGE left ) const {
        return left < right ? left : right ;
    }
    
private:
    STORAGE right ;
} ;
// only special case we need to take care of
template <> class pmin_op_Vector_Primitive<REALSXP,true> {
public:
    pmin_op_Vector_Primitive( double right_ ) :  right(right_) {}

    inline double operator()( double left ) const {
        return ( Rcpp::traits::is_na<REALSXP>( left ) || (left < right) ) ? left : right ;
    }
    
private:
    double right ;
} ;




template <
    int RTYPE, 
    bool LHS_NA, typename LHS_T, 
    bool RHS_NA, typename RHS_T
    >
class Pmin_Vector_Vector : public SugarVectorExpression< 
    RTYPE , 
    ( LHS_NA || RHS_NA ) ,
    Pmin_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T>
> {
public:
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
    typedef pmin_op<RTYPE,LHS_NA,RHS_NA> OPERATOR ;

    Pmin_Vector_Vector( const LHS_T& lhs_, const RHS_T& rhs_ ) : lhs(lhs_), rhs(rhs_), op() {}

    inline STORAGE operator[]( int i ) const {
        return op( lhs[i], rhs[i] ) ;
    }
    inline int size() const { return lhs.size() ; }

private:
    const LHS_T& lhs ;
    const RHS_T& rhs ;
    OPERATOR op ;
} ;



template <
    int RTYPE, 
    bool LHS_NA, typename LHS_T
    >
class Pmin_Vector_Primitive : public SugarVectorExpression< 
    RTYPE , 
    true ,
    Pmin_Vector_Primitive<RTYPE,LHS_NA,LHS_T>
> {
public:
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;
    typedef pmin_op_Vector_Primitive<RTYPE,LHS_NA> OPERATOR ;

    Pmin_Vector_Primitive( const LHS_T& lhs_, STORAGE rhs_ ) : lhs(lhs_), op(rhs_) {}

    inline STORAGE operator[]( int i ) const { return op( lhs[i] ) ; }
    inline int size() const { return lhs.size() ; }

private:
    const LHS_T& lhs ;
    OPERATOR op ;
} ;



} // sugar

template <
    int RTYPE, 
    bool LHS_NA, typename LHS_T,
    bool RHS_NA, typename RHS_T
>
inline sugar::Pmin_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T> 
pmin( 
    const Rcpp::SugarVectorExpression<RTYPE,LHS_NA,LHS_T>& lhs, 
    const Rcpp::SugarVectorExpression<RTYPE,RHS_NA,RHS_T>& rhs 
    ){
    return sugar::Pmin_Vector_Vector<RTYPE,LHS_NA,LHS_T,RHS_NA,RHS_T>( lhs.get_ref(), rhs.get_ref() ) ;
}

template <
    int RTYPE, 
    bool LHS_NA, typename LHS_T
>
inline sugar::Pmin_Vector_Primitive<RTYPE,LHS_NA,LHS_T> 
pmin( 
    const Rcpp::SugarVectorExpression<RTYPE,LHS_NA,LHS_T>& lhs, 
    typename Rcpp::traits::storage_type<RTYPE>::type rhs 
    ){
    return sugar::Pmin_Vector_Primitive<RTYPE,LHS_NA,LHS_T>( lhs.get_ref(), rhs ) ;
}


template <
    int RTYPE, 
    bool RHS_NA, typename RHS_T
>
inline sugar::Pmin_Vector_Primitive<RTYPE,RHS_NA,RHS_T> 
pmin( 
    typename Rcpp::traits::storage_type<RTYPE>::type lhs,  
    const Rcpp::SugarVectorExpression<RTYPE,RHS_NA,RHS_T>& rhs 
    ){
    return sugar::Pmin_Vector_Primitive<RTYPE,RHS_NA,RHS_T>( rhs.get_ref(), lhs ) ;
}


} // Rcpp

#endif

//
// Module_Add_Property.h:  Rcpp modules
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
// Copyright (C) 2013 Romain Francois
//
// This file is part of Rcpp11.
//
// Rcpp11 is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp11 is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp11.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp_Module_Add_Property_h
#define Rcpp_Module_Add_Property_h

    template <typename PROP>
    self& property( const char* name_, PROP (Class::*GetMethod)(void), const char* docstring = 0){
        return AddProperty( name_, new CppProperty_ReadOnly<Class,PROP,decltype(GetMethod)>(GetMethod, docstring) ) ;
    }

    template <typename PROP>
    self& property( const char* name_, PROP (Class::*GetMethod)(void) const, const char* docstring = 0){
        return AddProperty( name_, new CppProperty_ReadOnly<Class,PROP,decltype(GetMethod)>(GetMethod, docstring) ) ;
    }
    
    template <typename PROP>
    self& property( const char* name_, PROP (*GetMethod)(Class*), const char* docstring ){
        return AddProperty( name_, new CppProperty_ReadOnly<Class,PROP,decltype(GetMethod)>(GetMethod, docstring) ) ;
    }
    
    
    template <typename PROP>
    self& property( const char* name_, PROP (Class::*GetMethod)(void), void (Class::*SetMethod)(PROP), const char* docstring = 0){
        return AddProperty( name_, new CppProperty_Read_Write<Class,PROP,decltype(GetMethod), decltype(SetMethod)>(GetMethod, SetMethod, docstring) );
    }
    template <typename PROP>
    self& property( const char* name_, PROP (Class::*GetMethod)(void) const, void (Class::*SetMethod)(PROP), const char* docstring = 0){
        return AddProperty( name_, new CppProperty_Read_Write<Class,PROP,decltype(GetMethod), decltype(SetMethod)>(GetMethod, SetMethod, docstring) );
    }
    
    template <typename PROP>
    self& property( const char* name_, PROP (Class::*GetMethod)(void), void (*SetMethod)(Class*,PROP), const char* docstring = 0 ){
        return AddProperty( name_, new CppProperty_Read_Write<Class,PROP,decltype(GetMethod), decltype(SetMethod)>(GetMethod, SetMethod, docstring) );
    }
    template <typename PROP>
    self& property( const char* name_, PROP (Class::*GetMethod)(void) const , void (*SetMethod)(Class*,PROP), const char* docstring = 0 ){
        return AddProperty( name_, new CppProperty_Read_Write<Class,PROP,decltype(GetMethod), decltype(SetMethod)>(GetMethod, SetMethod, docstring) );
    }
    
    
    template <typename PROP>
    self& property( const char* name_, PROP (*GetMethod)(Class*), void (Class::*SetMethod)(PROP), const char* docstring = 0 ){
    	   return AddProperty( name_, new CppProperty_Read_Write<Class,PROP,decltype(GetMethod), decltype(SetMethod)>(GetMethod, SetMethod, docstring) );
    }
    
    template <typename PROP>
    self& property( const char* name_, PROP (*GetMethod)(Class*), void (*SetMethod)(Class*,PROP), const char* docstring = 0 ){
    	   return AddProperty( name_, new CppProperty_Read_Write<Class,PROP,decltype(GetMethod), decltype(SetMethod)>(GetMethod, SetMethod, docstring) );
    }
	
	
#endif

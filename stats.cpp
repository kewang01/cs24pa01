// stats.cxx - implements statistician class as defined in stats.h
// YOUR NAME(S), DATE

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented

namespace main_savitch_2C
{

  statistician::statistician(){
    count=0;
    total=0;
  }
  

  void statistician::next(double r){
    count++;
    total=total+r;
    if(count==1){
      tiniest=r;
      largest=r;
    }
    else{
      if(r<tiniest){
	tiniest=r;
      }
      if(r>largest){
	largest=r;
      }
    }
  }

  void statistician::reset(){
    count=0;
    total=0;
  }

  double statistician::mean() const{
    assert(count);
    return (1.0*total)/count;
  }

  double statistician::minimum() const{
    assert(count);
    return tiniest;
  }

  double statistician::maximum() const{
    assert(count);
    return largest;
  }

  statistician operator +(const statistician& s1,const statistician& s2){
    statistician s3;
    if(s1.length()==0 && s2.length()==0){
      s3.count=0;
      s3.total=0;
    }
    else if(s1.length()==0 && s2.length()!=0){
      s3=s2;
    }
    else if(s1.length()!=0 && s2.length()==0){
      s3=s1;
    }
    else{
      s3.count=s1.length()+s2.length();
      s3.total=s1.sum()+s2.sum();
      if(s1.minimum()<s2.minimum()){
	s3.tiniest=s1.minimum();
      }
      else{
	s3.tiniest=s2.minimum();
      }
      if(s1.maximum()>s2.maximum()){
	s3.largest=s1.maximum();
      }
      else{
	s3.largest=s2.maximum();
      }
    }
    return s3;
  }

  statistician operator *(double scale,const statistician& s){
    statistician s3;
    if(s.length()==0){
      s3=s;
    }
    else{
      s3.count=s.length();
      s3.total=scale*s.sum();
      s3.tiniest=scale*s.minimum();
      s3.largest=scale*s.maximum();
    }
    return s3;
  }

  bool operator ==(const statistician& s1,const statistician& s2){
    if(s1.length()== s2.length() && s1.sum()==s2.sum() && s1.minimum()==s2.minimum() && s1.maximum()==s2.maximum()){
      return true;
    }
    else{
      return false;
    }
  }
  
}


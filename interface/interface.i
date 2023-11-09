%module TestSwig

%{

#include "../src/lib.h"

%}
%rename("lego_%s") "add";


%include std_shared_ptr.i
%include "std_vector.i"
%include "typemaps.i"


%newobject lego::make_row_ptr_int;
%delobject lego::free_row_ptr_int;

%contract lego::make_row_ptr_int(int a) {
require:
  a >= 0;
}

%apply int *OUTPUT { int* res };
%apply int *OUTPUT { int* output };
%apply int &OUTPUT { int& output };






%include "../src/lib.h"
namespace std {
  %template(Pos2DVec) vector<lego::Pos2<double>>;
}

%template(shared_ptr_int)std::shared_ptr<int>;

%template(Pos2F) lego::Pos2<float>;

%template(Pos2D) lego::Pos2<double>;

%template(greater_i) lego::greater<int>;












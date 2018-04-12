/* -*- c++ -*- */

#define SIMPLE_INT_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "simple_int_swig_doc.i"

%{
#include "simple_int/simple_int.h"
%}


%include "simple_int/simple_int.h"
GR_SWIG_BLOCK_MAGIC2(simple_int, simple_int);

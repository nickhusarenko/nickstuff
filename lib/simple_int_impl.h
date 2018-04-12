
#ifndef INCLUDED_SIMPLE_INT_SIMPLE_INT_IMPL_H
#define INCLUDED_SIMPLE_INT_SIMPLE_INT_IMPL_H

#include <simple_int/simple_int.h>

#include <math.h>

namespace gr
{
    namespace simple_int
    {
        class simple_int_impl : public simple_int
        {
        private:
            // Internal Properties
            unsigned int interpolation_factor;
        public:
            simple_int_impl(int);
            ~simple_int_impl();
            
            // Set Class Property Functions
            void set_interpolation_factor(int);
            
            // Work Function
            int general_work(int, gr_vector_int &, gr_vector_const_void_star &, gr_vector_void_star &);
        };
    }
}

#endif

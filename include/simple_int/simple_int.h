
#ifndef INCLUDED_SIMPLE_INT_SIMPLE_INT_H
#define INCLUDED_SIMPLE_INT_SIMPLE_INT_H

#include <simple_int/api.h>
#include <gnuradio/block.h>

namespace gr
{
    namespace simple_int
    {
        class SIMPLE_INT_API simple_int : virtual public gr::block
        {
        public:
            typedef boost::shared_ptr<simple_int> sptr;
            
            static sptr make(int);
            
            virtual void set_interpolation_factor(int) { return; }
        };
    }
}

#endif



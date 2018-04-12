
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "simple_int_impl.h"

namespace gr
{
    namespace simple_int
    {
        simple_int::sptr simple_int::make(int param_interpolation_factor)
        {
            return gnuradio::get_initial_sptr(new simple_int_impl(param_interpolation_factor));
        }
        
        simple_int_impl::simple_int_impl(int param_interpolation_factor) :
            gr::block("simple_int", gr::io_signature::make(1, 1, sizeof(gr_complex)), gr::io_signature::make(1, 1, sizeof(gr_complex))),
            interpolation_factor(param_interpolation_factor)
        {
            
        }
        
        simple_int_impl::~simple_int_impl()
        {
            
        }
        
        void simple_int_impl::set_interpolation_factor(int param_input_value)
        {
            if (param_input_value < 1)
            {
                printf("Block [simple_int] received an invalid interpolation factor setting!!!\n");
                return;
            }
            
            this->interpolation_factor = ((unsigned int) param_input_value);
        }
        
        int simple_int_impl::general_work (int noutput_items, gr_vector_int &ninput_items, gr_vector_const_void_star &input_items, gr_vector_void_star &output_items)
        {
            // Local Variables
            const gr_complex *data_in;
            gr_complex *data_out;
            int process_count;
            int i, j;
            
            // Set Data In/Out Pointer
            data_in = ((const gr_complex *) input_items[0]);
            data_out = ((gr_complex *) output_items[0]);
            
            // Calculate Items To Process
            process_count = (noutput_items / this->interpolation_factor) ;
            
            if (process_count > ninput_items[0])
            {
                process_count = ninput_items[0] ;
            }
            
            // Process Input Items
            for (i = 0; (i < process_count); i++)
            {
                for (j = 0; (j < this->interpolation_factor); j++)
                {
                    data_out[((i*this->interpolation_factor) + (j))] = data_in[i];
                }
            }
            
            // Consume Used Inputs
            consume_each(process_count);
            
            // Return Number Of Created Outputs
            return ((process_count * this->interpolation_factor));
        }
    }
}


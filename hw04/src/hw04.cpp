#include <hw04.h>
#include <cstddef>

std::size_t hw04(const int* input_array, std::size_t elem_count)
{
    if(elem_count == 0){
        return 0;
    }

    int* out_data = new int[1];
    std::size_t out_data_size = 1;
    std::size_t current_index = 0;

    for(std::size_t i = 0; i < elem_count; i++){
        if(input_array[i] < 0){
        break;
        }

        if(current_index >= out_data_size) {
            int* new_out_data = new int[out_data_size * 2];
            for(std::size_t j = 0 ; j < out_data_size; j++){
                new_out_data[j] = out_data[j];
            }
            delete[] out_data;
            out_data = new_out_data;
            out_data_size *= 2;
        }

        out_data[current_index] = input_array[i];
        current_index++;
    }

    std::size_t sum = 0;
    for(std::size_t i = 0; i < current_index; i++){
        sum += out_data[i];
    }

    delete[] out_data;
    return sum;
}

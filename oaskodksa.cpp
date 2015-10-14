#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

typedef std::vector<unsigned int> input_type;

void radix_sort(input_type & x)
{
    if ( x.empty() ) return; // at least one element

    typedef std::vector< std::vector< input_type::value_type > > buckets_type;
    buckets_type buckets;

    buckets.resize(10); // allocate buckets
    // for sorting decimal numbers

    int pow10 = 1; // pow10 holds powers of 10 (1, 10, 100, ...)

    // find maximum in the array to limit the main loop below
    input_type::value_type max = *std::max_element(x.begin(), x.end());

    //begin radix sort
    for(; max != 0 ; max/=10, pow10*=10)
    {
        // 1. determine which bucket each element should enter
        // for each element in 'x':
        for(input_type::const_iterator elem = x.begin(); elem != x.end(); ++elem)
        {
                // calculate the bucket number:
                size_t const bucket_num = ( *elem / pow10 ) % 10;
                // add the element to the list in the bucket:
                buckets[ bucket_num ].push_back( *elem );
        }

        // 2. transfer results of buckets back into main array
        input_type::iterator store_pos = x.begin();
        // for each bucket:
        for(buckets_type::iterator bucket = buckets.begin(); bucket != buckets.end(); ++bucket)
        {
                // for each element in the bucket:
                for(buckets_type::value_type::const_iterator bucket_elem = bucket->begin();
                        bucket_elem != bucket->end(); ++bucket_elem)
                {
                        // copy the element into next position in the main array
                        *store_pos++ = *bucket_elem;
                }
                bucket->clear(); // forget the current bucket's list
        }
    }
}

int main() {

    input_type input;

    // read numbers from standard input (ends with end-of-file: ^Z / ^D, or
    // with a new line that contains something that's not a number)
    std::cout << "Enter positive numbers to sort:" << std::endl;
    std::copy(std::istream_iterator<unsigned int>(std::cin),
        std::istream_iterator<unsigned int>(), std::back_inserter(input));

    if ( input.end() != std::find_if(input.begin(), input.end(),
        std::bind1st(std::equal_to<unsigned int>(), 0)) )
    {
        std::cerr << "Zero isn't positive" << std::endl;
        return 1;
    }

    std::cout << " ** Elements before sorting: " << std::endl;
    std::copy(input.begin(), input.end(),
        std::ostream_iterator<unsigned int>(std::cout, " "));

    radix_sort(input);

    std::cout << std::endl << " ** Elemets after sorting: " << std::endl;
    std::copy(input.begin(), input.end(),
        std::ostream_iterator<unsigned int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

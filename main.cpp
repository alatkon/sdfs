#include <iostream>

// This function merges two ordered arrays in ordered one
int fusion(long long int a_m[],
           long long int a_i[],
           long long int b_m[],
           long long int b_i[],
           long long int c_m[],
           long long int c_i[],
           long long int size);

// This function is recursive unit of merge sort 
int rec_sort (long long int input[],
              long long int i_ind[],
              long long int output[],
              long long int o_ind[],
              long long int i_s);

// This is interface function of merge sort
int my_sort (long long int array[],
             long long int sort_array[],
             long long int indices[],
             long long int s_r);

int main()
{
    long long int size;
    
    // Read the number of players
    std::cin >> size;
    long long int input[size];

    // Read the efficiencies of players
    for (int step = 0; step < size; ++step)
    {
        std::cin >> input[step];
    }
    
    long long int sort_array[size];
    long long int indices[size];
    
    // Sorting of players' efficiencies
    my_sort(input, sort_array, indices, size);
    
    // Firstly team includes the weakest player
    long long int p_L = 0;
    long long int p_R = 0;
    long long int m_L = 0;
    long long int m_R = 0;
    long long int sum = sort_array[0];
    long long int max = sum;
    
    while (p_L < size - 1)
    {
        while (p_R < size - 1)
        {   
            // Check constrain of the problem
            if (p_R > p_L)
            {
                if (sort_array[p_L] + sort_array[p_L + 1] < sort_array[p_R + 1])
                {
                    break;
                }
            }
            
            // Add next player by efficiency
            // and update the summary players' efficiency
            ++p_R;
            sum = sum + sort_array[p_R];
            // Update the best solution
            if (sum > max)
            {
                max = sum;
                m_L = p_L;
                m_R = p_R;
            }
        }
        
        // Exclude the weakest player from the team
        // and update the summary players' efficiency
        sum = sum - sort_array[p_L];
        ++p_L;
    }
    
    long long int out_num = m_R - m_L + 1;
    long long int out[out_num];
    
    // Forming indexes of team players
    for (int step = 0; step < out_num; ++step)
    {
        out[step] = indices[step + m_L] + 1;
    }
    
    long long int sort_out[out_num];
    long long int ind_out[out_num];
    
    // Inverse sorting of players
    my_sort(out, sort_out, ind_out, out_num);
    
    // Display of the summary players' efficiency
    std::cout << max << std::endl;
    
    // Display of the indices of team players
    for (int step = 0; step < out_num; ++step)
    {
        std::cout << sort_out[step] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

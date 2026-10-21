#include "push_swap.h"

void	select_strategy(t_data *data)
{
    if(data->strategy == ADAPTIVE)
    {
        if(data->a->size <= 100)
        {
            if(data->disorder < 20.0) // disorder between 0 and 1 **
                data->strategy = SIMPLE;
            else
                data->strategy = MEDIUM;
        }
        else
        {
            if(data->disorder < 15.0)
                data->strategy = MEDIUM;
            else
                data->strategy = COMPLEX;
        }
    }
    return ;
}
void	execute_strategy(t_data *data)
{
    select_strategy(data);
    if(data->strategy == SIMPLE)
        sort_simple(data);
    else if (data->strategy == MEDIUM)
        sort_medium(data);
    else if (data->strategy == COMPLEX)
        sort_complex(data);
    return;
}

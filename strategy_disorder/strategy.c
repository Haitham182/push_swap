#include "../push_swap.h"

void	select_strategy(t_data *data)
{
	if (data->strategy == ADAPTIVE)
	{
		if (data->disorder < 0.2)
			data->strategy = SIMPLE;
		else if (data->disorder < 0.5)
			data->strategy = MEDIUM;
		else
			data->strategy = COMPLEX;
	}
    return ;
}
void	execute_strategy(t_data *data)
{
    select_strategy(data);
    if(data->strategy == SIMPLE)
        sort_medium(data);
    else if (data->strategy == MEDIUM)
        sort_medium(data);
   /* else if (data->strategy == COMPLEX)
        sort_complex(data);*/
    return;
}

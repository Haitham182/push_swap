#include "push_swap.h"

int main(int argc, char **argv)
{
        t_data  *data;
        if (argc <= 1)
                return (1);

        if (!parse_args(argc, argv,data->a,data))
        {
                write(1, "Error\n", 6);
                exit(1);                             
        }
        
        data = calloc(1,sizeof(t_data));
        data->a = lstnew_stack();
        data->b = lstnew_stack();
        data->bench = malloc(sizeof(t_bench));




}
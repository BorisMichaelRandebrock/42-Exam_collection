The re-creation of the main is bringing you 2 additional challenges.. the rereation of the main as such (which i provided at the lower level)
but also you will have to recreate the compare function (similar thing will happen to you in the ft_sort_list))
In addition, depending on your computer it may, or may not accept the prototype of the function in order to work, so you may have to change the prototype to void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)( * void, * void)); but only for testing purposes....

Assignment name  : ft_list_remove_if  
Expected files   : ft_list_remove_if.c  
Allowed functions: free  
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h  
typedef struct      s_list  
{    
  &nbsp;&nbsp;&nbsp;&nbsp; </pre>     struct s_list   *next;  
  &nbsp;&nbsp;&nbsp;&nbsp;</pre>      void            *data;  
}   </pre> &nbsp;&nbsp;               t_list;   


As in this assignement you have to work with a header you do not know and you can not deliver it either, I have provided you with the list.h @ its lower level..     
Be aware.. in the examen you will have to access it at the same level (that is why the comment).
But check out the header in the lower level as you may have to re-create it in the exam (as well as the cmp function which you will find in its main).   

Assignment name  : sort_list  
Expected files   : sort_list.c  
Allowed functions:  
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)  
{  
&nbsp;&nbsp;&nbsp;&nbsp;	return (a <= b);  
}  

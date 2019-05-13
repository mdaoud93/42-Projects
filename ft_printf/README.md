# ft_printf
My own implementaion of the famous printf function.

To compile, simple call make inside the repository, this will create a static library called libftprintf.a that you can then link with your program.  
To compile your program and link it with the library:  
-- include the header "ft_printf.h" inside your source/header file.  
-- compile the program and specify the path of the library as well as the path to the header file.  
gcc <program_name> -L \<path to the library\> -lftprintf -I \<path to the header folder\>


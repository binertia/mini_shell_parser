#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

// :TODO: can silent out any SIGVALUE by use tc{..} function
// :TODO: need to do Makefile with absolute path on libreadline;

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0); // ignore this error; :HACK:
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
		return ;
}

void	init_sig_handle()
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}

/* :TODO: 
 *
 * handle    ''
 * handle    ""
 * handle    < , >
 *		bash-3.2$ > out.txt < papa.sh read input; echo $input
	#!binbash
		bash-3.2$ cat out.txt
		(no output);

		> out.txt echo love
		cat out.txt
		love

		< . ls
		(file in current dir)

		bash-3.2$ > out.txt < papa.sh read input
		bash-3.2$ echo $input
	#!binbash
 *	<  :	// content of file (not output) direct to input stream of cmd
 *    // ** ./read_input < text_file > output_file  
 *	  // ** ./read_input > output_file < text_file
 *		two of both is the same result !! god help me!
 *	  // ** echo love > test.txt ; < test.txt grep love  : should work
 *	  // ** echo love > test.txt ; < test.txt grep love > hello.txt : should work
 * handle    << , >>
 * Therefore, the main difference between > and >> is that > overwrites the content of a file (if it exists), while >> appends content to the end of a file without overwriting existing content.  > rewrite   >> appends but >> will use stdout to them
 * handle    |  
 * handle    $(environment var)
 * handle	 $? :: used as stores the exit status of the last executed command.
 *					ex (bash can't read file that chmod to 000, after run that cmd it will save 126 to $?)
 *
 * handle	|| if $? return error send another
 * handle	&& if $? return sucess send another
 * handle	*
 * whild card can do it :::  cat *.c   ==  ls | grep '\.c$' > cat
 * ::  cat $(ls | grep '\.c$')  == cat *.c " need ecapse for '.'  (\.) if not it will send grep meaing at '.' can be another char that follow by 'c' jjjkk"
 * ::  cat $(ls | grep '.c' ) == cat *.c*
 * ::  cat $(ls | grep '^.c') == cat .c*
 
 * ========= build in function ==========
◦ echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no options
*/

/*
 *	token type
 *	1 for <
 *	2 for >
 * */
void	manipulate_input(char *s)
{
	
}

int main(int ac, char *av[]) {
    char* input;
	
	init_sig_handle();
	if (ac > 1)
	{
		// case of want to run script file
		// send av[1] to bin/bash
		// ** bash will run only front script file
		return (2);
	}
	if (ac < 2)
    // Readline loop
    while (1) {
        input = readline(">");
        if (!input) {   // case ctrl+d
            printf("ctrl+d case ..\n");
			free(input);
            break;
        }
        if (input[0] != '\0') {
			manipulate_input(input);
            printf("You entered: %s\n", input); // :FIX: temporary display
            add_history(input);
        }
        free(input);
    }
	clear_history();

    return 0;
}

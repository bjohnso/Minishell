#include "ft_sh.h"

int     main(int argc, char **argv){
    //t_shell         *shell;
    t_token_list    *token_list;

    /*while (1){
        if (shell->quit == true)
        break ;
    }*/
    if (argc > 0){
    
        //TODO: Allow Parser to return error codes
        token_list = parser(argv[1]);

        ft_printf("Number of tokens returned : %d\n", token_list->size);


        /*for (int i = 0; i < token_list->size; i++){
            ft_printf("Lexeme : %s | Type : %s\n", token_list->tokens[i]->lexeme, token_list->tokens[i]->type);
        }*/
    }
}
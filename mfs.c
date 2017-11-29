/*
 * Alejandro Waumann
 * FAT32 File System
 * 
 * Utility to read FAT32 file systems
 * 
 * November 23, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// WHITESPACE will be used as the delimter for tokenization
#define WHITESPACE " \t\n"
#define MAX_COMMAND_SIZE 255
#define MAX_NUM_ARGUEMENTS 4

// Tokenization helper functions
int tokenize_cmd( char *cmd_str, char **tokens );
void free_tokens( char **tokens, int token_count );

FILE * fp = NULL;

int main()
{
    char * cmd_str = (char *) malloc( MAX_COMMAND_SIZE );

    while( 1 )
    {
        printf("mfs> ");
        memset(cmd_str, '\0', MAX_COMMAND_SIZE);
        // Wait for user input
        while(!fgets( cmd_str, MAX_COMMAND_SIZE, stdin ));

        // Tokenize user input
        char * tokens[MAX_NUM_ARGUEMENTS];
        int token_count = tokenize_cmd(cmd_str, tokens);

        // Store the command from command line arguments
        char * cmd = tokens[0];

        /*************************
         * Begin command execution
        **************************/

        // E X I T  or  Q U I T
        if( ( strcmp( cmd, "exit" ) == 0 ) || ( strcmp( cmd, "quit" ) == 0 ) )
        {   break; }
        // O P E N
        else if( strcmp( cmd, "open" ) == 0 )
        {
            if( token_count == 2 )
            {
                if( fp )
                {   printf("Error: File system image already open.\n"); }
                else if( !( fp = fopen( tokens[1], "r" ) ) )
                {   printf("Error: File system image not found.\n"); }
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: open [filename]\n");
            }
        }
        // C L O S E
        else if( strcmp( cmd, "close" ) == 0 )
        {
            if( token_count == 1 )
            {
                if( !fp )
                {   printf("Error: File system not open.\n"); }
                else 
                {
                    fclose(fp);
                    fp = NULL;
                }
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: close\n");
            }
        }
        // Prevent command execution if no file is open
        else if( ( !fp ) && ( strcmp( cmd, "" ) != 0 ) )
        {   printf("Error: File system image must be opened first.\n"); }
        // I N F O
        else if( strcmp( cmd, "info" ) == 0 )
        {
            if( token_count == 1 )
            {
                
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: info\n");
            }
        }
        // S T A T
        else if( strcmp( cmd, "stat" ) == 0 )
        {
            if( token_count == 2 )
            {
                
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: stat [filename or directory]\n");
            }
        }
        // G E T
        else if( strcmp( cmd, "get" ) == 0 )
        {
            if( token_count == 2 )
            {
                
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: get [filename]\n");
            }
        }
        // C D
        else if( strcmp( cmd, "cd" ) == 0 )
        {
            if( token_count == 2 )
            {
                
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: cd [directory]\n");
            }
        }
        // L S
        else if( strcmp( cmd, "ls" ) == 0 )
        {
            if( token_count == 2 )
            {
                
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: ls [directory]\n");
            }
        }
        // R E A D
        else if( strcmp( cmd, "read" ) == 0 )
        {
            if( token_count == 4 )
            {
                
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: read [filename] [position] [number of bytes]\n");
            }
        }
        // V O L U M E
        else if( strcmp( cmd, "volume" ) == 0 )
        {
            if( token_count == 1 )
            {
                
            }
            else
            {
                printf("Error: Incorrect number of arguments.\n");
                printf("Usage: volume\n");
            }
        }
        // Command not supported
        else if( strcmp( cmd, "" ) != 0 )
        {   printf("Error: Command not supported.\n"); }

        free_tokens( tokens, token_count );
    }

    free( cmd_str );

    return 0;
}

/*
 * Function: tokenize_cmd
 * Parameters: The command line argument string and a tokens array
 *             where the tokens will be stored 
 * Returns: The number of tokens
 * Description: Tokenizes command line argument using WHITESPACE
 *              as the delimeter
 * Side Effects: Tokens array is filled with parsed arguments;
 *               Empty string if there are no arguments
*/
int tokenize_cmd( char * cmd_str, char** tokens )
{
    // arg_ptr points to the token parsed by strsep
    char * arg_ptr;
    char * working_str = strdup( cmd_str );

    // track the original allocated space to deallocate the correct
    // amount of space since the working_str pointer will be moving
    char * working_root = working_str;

    // Tokenize cmd_str with WHITESPACE as the demiliter
    int token_count = 0;    // tracks # of valid arguments
    while( ( (arg_ptr = strsep( &working_str, WHITESPACE )) != NULL ) &&
             ( token_count < MAX_NUM_ARGUEMENTS ) )
    {
        if( strcmp(arg_ptr, "") != 0 )
        {
            tokens[token_count] = strndup( arg_ptr, MAX_COMMAND_SIZE );
            ++token_count;
        }
    }

    // If there were no valid tokens, add an empty string
    // for token[0] to indicate an empty command
    if( token_count == 0 )
    {
        tokens[0] = "";
    }

    free( working_root );
    return token_count;
}

/*
 * Function: free_tokens
 * Parameters: The tokens array & the number of tokens in the array
 * Returns: None
 * Description: Frees the dynamically allocated memory in array
 */
void free_tokens( char**token, int token_count )
{
    int i;
    for( i = 0; i < token_count; i++ ) {
        free( token[i] );
    }
}

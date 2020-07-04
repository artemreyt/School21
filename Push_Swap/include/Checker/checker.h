#ifndef CHECKER_H
#define CHECKER_H

#define OK_CODE     0
#define KO_CODE     1
#define ERROR_CODE  2

#define OK_MSG      "OK"
#define KO_MSG      "KO"
#define ERROR_MSG   "Error"

#define WHITESPACES " \t\n\r"

int     checker_parse_arguments(int argc, char **argv, int **arr, int *size);
int     launch_checker(int argc, char **argv);

#endif

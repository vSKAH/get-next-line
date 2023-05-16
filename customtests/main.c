#include "../get_next_line.h"
#include "stdio.h"
#include "fcntl.h"

int main() {


   int file_descriptor = open("/nfs/homes/jbadaire/CLionProjects/get-next-line/customtests/tests/alternate_line_nl_no_nl", O_RDONLY);
    char *line = get_next_line(file_descriptor);
    printf("Program Start\n");

    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(file_descriptor);
    }
    close(file_descriptor);
    return 0;

}
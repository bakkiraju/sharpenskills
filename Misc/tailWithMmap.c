#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


#include <errno.h>

// Restrictions:
// -n number = number is always a number and it is > 0
// path to file is always an absolute path, you can access and read the file
// the file contents have no holes, are ASCII
// You can guarantee that this code only needs to run on Linux: nothing crossplatform is needed
// Newline will be the '\n' character

int main( int argc, char ** argv ) {
    int numberOfLines = 5; //atoi(argv[1]);
    const char * path = __FILE__ ; // argv[2];
    size_t size;
    int fd = open ( path, O_RDONLY );
    printf("File fd %d\n", fd);
    struct stat _stat;
    stat(path, &_stat);
    printf("File size %ld\n", _stat.st_size);
    size = _stat.st_size;
    /* Memory-map the file. */
    const char * mapped = (const char *) mmap (0, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED )
    {
        printf("mmap %s failed: %s\n",
           path, strerror (errno));
        return -1;   
    }

    /* Now do something with the information. */
    long lines = 0 ;
    for (int i = 0; i < size; i++) {
        char c;
        c = mapped[i];
        if(c == '\n')
        {
           lines++; 
        }         
     }
     
    printf("Number of lines in file : %ld\n", lines);

    int numOfLinesToSkip = lines - numberOfLines;

    printf("Number of lines to skip : %d\n", numOfLinesToSkip);
    int i;
    for (i = 0; i < size && numOfLinesToSkip > 0; i++) {
        char c;
        c = mapped[i];
        if(c == '\n')
        {
            numOfLinesToSkip--;
        }         
     }
     write(1, &mapped[i], _stat.st_size - i);
     munmap(&mapped, _stat.st_size);
     return 0;
}
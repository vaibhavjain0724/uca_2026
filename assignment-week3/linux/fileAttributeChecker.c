#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int BUFFER_SIZE = 1052;




int main(int argc, char* argv[]){
    if(argc != 2){
        printf("format: %s <file path>\n", argv[0]);
    }

    int fd = open( argv[1] , O_RDONLY  );

    char buf[BUFFER_SIZE];


    struct stat fileInfo;

    printf("=== File Attributes for: %s ===\n", argv[1]);

    fstat( fd , &fileInfo );

    /*
    struct stat {
         dev_t    st_dev;    device inode resides on
         ino_t    st_ino;     inode's number 
         mode_t   st_mode;    inode protection mode 
         nlink_t  st_nlink;  number of hard links to the file 
         uid_t    st_uid;    user-id of owner
         gid_t    st_gid;    group-id of owner
         dev_t    st_rdev;   device type, for special file inode
         struct timespec st_atimespec;   time of last access
         struct timespec st_mtimespec;   time of last data modification
    */
    //using man 2 stat | grep "st_"

    /*fileInfo.st_ino        // inode number
        fileInfo.st_mode       // file type + permissions
        fileInfo.st_nlink      // hard link count
        fileInfo.st_uid        // owner's user ID
        fileInfo.st_gid        // owner's group ID
        fileInfo.st_size       // size in bytes
        fileInfo.st_blksize    // preferred I/O block size
        fileInfo.st_blocks     // allocated blocks
    */
    
    if (S_ISREG(fileInfo.st_mode))
        printf("File Type: Regular File\n");
    else if (S_ISDIR(fileInfo.st_mode))
        printf("File Type: Directory\n");
    else
        printf("File Type: Other\n");
    
    printf("Permissions: %o\n", fileInfo.st_mode);
}
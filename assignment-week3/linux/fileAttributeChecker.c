// #include <stdio.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// int BUFFER_SIZE = 1052;




// int main(int argc, char* argv[]){
//     if(argc != 2){
//         printf("format: %s <file path>\n", argv[0]);
//     }

//     int fd = open( argv[1] , O_RDONLY  );

//     char buf[BUFFER_SIZE];


//     struct stat fileInfo;

//     printf("=== File Attributes for: %s ===\n", argv[1]);

//     fstat( fd , &fileInfo );

//     /*
//     struct stat {
//          dev_t    st_dev;    device inode resides on
//          ino_t    st_ino;     inode's number 
//          mode_t   st_mode;    inode protection mode 
//          nlink_t  st_nlink;  number of hard links to the file 
//          uid_t    st_uid;    user-id of owner
//          gid_t    st_gid;    group-id of owner
//          dev_t    st_rdev;   device type, for special file inode
//          struct timespec st_atimespec;   time of last access
//          struct timespec st_mtimespec;   time of last data modification
//     */
//     //using man 2 stat | grep "st_"

//     /*fileInfo.st_ino        // inode number
//         fileInfo.st_mode       // file type + permissions
//         fileInfo.st_nlink      // hard link count
//         fileInfo.st_uid        // owner's user ID
//         fileInfo.st_gid        // owner's group ID
//         fileInfo.st_size       // size in bytes
//         fileInfo.st_blksize    // preferred I/O block size
//         fileInfo.st_blocks     // allocated blocks
//     */
    
//     if (S_ISREG(fileInfo.st_mode))
//         printf("File Type: Regular File\n");
//     else if (S_ISDIR(fileInfo.st_mode))
//         printf("File Type: Directory\n");
//     else
//         printf("File Type: Other\n");
    
//     printf("Permissions: %o\n", fileInfo.st_mode);

//     printf("File Size: %llu bytes\n", fileInfo.st_size);

//     printf("Hard Links Count: %d\n", fileInfo.st_nlink);

//     printf("Owner (UID) %d\n", fileInfo.st_uid);

//      printf("Group (GID) %d\n", fileInfo.st_gid);

//     printf("Last access time:" , fileInfo.st_atimespec);

//     printf("Last access time:" , fileInfo.st_mtimespec);

    
// }

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Format: %s <file path>\n", argv[0]);
        return 1;
    }

    // Open the file
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat fileInfo;

    // Get file information
    if (fstat(fd, &fileInfo) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

    // File type
    if (S_ISREG(fileInfo.st_mode))
        printf("File Type:            Regular File\n");
    else if (S_ISDIR(fileInfo.st_mode))
        printf("File Type:            Directory\n");
    else if (S_ISLNK(fileInfo.st_mode))
        printf("File Type:            Symbolic Link\n");
    else
        printf("File Type:            Other\n");

    // Permissions
    printf("Permissions:          0%o\n",
           fileInfo.st_mode & 0777);

    // Size
    printf("File Size:            %lld bytes\n",
           (long long)fileInfo.st_size);

    // Hard links
    printf("Hard Links Count:     %llu\n",
           (unsigned long long)fileInfo.st_nlink);

    // Owner
    printf("Owner (UID):          %u\n",
           (unsigned int)fileInfo.st_uid);

    // Group
    printf("Group (GID):          %u\n",
           (unsigned int)fileInfo.st_gid);

    // Times
    printf("Last Access Time:     %s",
           ctime(&fileInfo.st_atime));

    printf("Last Modification:    %s",
           ctime(&fileInfo.st_mtime));

    printf("Status Change Time:   %s",
           ctime(&fileInfo.st_ctime));

    close(fd);

    return 0;
}
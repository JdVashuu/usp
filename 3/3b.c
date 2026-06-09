#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct dirent *d;
    struct stat m;

    DIR *dp = (argc > 1) ? argv[1] : ".";
    dp = opendir(dp);
    if (dp) {
        while (d = readdir(dp)) {
        stat(d->d_name, &m);
        printf("%ld %o %d %d %s %s\n", m.st_ino, m.st_mode, m.st_uid, m.st_gid,
                ctime(&m.st_atime), d->d_name);
        }
    }
}
Commands to Execute:
vi program_name.c (type program here)
cc program_name.c
./a.out <path of the directory> [Ex. /home/cs6a16/Downloads ]

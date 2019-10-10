#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>

static int num_dirs, num_regular;

bool is_dir(const char* path) {
  /*
   * Use the stat() function (try "man 2 stat") to determine if the file
   * referenced by path is a directory or not.  Call stat, and then use
   * S_ISDIR to see if the file is a directory. Make sure you check the
   * return value from stat in case there is a problem, e.g., maybe the
   * the file doesn't actually exist.
   */
	
	
	struct stat buffer;
	int n = stat(path,&buffer);
	if(n==0){
	    return S_ISDIR(buffer.st_mode);
	}else{
		exit(n);
	}


}

/* 
 * I needed this because the multiple recursion means there's no way to
 * order them so that the definitions all precede the cause.
 */
void process_path(const char*);

void process_directory(const char* path) {
  /*
   * Update the number of directories seen, use opendir() to open the
   * directory, and then use readdir() to loop through the entries
   * and process them. You have to be careful not to process the
   * "." and ".." directory entries, or you'll end up spinning in
   * (infinite) loops. Also make sure you closedir() when you're done.
   *
   * You'll also want to use chdir() to move into this new directory,
   * with a matching call to chdir() to move back out of it when you're
   * done.
   */

	DIR *dir;
    	char* dp;

	num_dirs++;

//	printf("Current path: %s\n", path);

	char cwd[1024];
	getcwd(cwd, sizeof(cwd));

//	printf("cwd: %s\n", cwd);
	chdir(path);
	if((dir =opendir("."))==NULL){
		perror("Cannot open dir");
		exit(1);
	}
	//strcmp
	struct dirent* ent;
	while((ent = readdir(dir)) != NULL){
		dp = ent -> d_name;
//		printf("dp: %s\n", dp);
		if(strcmp(dp,".")!=0&&strcmp(dp,"..")!=0){
			process_path(dp);
		}
//		printf("Done with %s\n", dp);
	}
//	printf("Done with while\n");
	closedir(dir);
	chdir(cwd);
	


}

void process_file(const char* path) {
  /*
   * Update the number of regular files.
   */
	num_regular++;
}

void process_path(const char* path) {
//	printf("In process_path: %s\n", path);
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}

#include <stdio.h>
#include <assert.h>

#define CHAR 1
#define WORD 2
#define LINE 4

void print_usage(char* name) {
  printf("Usage: %s <file> <mode>\nwhere <mode> is\n"
         "  -c\tcount the number of characters in <file>\n"
         "  -w\tcount the number of words in <file>\n"
         "  -l\tcount the number of newlines in <file>\n", name);
}

int parse_params(int argc, char** argv, int* mode, char** file_name) {
  if (argc != 3) {
    return 0;
  }

  if (*argv[1] != '-') return 0;
  if (*(argv[1] + 1) == '\0') return 0;
  if (*(argv[1] + 2) != '\0') return 0;

  switch (*(argv[1] + 1)) {
  case 'c': *mode = CHAR; break;
  case 'w': *mode = WORD; break;
  case 'l': *mode = LINE; break;
  default: return 0;
  }

  *file_name = argv[2];
  
  return 1;
}

int main(int argc, char** argv) {
  // Parse command line arguments
  int mode;
  char* file_name;

  int ok = parse_params(argc, argv, &mode, &file_name);

  if (!ok) {
    print_usage(argv[0]);
    return -1;
  }

  // Open the file
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error: can't open file %s.\n", file_name);
    return -1;
  }

  // Read contents of file and count
  char buf[128];
  unsigned int ccount = 0;
  unsigned int wcount = 0;
  unsigned int lcount = 0;

  int in_word = 0;
  while (fgets(buf, sizeof(buf), file)) {
    for (int i = 0; buf[i] != '\0'; ++i) {
      if (ccount + 1 < ccount) {
        printf("Error: file too large.");
        return -1;
      }
      ccount++;

      switch (buf[i]) {
      case '\n': lcount++;
      case ' ':
      case '\t': in_word = 0; break;
      default: if (!in_word) {
          in_word = 1;
          wcount++;
        }
      }
        
    }
  }

  // Close the file
  fclose(file);

  // Pick result to display
  int res;
  switch (mode) {
  case CHAR: res = ccount; break;
  case WORD: res = wcount; break;
  case LINE: res = lcount; break;
  }

  // Display result
  printf("%d %s\n", res, file_name);
  
  return 0;
}

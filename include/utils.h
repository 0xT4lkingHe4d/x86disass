#include <linux/types.h>
#include <stdio.h>
#include <ctype.h>

#define BRED	"\e[1;31m"
#define RED		"\e[0;31m"
#define BGRN	"\e[1;32m"
#define GRN		"\e[0;32m"
#define BBLUE	"\e[1;34m"
#define BLUE	"\e[0;34m"
#define YLW		"\e[0;33m"
#define BYLW	"\e[1;33m"
#define CYAN	"\e[0;36m"
#define BCYAN	"\e[1;36m"
#define WHT		"\e[0;37m"
#define BWHT	"\e[1;37m"
#define CRST	"\e[0m"

#define color(c, str)	c str CRST

#define prf		printf		//extern int (*prf)(const char *f, ...);
#define pr		puts		//extern int (*pr)(const char *f);

#define N_BITS_MAX(n)		((1ll << (n)) -1)

/*
 * This file was generated by the mkbuiltins program.
 */

#include "shell.h"
#include "builtins.h"

int bgcmd(int, char **);
int fgcmd(int, char **);
int breakcmd(int, char **);
int cdcmd(int, char **);
int commandcmd(int, char **);
int dotcmd(int, char **);
int echocmd(int, char **);
int evalcmd(int, char **);
int execcmd(int, char **);
int exitcmd(int, char **);
int exportcmd(int, char **);
int falsecmd(int, char **);
int getoptscmd(int, char **);
int hashcmd(int, char **);
int jobscmd(int, char **);
int localcmd(int, char **);
int printfcmd(int, char **);
int pwdcmd(int, char **);
int readcmd(int, char **);
int returncmd(int, char **);
int setcmd(int, char **);
int shiftcmd(int, char **);
int timescmd(int, char **);
int trapcmd(int, char **);
int truecmd(int, char **);
int typecmd(int, char **);
int umaskcmd(int, char **);
int unaliascmd(int, char **);
int unsetcmd(int, char **);
int waitcmd(int, char **);
int aliascmd(int, char **);
int ulimitcmd(int, char **);
int testcmd(int, char **);
int killcmd(int, char **);

const struct builtincmd builtincmd[] = {
	{ ".", dotcmd, 3 },         // 0
	{ ":", truecmd, 3 },        // 1
	{ "[", testcmd, 0 },        // 2
	{ "alias", aliascmd, 6 },   // 3
#if JOBS
	{ "bg", bgcmd, 2 },
#endif
	{ "break", breakcmd, 3 },   // 4
	{ "cd", cdcmd, 2 },         // 5
	{ "chdir", cdcmd, 0 },      // 6
	{ "command", commandcmd, 2 }, // 7
	{ "continue", breakcmd, 3 }, // 8
	{ "echo", echocmd, 0 },     // 9
	{ "eval", NULL, 3 },        // 10
	{ "exec", execcmd, 3 },     // 11
	{ "exit", exitcmd, 3 },     // 12
	{ "export", exportcmd, 7 }, // 13
	{ "false", falsecmd, 2 },   // 14
#if JOBS
	{ "fg", fgcmd, 2 },
#endif
	{ "getopts", getoptscmd, 2 }, // 15
	{ "hash", hashcmd, 2 },     // 16
	{ "jobs", jobscmd, 2 },     // 17
	{ "kill", killcmd, 2 },     // 18
	{ "local", localcmd, 7 },   // 19
	{ "printf", printfcmd, 0 }, // 20
	{ "pwd", pwdcmd, 2 },       // 21
	{ "read", readcmd, 2 },     // 22
	{ "readonly", exportcmd, 7 }, // 23
	{ "return", returncmd, 3 }, // 24
	{ "set", setcmd, 3 },       // 25
	{ "shift", shiftcmd, 3 },   // 26
	{ "test", testcmd, 0 },     // 27
	{ "times", timescmd, 3 },   // 28
	{ "trap", trapcmd, 3 },     // 29
	{ "true", truecmd, 2 },     // 30
	{ "type", typecmd, 2 },     // 31
#ifdef HAVE_GETRLIMIT
	{ "ulimit", ulimitcmd, 2 },
#endif
	{ "umask", umaskcmd, 2 },   // 32
	{ "unalias", unaliascmd, 2 }, // 33
	{ "unset", unsetcmd, 3 },   // 34
	{ "wait", waitcmd, 2 },     // 35
};

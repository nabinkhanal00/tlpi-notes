#pragma once

// prints a message on the standard error
// argument list is same as for printf()
// terminating newline character is automatically appended to the output string
void errMsg(const char *format, ...);

#ifdef __GNUC__
#define NORETURN __attribute__((__noreturn__))
#else
#define NONORETURN
#endif

// acts like errMsg()
// also terminates the program
void errExit(const char *format, ...) NORETURN;

// similar to errExit()
// doesn't flush standard output
// terminates the process by calling _exit() instead of exit()
// this causes the process to terminate without flushing stdio buffers or invoking exit handlers
void err_exit(const char *format, ...) NORETURN;

// same as errExit()
// instead of printing the error text correspoiding to the current value of errno, it prints the text corresponding to the error number given in the argument
void errExitEn(int errnum, const char *format, ...) NORETURN;

void fatal(const char *format, ...) NORETURN;

void usageErr(const char *format, ...) NORETURN;

void cmdLineErr(const char *format, ...) NORETURN;

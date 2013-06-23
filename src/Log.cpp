/*
 * log.cpp
 *
 *  by zhanqu
 *  date 2013-6-22
 */

#include "Log.h"

FILE* Log::file = stdout;

int Log::i(const char* fmt, ...) {
	if (file == stdout) {
		fprintf(file, "\033[37;1m%-10s", "[info]"); // green
	}
	// 增加颜色输出
	va_list args;
	int n;
	va_start(args, fmt);
	n = vfprintf(file, fmt, args);
	va_end(args);

	_postLog();
	return n;
}

int Log::w(const char* fmt, ...) {
	if (file == stdout) {
		fprintf(file, "\033[33;1m%-10s", "[warn]"); // yellow
	}
	// 增加颜色输出
	va_list args;
	int n;
	va_start(args, fmt);
	n = vfprintf(file, fmt, args);
	va_end(args);

	_postLog();
	return n;
}

int Log::e(const char* fmt, ...) {
	if (file == stdout) {
		fprintf(file, "\033[31;1m%-10s", "[error]"); //red
	}
	// 增加颜色输出
	va_list args;
	int n;
	va_start(args, fmt);
	n = vfprintf(file, fmt, args);
	va_end(args);

	_postLog();
	return n;
}

void Log::_postLog() {
	if (file == stdout) {
		fprintf(file, "\033[0m\n");
	} else {
		fprintf(file, "\n");
	}
}

/*
 int Log::_log(const char* fmt, char*()) {
 va_list args;
 int n;
 va_start(args, fmt);
 n = vsprintf(sprint_buf, fmt, args);
 va_end(args);
 write(stdout, sprint_buf, n);
 return n;
 }
 */


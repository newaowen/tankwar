/*
 * log.cpp
 *
 *  by zhanqu
 *  date 2013-6-22
 */

#include "Log.h"

int Log::i(const char* fmt, ...) {
	fprintf(file, "\033[1m\033[40;34m");
		// 增加颜色输出
		va_list args;
		int n;
		va_start(args, fmt);
		n = vfprintf(file, fmt, args);
		va_end(args);

		fprintf(file, "\033[0m\n");
		return n;
}

int Log::w(const char* fmt, ...) {
	fprintf(file, "\033[1m\033[40;34m");
	// 增加颜色输出
	va_list args;
	int n;
	va_start(args, fmt);
	n = vfprintf(file, fmt, args);
	va_end(args);

	fprintf(file, "\033[0m\n");
	return n;
}

int Log::e(const char* fmt, ...) {
	fprintf(file, "\033[1m\033[40;34m");
	// 增加颜色输出
	va_list args;
	int n;
	va_start(args, fmt);
	n = vfprintf(file, fmt, args);
	va_end(args);

	fprintf(file, "\033[0m\n");
	return n;
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


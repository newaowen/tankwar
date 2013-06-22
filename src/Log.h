/*
 * =====================================================================================
 *
 *       Filename:  Log.h
 *
 *    Description:  日志记录
 *
 *        Version:  1.0
 *        Created:  2012年10月29日 22时47分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _LOG_
#define _LOG_

#include <stdio.h>
#include <stdarg.h>

#define BUFSIZE 1024

class Log {

protected:
	//char buf[BUFSIZE];
	FILE *file;
	//int _log(const char* str, ...);

public:
	Log() {
		file = stdout;
	}
	~Log() {}

	void setOut(const char* path); 	// 设置输出,默认为标准输出
	int i(const char* str, ...); // info
	int w(const char* str, ...); // warn
	int e(const char* str, ...); // error

};

#endif


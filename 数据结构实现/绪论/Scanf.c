//
//  Scanf.c
//  数据结构_严蔚敏_C
//
//  Created by Jason on 2018/3/10.
//  Copyright © 2018年 Jason. All rights reserved.
//

#ifndef Scanf_C
#define Scanf_C

#include <stdio.h>
#include <string.h>
#include <stdarg.h> //提供宏 va_list va_start va_arg va_end
#include <ctype.h>  //提供宏 isprint 原型

/**
 自定义的数据录入函数，用于从fp中读取格式化的输入
 \\\\
 与fscanf函数不同的是，Scanf函数会只读取ASCII码
 不会读取中文字符
 
 @param fp 文件
 @param format 格式化输入传
 @param ... xx
 @return int xx
 */
int Scanf(FILE *fp, char *format, ...) {
    int *i;
    char *ch, *s;
    float *f;
    int count, k, n;
    size_t len;
    int tmp;
    va_list ap;
    
    len = strlen(format);
    va_start(ap, format);
    for (count = 0, k = 2; k <= len; k = k + 2) {
        while ((tmp = getc(fp)) != EOF) { //跳过非西文字符
            if (tmp >= 0 && tmp <= 127) {
                ungetc(tmp, fp);          //遇到收割西文字符，将西文字符放入输入流
                break;
            }
        }
        if (tmp == EOF)
            break;
        if (format[k - 1] == 'c') { //读取字符
            ch = va_arg(ap, char *);
            if (tmp != EOF) {
                count += fscanf(fp, "%c", ch);
            }
        }
        if (format[k - 1] == 'd') { //读取整数
            i = va_arg(ap, int *);
            while ((tmp = getc(fp)) != EOF) {
                if ((tmp >= '0' && tmp <= '9') || tmp == '+' || tmp == '-') {
                    ungetc(tmp, fp);
                    break;
                }
            }
            if (tmp != EOF)
                count += fscanf(fp, "%d", i);
        }
        if (format[k - 1] == 'f') { //读取浮点数
            f = va_arg(ap, float *);
            while ((tmp = getc(fp)) != EOF) {
                if ((tmp >= '0' && tmp <= '9') || tmp == '+' || tmp == '-' || tmp == '.') {
                    ungetc(tmp, fp);
                    break;
                }
            }
            if (tmp != EOF)
                count += fscanf(fp, "%f", f);
        }
        if (format[k - 1] == 's') { //读取字符串
            s = va_arg(ap, char *);
            while ((tmp = getc(fp)) != EOF && (!isprint(tmp) || tmp == ' '))
                ;
            n = 0;
            if (!feof(fp)) {
                ungetc(tmp, fp);
                while ((tmp = getc(fp)) != EOF) {
                    if (isprint(tmp) && tmp != ' ') {
                        s[n++] = tmp;
                    } else
                        break;
                }
                ungetc(tmp, fp);
            }
            s[n] = '\0';
            count++;
        }
    }
    va_end(ap);
    return count;
}

#endif

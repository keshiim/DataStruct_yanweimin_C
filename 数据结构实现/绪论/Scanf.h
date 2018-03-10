//
//  Scanf.h
//  数据结构_严蔚敏_C
//
//  Created by Jason on 2018/3/10.
//  Copyright © 2018年 Jason. All rights reserved.
//

#ifndef Scanf_h
#define Scanf_h

//状态码
#define TRUE            1 //真
#define FALSE           0 //假
#define YES             1 //是
#define NO              0 //否
#define OK              1 //通过
#define ERROR           0 //错误
#define SUCESS          1 //成功
#define UNSUCESS        0 //失败
#define INFEASIBLE     -1 //不可行

#ifndef _MATH_H_          //
#define OVERFLOW   -2     //堆栈上益
#define UNDERFLOW  -3     //堆栈下益
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

/* 状态码识别类型 */
typedef int STATUS;

/* 宏定义 */
// 函数暂停一段时间
#define Wait(x)\
{\
    double _Loop_Num_;\
    for (_Loop_Num_ = 0.01; _Loop_Num_ <= 100000*x; _Loop_Num_ += 0.01)\
        ;\
}//设立一个空循环

//摁Enter键
#define PressEnter \
{\
    fflush(stdin);\
    printf("Press Enter...");\
    getchar();\
    fflush(stdin);\
}

#endif /* Scanf_h */

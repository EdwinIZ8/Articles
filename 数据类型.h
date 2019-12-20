/*本文档的内容：
  为了适应张家馨的习惯，增强程序的通用性和可移植性，同时也便于阅读与写作，张家馨使用typedef声明了一些新的类型名，用来定义变量；使用#define简单地替换了一些字符串；还定义了一些新的操作。
  这将在预编译时起作用。
 *
 *要写成这样子：
  
  甲是基本整数；    /*int 甲*/
  乙是字符；       /*char 乙*/
  丙是基本整数指针；/*int* 丙*/
  丁是短整数数组；  /*short int[] 丁*/
  戊是基本整数函数；/*int 戊()*/

  是的作用是对调前后文字的顺序。
*/
#pragma once

/*+----------------------------------------------------------------------------------------+*/
/*|   					第一部分 新的类型			            |*/
/*+----------------------------------------------------------------------------------------+*/
/*
				|基本整数(int)
				|短整数(short int)
				|长整数(long int)
			|整形类型|*双长整数(long long int)
			|	|字符(char)
			|	|*布尔数(bool)
		|基本类型|
		|	|	|短小数(float)
		|	|浮点类型|长小数(double)
		|	|	|复数小数(float_complex,double_comple,long long_comple)
		|
	数据类型|枚举类型(enum)
		|空类型(void)
		|
		|	|指针(*)
		|	|数组([])
		|派生类型|结构体(struct)
			|共同体(union)
			|函数

			图1 C语言允许使用的类型（图中有*的是C99所增加的）
*/

typedef int			基本整数;
typedef short int		短整数;
typedef long int		长整数;
typedef long long int		双长整数;
typedef	char			字符;
typedef bool			布尔数;
typedef float			短小数;
typedef double			长小数;
typedef float_complex		短复数小数;
typedef double_comple		长复数小数;
typedef long long_comple	双长复数小数;
#define 枚举类型 enum;
typedef void 			空类型;
#define 指针 *;
#define 结构体 struct;
#define 共同体 union;

typedef struct
{
	char	红色;
	char	绿色;
	char	蓝色;
}颜色;

typedef struct
{
	char		红色;
	char		绿色;
	char		蓝色;
	short int	横坐标;
	short int	纵坐标;
}点;

typedef (const char) 文件名;

/*+----------------------------------------------------------------------------------------+*/
/*|					第二部分 替换的字符串				   |*/
/*+----------------------------------------------------------------------------------------+*/
#define 引用		include;
#define 规定		define;
#define 主函数		main;
#define 标准输入输出	stdio;
#define 输出		printf;
#define	输入		scanf;
#define 正确		1;
#define 错误		0;
#define 成功		1;
#define 失败		0;

/*+----------------------------------------------------------------------------------------+*/
/*|                                     第三部分 新的操作。                                   |*/
/*+----------------------------------------------------------------------------------------+*/
#define 最大数(a,b) (((a)>(b))?(a):(b))
#define 最小数(a,b) (((a)<(b))?(a):(b))

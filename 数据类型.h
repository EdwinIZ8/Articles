/*本文档的内容：
  为了适应张家馨的习惯，增强程序的通用性和可移植性，使用typedef声明了一些新的类型名，用来定义变量；使用#define简单地替换了一些字符串，这将在预编译时起作用。
*/
#pragma once

/*+----------------------------------------------------------------------------------------+*/
/*|   					第一部分 新的类型				   |*/
/*+----------------------------------------------------------------------------------------+*/
/*
				|基本整形(int)
				|短整形(short int)
				|长整形(long int)
			|整形类型|*双长整形(long long int)
			|	|字符型(char)
			|	|*布尔型(boot)
		|基本类型|
		|	|	|单精度浮点型(float)
		|	|浮点类型|双精度浮点型(double)
		|	|	|复数浮点型(float_complex,double_comple,long long_comple)
		|
	数据类型|枚举类型(enum)
		|空类型(void)
		|
		|	|指针类型(*)
		|	|数组类型([])
		|派生类型|结构体类型(struct)
			|共同体类型(union)
			|函数类型

			图1 C语言允许使用的类型（图中有*的是C99所增加的）
*/

typedef int			基本整形;
typedef short int		短整形;
typedef long int		长整形;
typedef long long int		双长整形;
typedef	char			字符型;
typedef bool			布尔型;
typedef float			单精度浮点型;
typedef double			双精度浮点型;
typedef float_complex		单精度复数浮点型;
typedef double_comple		双精度复数浮点型;
typedef long long_comple	双长复数浮点型;
#define 枚举类型 enum;
typedef void 			空类型;
#define 指针类型 *;
#define 结构体类型 struct;
#define 共同体类型 union;

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
#define 包含		include;
#define 定义		define;
#define 主函数		main;
#define 标准输入输出	stdio;
#define 输出		printf;
#define	输入		scanf;
#define 正确		1;
#define 错误		0;
#define 成功		1;
#define 失败		0;

// Project2.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "Project2.h"


// 这是导出变量的一个示例
PROJECT2_API int nProject2=0;

// 这是导出函数的一个示例。
PROJECT2_API int fnProject2(void)
{
    return 0;
}

PROJECT2_API int GetInt()
{
	return 2020;
}

// 这是已导出类的构造函数。
CProject2::CProject2()
{
    return;
}

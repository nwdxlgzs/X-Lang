#ifndef XLANG_H
#define XLANG_H
#include "xlangconf.h"

/**
 * @brief XLANG类型定义
 * 提供一个完整的255个基本类型定义范围(0xff为未定义)
 * [vm-type]标记的是对虚拟机而言需要的类型，没标注的是对虚拟机等具体底层而言标记的类型
 */
typedef enum XLANG_TYPE
{
    XTYPE_UNDEF = 0xff,      // 未定义(默认分配的值)
    XTYPE_NULL = 0,          // [vm-type]空值
    XTYPE_BOOLEAN = 1,       // [vm-type]布尔值
    XTYPE_INTEGER = 2,       // [vm-type]整数
    XTYPE_DOUBLE = 3,        // [vm-type]浮点数
    XTYPE_STRING = 4,        // [vm-type]字符串
    XTYPE_ARRAY = 5,         // [vm-type]数组
    XTYPE_TABLE = 6,         // [vm-type]表
    XTYPE_FUNCTION = 7,      // [vm-type]函数
    XTYPE_LIGHTUSERDATA = 8, // [vm-type]轻量用户数据(指针)
    XTYPE_USERDATA = 9,      // [vm-type]用户数据(一片内存的指针)
    XTYPE_MUTEX = 10,        // [vm-type]互斥量
    XTYPE_THREAD = 11,       // [vm-type]线程
    XTYPE_OBJECT = 12,       // [vm-type]对象|实例
    XTYPE_CLASS = 13,        // [vm-type]类
    XTYPE_PROTO = 14,        // 原型
} XLANG_TYPE;
/**
 * @brief XLANG整数修饰
 * |other:5|type:2|sign:1|
 */
typedef enum XLANG_INT_DECORATE
{
    XDECO_UNSIGNED_INT = 0, // 无符号，关键标注：U/u
    XDECO_SIGNED_INT = 1,   // 有符号，关键标注：S/s/缺省
    XDECO_INT8 = 1 << 1,    // 8位整数，关键标注：B/b
    XDECO_INT64 = 4 << 1,   // 64位整数，关键标注：L/l/缺省
    // 关键标注：U、S优先于B、L
    // 运算降级：有符号服从无符号，int8服从int64
} XLANG_INT_DECORATE;
/**
 * @brief XLANG函数修饰
 * |other:6|type:2|
 */
typedef enum XLANG_FUNC_DECORATE
{
    XDECO_CCLOSURE = 0, // C闭包，携带0到255个变量
    XDECO_XCLOSURE = 1, // X闭包，携带0到255个变量
    XDECO_METHOD = 2,   // 方法，携带一个实例或者类
    XDECO_CFUNC = 3,    // C函数，不携带变量
} XLANG_FUNC_DECORATE;
/**
 * @brief 标记类型是可回收的
 * |mark:1|other:7|
 */
#define BITMASK_ISCOLLECTABLE (1 << 7)
#define SETCOLLECTABLE(t) (t | BITMASK_ISCOLLECTABLE)
#define ISCOLLECTABLE(t) (t & BITMASK_ISCOLLECTABLE)

#endif // XLANG_H
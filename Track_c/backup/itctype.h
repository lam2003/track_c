/************************************************************************** 
    *  @Copyright (c) 2015, XueYB, All rights reserved. 
 
    *  @file     : itctype.h 
    *  @version  : ver 1.0 
 
    *  @author   : XueYB 
    *  @date     : 2015/10/09 11:49 
    *  @brief    : 基础的一些数据结构 
**************************************************************************/
#ifndef itctype_h_
#define itctype_h_

#include <stdio.h>

typedef long long int64;
typedef unsigned long long uint64;

typedef unsigned char uchar;
typedef unsigned short ushort;

#define bool int
#define false 0
#define true 1

#define ITC_PI   3.1415926535897932384626433832795
#define ITC_LOG2 0.69314718055994530941723212145818

#define ITC_SWAP(a,b,t) ((t) = (a), (a) = (b), (b) = (t))

#define ITC_MIN(a,b)  ((a) > (b) ? (b) : (a))
#define ITC_MAX(a,b)  ((a) < (b) ? (b) : (a))
/* min & max without jumps */
#define  ITC_IMIN(a, b)  ((a) ^ (((a)^(b)) & (((a) < (b)) - 1)))

#define  ITC_IMAX(a, b)  ((a) ^ (((a)^(b)) & (((a) > (b)) - 1)))

/* absolute value without jumps */
#define  ITC_CMP(a,b)    (((a) > (b)) - ((a) < (b)))
#define  ITC_SIGN(a)     ITC_CMP((a),0)


#define ITC_CN_MAX     512			//不应超过2047
#define ITC_CN_SHIFT   3
#define ITC_DEPTH_MAX  (1 << ITC_CN_SHIFT)

#define ITC_8U   0
#define ITC_8S   1
#define ITC_16U  2
#define ITC_16S  3
#define ITC_32S  4
#define ITC_32F  5
#define ITC_64F  6
#define ITC_USRTYPE1 7

#define ITC_MAT_DEPTH_MASK       (ITC_DEPTH_MAX - 1)									// 0000 0111
#define ITC_MAT_DEPTH(flags)     ((flags) & ITC_MAT_DEPTH_MASK)							//获取深度（低3位）

#define ITC_MAKETYPE(depth,cn) (ITC_MAT_DEPTH(depth) + (((cn)-1) << ITC_CN_SHIFT))		//低3位表示类型，其余高位中表示通道数
#define ITC_MAKE_TYPE ITC_MAKETYPE

#define ITC_8UC1 ITC_MAKETYPE(ITC_8U,1)
#define ITC_8UC2 ITC_MAKETYPE(ITC_8U,2)
#define ITC_8UC3 ITC_MAKETYPE(ITC_8U,3)
#define ITC_8UC4 ITC_MAKETYPE(ITC_8U,4)
#define ITC_8UC(n) ITC_MAKETYPE(ITC_8U,(n))

#define ITC_8SC1 ITC_MAKETYPE(ITC_8S,1)
#define ITC_8SC2 ITC_MAKETYPE(ITC_8S,2)
#define ITC_8SC3 ITC_MAKETYPE(ITC_8S,3)
#define ITC_8SC4 ITC_MAKETYPE(ITC_8S,4)
#define ITC_8SC(n) ITC_MAKETYPE(ITC_8S,(n))

#define ITC_16UC1 ITC_MAKETYPE(ITC_16U,1)
#define ITC_16UC2 ITC_MAKETYPE(ITC_16U,2)
#define ITC_16UC3 ITC_MAKETYPE(ITC_16U,3)
#define ITC_16UC4 ITC_MAKETYPE(ITC_16U,4)
#define ITC_16UC(n) ITC_MAKETYPE(ITC_16U,(n))

#define ITC_16SC1 ITC_MAKETYPE(ITC_16S,1)
#define ITC_16SC2 ITC_MAKETYPE(ITC_16S,2)
#define ITC_16SC3 ITC_MAKETYPE(ITC_16S,3)
#define ITC_16SC4 ITC_MAKETYPE(ITC_16S,4)
#define ITC_16SC(n) ITC_MAKETYPE(ITC_16S,(n))

#define ITC_32SC1 ITC_MAKETYPE(ITC_32S,1)
#define ITC_32SC2 ITC_MAKETYPE(ITC_32S,2)
#define ITC_32SC3 ITC_MAKETYPE(ITC_32S,3)
#define ITC_32SC4 ITC_MAKETYPE(ITC_32S,4)
#define ITC_32SC(n) ITC_MAKETYPE(ITC_32S,(n))

#define ITC_32FC1 ITC_MAKETYPE(ITC_32F,1)
#define ITC_32FC2 ITC_MAKETYPE(ITC_32F,2)
#define ITC_32FC3 ITC_MAKETYPE(ITC_32F,3)
#define ITC_32FC4 ITC_MAKETYPE(ITC_32F,4)
#define ITC_32FC(n) ITC_MAKETYPE(ITC_32F,(n))

#define ITC_64FC1 ITC_MAKETYPE(ITC_64F,1)
#define ITC_64FC2 ITC_MAKETYPE(ITC_64F,2)
#define ITC_64FC3 ITC_MAKETYPE(ITC_64F,3)
#define ITC_64FC4 ITC_MAKETYPE(ITC_64F,4)
#define ITC_64FC(n) ITC_MAKETYPE(ITC_64F,(n))

//#define ITC_AUTO_STEP  0x7fffffff
//#define ITC_WHOLE_ARR  ITCSlice( 0, 0x3fffffff )

#define ITC_MAT_CN_MASK          ((ITC_CN_MAX - 1) << ITC_CN_SHIFT)							//通道掩码
#define ITC_MAT_CN(flags)        ((((flags) & ITC_MAT_CN_MASK) >> ITC_CN_SHIFT) + 1)		//获得通道数（第4到12位）
#define ITC_MAT_TYPE_MASK        (ITC_DEPTH_MAX*ITC_CN_MAX - 1)
#define ITC_MAT_TYPE(flags)      ((flags) & ITC_MAT_TYPE_MASK)								//获得数据类型和通道
#define ITC_MAT_CONT_FLAG_SHIFT  14
#define ITC_MAT_CONT_FLAG        (1 << ITC_MAT_CONT_FLAG_SHIFT)								//第15位
#define ITC_IS_MAT_CONT(flags)   ((flags) & ITC_MAT_CONT_FLAG)
#define ITC_IS_CONT_MAT          ITC_IS_MAT_CONT
//#define ITC_SUBMAT_FLAG_SHIFT    15
//#define ITC_SUBMAT_FLAG          (1 << ITC_SUBMAT_FLAG_SHIFT)								//第16位,未明白含义，也未使用
//#define ITC_IS_SUBMAT(flags)     ((flags) & ITC_MAT_SUBMAT_FLAG)

#define ITC_MAGIC_MASK       0xFFFF0000		//用于判断是否是Mat结构
#define ITC_MAT_MAGIC_VAL    0x42420000

#define INT_MAX         2147483647			//32位整型能表示的最大数值
//#define NULL	0

#define ITC_AUTOSTEP  0x7fffffff

#define ITC_IS_MAT_HDR(mat) \
	((mat) != NULL && \
	(((const Itc_Mat_t*)(mat))->type & CV_MAGIC_MASK) == ITC_MAT_MAGIC_VAL && \
	((const Itc_Mat_t*)(mat))->cols > 0 && ((const Itc_Mat_t*)(mat))->rows > 0)		//判断是否是Mat

#define ITC_IS_MAT(mat) \
	(ITC_IS_MAT_HDR(mat) && ((const Itc_Mat_t*)(mat))->data.ptr != NULL)			//判断是否有数据

#define ITC_IS_MASK_ARR(mat) \
	(((mat)->type & (ITC_MAT_TYPE_MASK & ~ITC_8SC1)) == 0)

#define ITC_ARE_TYPES_EQ(mat1, mat2) \
	((((mat1)->type ^ (mat2)->type) & ITC_MAT_TYPE_MASK) == 0)					//判断mat1和mat2类型（通道数和深度）是否相同

#define ITC_ARE_CNS_EQ(mat1, mat2) \
	((((mat1)->type ^ (mat2)->type) & ITC_MAT_CN_MASK) == 0)					//判断mat1和mat2通道数是否相等

#define ITC_ARE_DEPTHS_EQ(mat1, mat2) \
	((((mat1)->type ^ (mat2)->type) & ITC_MAT_DEPTH_MASK) == 0)					//判断mat1和mat2深度是否相等

#define ITC_ARE_SIZES_EQ(mat1, mat2) \
	((mat1)->height == (mat2)->height && (mat1)->width == (mat2)->width)		//判断mat1和mat2尺寸是否相等

#define ITC_IS_MAT_CONST(mat)  \
	(((mat)->height | (mat)->width) == 1)

#define ITC_ELEM_SIZE(type) \
	(ITC_MAT_CN(type) << ((((sizeof(size_t) / 4 + 1) * 0x4000 | 0x3a50) >> ITC_MAT_DEPTH(type) * 2) & 3))	//每一个元素有n个通道，每个通道占s个字节，那么一个元素的大小就为n*s,其中s的取值为1，2，4，8，用位操作《取代*则为0，1，2，3
//0x3a50中，每两个位对应一个深度的s,最高两位对应ITC_USRTYPE1，size_t只对最高两位产生影响（因为0x4000）
/* general-purpose saturation macros */
#define  ITC_CAST_8U(t)  (uchar)(!((t) & ~255) ? (t) : (t) > 0 ? 255 : 0)						//((t) & ~255)不为0说明已经越界
#define  ITC_CAST_8S(t)  (char)(!(((t)+128) & ~255) ? (t) : (t) > 0 ? 127 : -128)
#define  ITC_CAST_16U(t) (ushort)(!((t) & ~65535) ? (t) : (t) > 0 ? 65535 : 0)
#define  ITC_CAST_16S(t) (short)(!(((t)+32768) & ~65535) ? (t) : (t) > 0 ? 32767 : -32768)
#define  ITC_CAST_32S(t) (int)(t)
#define  ITC_CAST_64S(t) (int64)(t)
#define  ITC_CAST_32F(t) (float)(t)
#define  ITC_CAST_64F(t) (double)(t)

/****************************************************************************************\
*                             Common macros and inline functions                         *
\****************************************************************************************/

#define itcFree(ptr) (itcFree_(*(ptr)), *(ptr)=0)

/* maximum size of dynamic memory buffer.
cvAlloc reports an error if a larger block is requested. */
#define  ITC_MAX_ALLOC_SIZE    (((size_t)1 << (sizeof(size_t)*8-2)))  //判断是否越界
/* the alignment of all the allocated buffers */
#define  ITC_MALLOC_ALIGN    32
// pointers to allocation functions, initially set to default
static void* p_cvAllocUserData = 0;
/* default storage block size */
#define  ITC_STORAGE_BLOCK_SIZE   ((1<<16) - 128)
/* default alignment for dynamic data strucutures, resided in storages. */
#define  ITC_STRUCT_ALIGN    ((int)sizeof(double))

#define ITC_GET_LAST_ELEM( seq, block ) \
	((block)->data + ((block)->count - 1)*((seq)->elem_size))

#define ITC_FREE_PTR(storage)  \
	((char*)(storage)->top + (storage)->block_size - (storage)->free_space)
/* 0x3a50 = 11 10 10 01 01 00 00 ~ array of log2(sizeof(arr_type_elem)) */
//#define ITC_ELEM_SIZE(type) 
//	(ITC_MAT_CN(type) << ((((sizeof(size_t) / 4 + 1) * 16384 | 0x3a50) >> ITC_MAT_DEPTH(type) * 2) & 3))
#define ITC_SHIFT_TAB_MAX 32
static const char itcPower2ShiftTab[] =
{
	0, 1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, 4,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5
};

#define ITC_MEMCPY_AUTO( dst, src, len )                                             \
{                                                                                   \
	size_t _icv_memcpy_i_, _icv_memcpy_len_ = (len);                                \
	char* _icv_memcpy_dst_ = (char*)(dst);                                          \
	const char* _icv_memcpy_src_ = (const char*)(src);                              \
if ((_icv_memcpy_len_ & (sizeof(int)-1)) == 0)                                 \
{                                                                               \
	assert(((size_t)_icv_memcpy_src_&(sizeof(int)-1)) == 0 && \
	((size_t)_icv_memcpy_dst_&(sizeof(int)-1)) == 0);                  \
for (_icv_memcpy_i_ = 0; _icv_memcpy_i_ < _icv_memcpy_len_;                 \
	_icv_memcpy_i_ += sizeof(int))                                           \
{                                                                           \
	*(int*)(_icv_memcpy_dst_ + _icv_memcpy_i_) = \
	*(const int*)(_icv_memcpy_src_ + _icv_memcpy_i_);                         \
	}                                                                           \
	}                                                                               \
	else                                                                            \
{                                                                               \
for (_icv_memcpy_i_ = 0; _icv_memcpy_i_ < _icv_memcpy_len_; _icv_memcpy_i_++)\
	_icv_memcpy_dst_[_icv_memcpy_i_] = _icv_memcpy_src_[_icv_memcpy_i_];    \
	}                                                                               \
}

#define  ITC_TOGGLE_FLT(x) ((x)^((int)(x) < 0 ? 0x7fffffff : 0))

#endif // itctype_h_